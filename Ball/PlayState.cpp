#include "PlayState.h"
#include "GameMath.h"
#include "Game.h"

#include "Assets.h"

#include <cassert>

#include <algorithm>

PlayState::PlayState(std::shared_ptr<Content>& content)
{
	m_content = content;
}

PlayState::~PlayState()
{
}

void PlayState::Init()
{
	//Создание игрока
	this->CreateObject(ObjectTypes::PLAYER_TYPE);
	m_player.lock()->SetPosition(sf::Vector2f(m_content->renderWindow->getSize().x / 2, m_content->renderWindow->getSize().y / 2));
	//----------------
	
	//Создание камеры
	m_view.reset(sf::FloatRect(0.f, 0.f, m_content->renderWindow->getSize().x, m_content->renderWindow->getSize().y));

	//Создание прицела
	m_content->assetMan->AddTexture(Textures::MARK_TEXTURE, "Textures/mark.png");
	m_mark.setTexture(m_content->assetMan->GetTexture(Textures::MARK_TEXTURE));
	m_mark.setOrigin(m_mark.getPosition().x + m_mark.getLocalBounds().width / 2, m_mark.getPosition().y + m_mark.getLocalBounds().height / 2);
	//----------------

	//Скрытие стандартного курсора
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
	m_content->renderWindow->setView(m_view);
	m_content->renderWindow->clear(sf::Color::White);

	for (auto& obj : m_objects)
		obj->Render();

	m_content->renderWindow->draw(m_mark);

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
	{
		obj->Update(deltaTime);



		//-----Удаление пуль которые за пределами экрана-----//
		if (obj->GetType() == ObjectTypes::BULLET_TYPE)
		{
			sf::Vector2f pos = obj->GetPosition();

			sf::FloatRect currentView;
			currentView.top = m_view.getCenter().x - m_view.getSize().x / 2;
			currentView.left = m_view.getCenter().y - m_view.getSize().y / 2;
			currentView.width = m_view.getSize().x;
			currentView.height = m_view.getSize().y;

			if (!currentView.contains(obj->GetPosition()))
				obj->SetDelete(true);
		}
		//---------------------------------------------------//
	}
	//----------------------------------//
	

	//-----Игрок стреляет-----//
	if (m_player.lock().get()!=nullptr)
	{
		if (m_player.lock()->GetShot())
		{

			m_player.lock()->SetShot(false);

			auto tempBullet = std::dynamic_pointer_cast<BulletObject>(CreateObject(ObjectTypes::BULLET_TYPE));
			tempBullet->SetOwner(m_player.lock());
			tempBullet->SetPosition(m_player.lock()->CalculateShootPosition());
			
			tempBullet->SetDirection(NormalizeVector(cursorPos - m_player.lock()->GetCannonPosition()));
		}
	}
	//------------------------//

	this->DeleteObjects();
}

void PlayState::HandleEvent()
{
	sf::Event ev;

	m_player.lock()->ProcessInput();

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

std::shared_ptr<GameObject>& PlayState::CreateObject(ObjectTypes type)
{	
	bool isPlayer = false;

	m_bufObject.reset();

	switch (type)
	{
	case NONE_TYPE:
		break;
	case PLAYER_TYPE:
		
		isPlayer = true;
		m_bufObject = std::make_shared<PlayerObject>(m_content);
		
		break;
	case BULLET_TYPE:
		
		m_bufObject = std::make_shared<BulletObject>(m_content);

		break;
	default:
		break;
	}

	assert(m_bufObject.get() != nullptr && "object cannot be created");

	if (isPlayer)
	{
		m_player = std::dynamic_pointer_cast<PlayerObject>(m_bufObject);
	}

	m_objects.push_back(std::move(m_bufObject));

	return m_objects.back();
}

void PlayState::DeleteObjects()
{
	auto result = std::remove_if(m_objects.begin(), m_objects.end(), [](std::shared_ptr<GameObject>& obj) {
		return (obj->GetDelete() == true); 
		});

	m_objects.erase(result, m_objects.end());
}
