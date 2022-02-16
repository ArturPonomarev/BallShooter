#pragma once
#include "GameObject.h"

#include <iostream>


class BulletObject :
    public GameObject
{
public:
   
    BulletObject(std::shared_ptr<Content>& content);
    virtual ~BulletObject() {};

    // Унаследовано через GameObject
    virtual void Render() override;
    virtual void Update(float deltaTime) override;
    virtual void ProcessInput() override;
    virtual void Collide(std::shared_ptr<GameObject>& otherObj) override;

    //---------Сеттеры Геттеры---------------------------
    std::shared_ptr<GameObject> GetOwner() { return m_owner; }
    void SetOwner(std::shared_ptr<GameObject> newOwner) { m_owner = newOwner; }

    float GetDamage() { return m_damage; }
    void SetDamage(float newDamage) { m_damage = newDamage; }
    //---------------------------------------------------


protected:
    std::shared_ptr<GameObject> m_owner;

    float m_damage;
};

