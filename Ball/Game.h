#pragma once

#include <SFML/Graphics.hpp>

#include "StateManager.h"
#include "AssetManager.h"

#include <memory>
#include <iostream>

struct Content
{
	std::unique_ptr<StateManager> stateMan;
	std::unique_ptr<AssetManager> assetMan;
	std::unique_ptr<sf::RenderWindow> renderWindow;

	Content()
	{
		stateMan = std::make_unique<StateManager>();
		assetMan = std::make_unique<AssetManager>();
		renderWindow = std::make_unique <sf::RenderWindow>();
	}
};

class Game
{
public:

	Game();
	~Game();

	void Init();
	void Leave();

	void GameLoop();

private:
	sf::Clock m_clock;

	std::shared_ptr<Content> m_content;

	bool m_isGameActive;
};
