#pragma once
#include "GameObject.h"


class BulletObject :
    public GameObject
{
public:
   
    BulletObject(std::shared_ptr<Content>& content);
    virtual ~BulletObject() {};

    // ������������ ����� GameObject
    virtual void Init() override;
    virtual void Render() override;
    virtual void Update(float deltaTime) override;
    virtual void ProcessInput() override;
    virtual void Collide(GameObject& otherObj) override;

    //---------������� �������---------------------------
    GameObject* GetOwner() { return m_owner; }
    void SetOwner(GameObject* newOwner) { m_owner = newOwner; }

    float GetDamage() { return m_damage; }
    void SetDamage(float newDamage) { m_damage = newDamage; }
    //---------------------------------------------------


protected:
    GameObject* m_owner;

    float m_damage;
};

