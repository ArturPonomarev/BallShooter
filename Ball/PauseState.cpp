#include "PauseState.h"
#include "Game.h"
#include "Assets.h"

PauseState::PauseState(std::shared_ptr<Content>& content)
{
	m_content = content;
}

void PauseState::Init()
{
	//Надпись "Pause"----------------
	m_pauseLabel.setFont(m_content->assetMan->GetFont(Fonts::MAIN_FONT));
	m_pauseLabel.setCharacterSize(25);
	m_pauseLabel.setString("Pause");
	m_pauseLabel.setFillColor(sf::Color::Black);

	m_pauseLabel.setPosition( (m_content->renderWindow->getSize().x/2) - 50,
								100.f);

	//Рамка надписи------------------
	m_pauseLabelFrame.setFillColor(sf::Color::Red);
	m_pauseLabelFrame.setOutlineThickness(3);
	m_pauseLabelFrame.setOutlineColor(sf::Color::Black);
	m_pauseLabelFrame.setSize(sf::Vector2f(90.f,35.f));
	m_pauseLabelFrame.setPosition(m_pauseLabel.getPosition() + sf::Vector2f(-5.f,0.f));
}

void PauseState::Leave()
{
}

void PauseState::Pause()
{
}

void PauseState::Resume()
{
}

void PauseState::Render()
{
	m_content->renderWindow->draw(m_pauseLabelFrame);
	m_content->renderWindow->draw(m_pauseLabel);

	m_content->renderWindow->display();
}

void PauseState::Update(float deltaTime)
{
}

void PauseState::HandleEvent()
{
	sf::Event ev;

	while (m_content->renderWindow->pollEvent(ev))
	{
		switch (ev.type)
		{
		case sf::Event::Closed:
			m_content->renderWindow->close();
			break;
		case sf::Event::KeyPressed:
			if (ev.key.code == sf::Keyboard::Key::Escape)
				m_content->stateMan->PopCurrent();
		default:
			break;
		}
	}
}
