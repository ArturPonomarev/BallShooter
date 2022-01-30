#pragma once
#include "Creator.h"

#include "PlayerObject.h"

class PlayerCreator :
    public Creator
{
public:
    PlayerCreator() {};
    ~PlayerCreator() {};
    // Унаследовано через Creator
    virtual std::shared_ptr<GameObject> CreateObject(std::shared_ptr<Content>& content, sf::Vector2f pos, sf::Vector2f dir, Alliance ally) override;
};

