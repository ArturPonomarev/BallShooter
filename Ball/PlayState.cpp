#include "PlayState.h"
#include "GameMath.h"
#include "Game.h"

#include "Assets.h"

#include <cassert>

PlayState::PlayState(std::shared_ptr<Content>& content)
{
	m_content = content;
}

PlayState::~PlayState()
{
}

void PlayState::Init()
{
	this->CreateObject(ObjectTypes::PLAYER_TYPE);

	m_content->assetMan->AddTexture(Textures::MARK_TEXTURE, "Textures/mark.png");
	m_mark.setTexture(m_content->assetMan->GetTexture(Textures::MARK_TEXTURE));
	m_mark.setOrigin(m_mark.getPosition().x + m_mark.getLocalBounds().width / 2, m_mark.getPosition().y + m_mark.getLocalBounds().height / 2);
	

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

	m_content->renderWindow->draw(m_mark);

	for (auto& obj : m_objects)
		obj->Render();

	m_content->renderWindow->display();
}

void PlayState::Update(float deltaTime)
{
	//----Спрайтовый курсор заменяет обычный-----//
	sf::Vector2f cursorPos = m_content->renderWindow->mapPixelToCoords(sf::Mouse::getPosition(*(m_content->renderWindow.get())));
	m_mark.setPosition(cursorPos);
	//-------------------------------------------//

	//-----Обновление всех объектов-----//
	for (auto& obj : m_objects)
		obj->Update(deltaTime);
	
	//----------------------------------//
	

	//-----Игрок стреляет-----//
	if (m_player!=nullptr)
	{
		if (m_player->GetShot())
		{
			std::cout << "shoot"<<'\n';

			m_player->SetShot(false);

			BulletObject* bullet = (BulletObject*)CreateObject(ObjectTypes::BULLET_TYPE);
			bullet->SetOwner(m_player);
			bullet->SetPosition(m_player->CalculateShootPosition());
			
			
			bullet->SetDirection(NormalizeVector(cursorPos - bullet->GetPosition()));
		}
	}

	//------------------------//


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

GameObject* PlayState::CreateObject(ObjectTypes type)
{	
	GameObject* retObj = nullptr;

	switch (type)
	{
	case NONE_TYPE:
		break;
	case PLAYER_TYPE:
		
		retObj = new PlayerObject(m_content);
		
		m_player = (PlayerObject*)retObj;
		m_player->SetPosition(sf::Vector2f(500.f,500.f));
		
		break;
	case BULLET_TYPE:
		
		retObj = new BulletObject(m_content);

		break;
	default:
		break;
	}

	assert(retObj != nullptr);

	m_objects.push_back(retObj);

	return m_objects.back();
}
