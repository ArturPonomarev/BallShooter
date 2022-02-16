#pragma once
#include "GameObject.h"
#include "PlayerObject.h"

class EnemyObject :
    public GameObject
{
public:
    EnemyObject(std::shared_ptr<Content>& content);
    virtual ~EnemyObject();

    // Унаследовано через GameObject
    virtual void Update(float deltaTime) override;
    
    virtual void ProcessInput() override;
    virtual void Collide(std::shared_ptr<GameObject>& otherObj) override;

    //---------Сеттеры Геттеры---------------------------
    void SetPlayer(std::shared_ptr<PlayerObject> player) { m_player = player; }

    //---------------------------------------------------
protected:
    std::shared_ptr<PlayerObject> m_player;

    float m_damage;

    float m_attackCooldownTime;
    float m_attackCooldownTimer;
    
};

