#include "PlayState.h"

#include "Game.h"

#include "Assets.h"

PlayState::PlayState(std::shared_ptr<Content>& content)
{
	m_content = content;
}

PlayState::~PlayState()
{
}

void PlayState::Init()
{
	m_content->assetMan->AddTexture(Textures::MARK_TEXTURE, "Textures/mark.png");
	m_mark.setTexture(m_content->assetMan->GetTexture(Textures::MARK_TEXTURE));
	m_mark.setOrigin(m_mark.getPosition().x + m_mark.getLocalBounds().width / 2, m_mark.getPosition().y + m_mark.getLocalBounds().height / 2);

	m_content->assetMan->AddTexture(Textures::CANNON_TEXTURE, "Textures/cannon.png");
	

	m_player = std::dynamic_pointer_cast<PlayerObject>(m_playerCreator.CreateObject(m_content,Alliance::ALLY_ALLIANCE,sf::Vector2f(350.f,350.f)));


	m_content->renderWindow->setMouseCursorVisible(false);
}

void PlayState::Leave()
{
	m_content->renderWindow->setMouseCursorVisible(true);
}

void PlayState::Pause()
{
}

void PlayState::Resume()
{
}

void PlayState::Render()
{
	m_content->renderWindow->clear(sf::Color::White);

	m_player->Render();
	m_content->renderWindow->draw(m_mark);

	m_content->renderWindow->display();
}

void PlayState::Update(float deltaTime)
{
	sf::Vector2f cursorPos = m_content->renderWindow->mapPixelToCoords(sf::Mouse::getPosition(*(m_content->renderWindow.get())));
	m_mark.setPosition(cursorPos);

	m_player->Update(deltaTime);
}

void PlayState::HandleEvent()
{
	sf::Event ev;

	m_player->ProcessInput();

	while (m_content->renderWindow->pollEvent(ev))
	{
		switch (ev.type)
		{
		case sf::Event::Closed:
			m_content->renderWindow->close();
			break;
		default:
			break;
		}
	}
}
