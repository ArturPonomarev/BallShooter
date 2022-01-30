#pragma once
#include "GameObject.h"
class PlayerObject :
    public GameObject
{
public:
    PlayerObject(std::shared_ptr<Content>& content);
    virtual ~PlayerObject() {};

    // ������������ ����� GameObject
    virtual void Update(float deltaTime) override;
    virtual void ProcessInput() override;
    virtual void Collide(GameObject& otherObj) override;
    virtual void Render() override;

    sf::Vector2f CalculateShootPosition();

private:
    sf::Sprite m_cannon;

    //����
    sf::CircleShape m_projectile;
};

