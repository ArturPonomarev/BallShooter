#pragma once
#include "GameState.h"

#include "PlayerObject.h"
#include "BulletObject.h"

class PlayState :
    public GameState
{
public:
    PlayState(std::shared_ptr<Content>& content);
    ~PlayState();

    // Унаследовано через GameState
    virtual void Init() override;
    virtual void Leave() override;
    virtual void Pause() override;
    virtual void Resume() override;
    virtual void Render() override;
    virtual void Update(float deltaTime) override;
    virtual void HandleEvent() override;


    GameObject* CreateObject(ObjectTypes type);
private:

    std::shared_ptr<Content> m_content;

    PlayerObject* m_player;

    std::vector<GameObject*> m_objects;

    sf::Sprite m_mark;
};

