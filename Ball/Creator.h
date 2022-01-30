#pragma once

#include <memory>

#include "GameObject.h"
#include "Assets.h"

struct Content;

class Creator
{
public: 
	Creator() {};
	virtual ~Creator() {};

	virtual std::shared_ptr<GameObject> CreateObject(std::shared_ptr<Content>& content, sf::Vector2f pos, sf::Vector2f dir, Alliance ally) = 0;
};

