#include "Game.h"

#include <iostream>

#include "MainMenuState.h"
#include <cstdlib>
#include <ctime>

Game::Game()
{
}

Game::~Game()
{
}

void Game::Init()
{
	srand(time(0));

	m_content = std::make_shared<Content>();

	m_content->renderWindow->create(sf::VideoMode(1280, 920), "Game", sf::Style::Default);
	m_clock.restart();

	m_content->stateMan->Add(std::make_unique<MainMenuState>(m_content));
	m_isGameActive = true;
}

void Game::Leave()
{
}

void Game::GameLoop()
{
	while (m_content->renderWindow->isOpen())
	{
		m_content->stateMan->ProcessStateChange();
		m_content->stateMan->GetCurrentState()->HandleEvent();
		m_content->stateMan->GetCurrentState()->Render();
		m_content->stateMan->GetCurrentState()->Update(m_clock.getElapsedTime().asSeconds());
	
		m_clock.restart();
	}
}