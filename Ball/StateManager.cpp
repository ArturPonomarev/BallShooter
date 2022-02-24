#include "StateManager.h"

StateManager::StateManager()
{

}

StateManager::~StateManager()
{

}

void StateManager::Init()
{
	while (!m_states.empty())
		m_states.pop();

	m_newState.reset();

	m_add = false;
	m_remove = false;
	m_replace = false;
}

void StateManager::Add(std::unique_ptr<GameState> newState, bool isReplace)
{
	m_add = true;
	m_newState = std::move(newState);
	m_replace = isReplace;
}

void StateManager::PopCurrent()
{
	m_remove = true;
}

void StateManager::ProcessStateChange()
{
	//Удаление верхнего состояния
	if (m_remove && !m_states.empty())
	{
		m_states.top()->Leave();
		m_states.pop();

		if (!m_states.empty())
		{
			m_states.top()->Resume();
		}

		m_remove = false;
	}

	if (m_add)
	{
		if (m_replace)
		{
			if (!m_states.empty())
			{
				m_states.top()->Leave();
				m_states.pop();
			}

			m_replace = false;
		}

		if (!m_states.empty())
			m_states.top()->Pause();

		m_states.push(std::move(m_newState));
		m_states.top()->Init();

		m_add = false;
	}
}

std::unique_ptr<GameState>& StateManager::GetCurrentState()
{
	return m_states.top();
}