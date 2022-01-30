#pragma once

#include <memory>
#include <stack>

#include "GameState.h"

class StateManager
{
public:

	StateManager();
	~StateManager();

	void Init();

	void Add(std::unique_ptr<GameState> newState, bool isReplace = false);
	void PopCurrent();
	void ProcessStateChange();

	std::unique_ptr<GameState>& GetCurrentState();

	//Работа с состояниями
	std::stack<std::unique_ptr<GameState>> m_states;
	std::unique_ptr<GameState> m_newState;

private:
	bool m_add;
	bool m_replace;
	bool m_remove;
};

