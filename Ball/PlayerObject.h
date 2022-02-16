#pragma once
#include "GameObject.h"
#include "BulletObject.h"

class PlayerObject :
    public GameObject
{
public:
    PlayerObject(std::shared_ptr<Content>& content);
    virtual ~PlayerObject() {};

    // Унаследовано через GameObject
    virtual void Update(float deltaTime) override;
    virtual void ProcessInput() override;
    virtual void Collide(std::shared_ptr<GameObject>& otherObj) override;
    virtual void Render() override;

    sf::Vector2f CalculateShootPosition();


    //---------Сеттеры Геттеры---------------------------
    float GetReloadTime() { return m_reloadTime; }
    void SetReloadTime(float newReloadTime) { m_reloadTime = newReloadTime; }

    float GetMaxReloadTime() { return m_maxReloadTime; }
    void SetMaxReloadTime(float newMaxReloadTime) { m_maxReloadTime = newMaxReloadTime; }

    bool GetShot() { return m_isShot; }
    void SetShot(bool newIsShot) { m_isShot = newIsShot; }

    sf::Vector2f GetCannonPosition() { return m_cannon.getPosition(); }
    //---------------------------------------------------

private:
    sf::Sprite m_cannon;

    //Стрельба
    float m_reloadTime;
    float m_maxReloadTime;
    bool m_isShot; 
};

