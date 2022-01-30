#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

struct Content;

class GameState
{
public:
	GameState() {};
	virtual ~GameState() {};

	virtual void Init() = 0;
	virtual void Leave() = 0;

	virtual void Pause() = 0;
	virtual void Resume() = 0;

	virtual void Render() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void HandleEvent() = 0;
};

