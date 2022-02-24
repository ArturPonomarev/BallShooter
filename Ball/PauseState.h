#pragma once
#include "GameState.h"
class PauseState :
    public GameState
{
public:
    PauseState(std::shared_ptr<Content>& content);
    ~PauseState() {};

    // Унаследовано через GameState
    virtual void Init() override;
    virtual void Leave() override;
    virtual void Pause() override;
    virtual void Resume() override;
    virtual void Render() override;
    virtual void Update(float deltaTime) override;
    virtual void HandleEvent() override;

private:
    std::shared_ptr<Content> m_content;

    sf::Text m_pauseLabel;
    sf::RectangleShape m_pauseLabelFrame;
};

