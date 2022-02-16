#pragma once
#include "GameObject.h"
class EnemyObject :
    public GameObject
{
public:
    EnemyObject();
    virtual ~EnemyObject();

    // Унаследовано через GameObject
    virtual void Update(float deltaTime) override;
    
    virtual void Init() override;
    virtual void ProcessInput() override;
    virtual void Collide(std::shared_ptr<GameObject>& otherObj) override;
};

