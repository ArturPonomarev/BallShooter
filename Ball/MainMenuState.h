#pragma once
#include "GameState.h"

class MainMenuState :
    public GameState
{
public:
    MainMenuState(std::shared_ptr<Content>& content);
    ~MainMenuState();

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

    sf::Text m_titleLabel;
    sf::RectangleShape m_startButtonFrame;
    sf::Text m_startTextLabel;
    sf::RectangleShape m_exitButtonFrame;
    sf::Text m_exitTextLabel;

    bool m_isStartButtonPressed;
    bool m_isExitButtonPressed;

    bool m_isStartButtonSelected;
    bool m_isExitButtonSelected;

};

