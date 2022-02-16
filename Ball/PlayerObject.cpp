#include "PlayerObject.h"

#include <iostream>

#include "GameMath.h"

#include "Game.h"
#include "Assets.h"
#include "GameState.h"

#include "GameConstants.h"

PlayerObject::PlayerObject(std::shared_ptr<Content>& content) : GameObject(content)
{
	m_type = ObjectTypes::PLAYER_TYPE;
	m_alliance = Alliance::ALLY_ALLIANCE;

	//-----Боевка-----//
	m_maxHp = PLAYER_MAX_HEALTH;
	m_currentHp = m_maxHp;
	
	m_maxReloadTime = PLAYER_RELOAD_TIME;
	m_reloadTime = m_maxReloadTime;

	m_isShot = false;
	//----------------//

	m_speed = PLAYER_SPEED;
	

	m_shape.setRadius(PLAYER_RADIUS);
	m_shape.setOutlineThickness(5);
	m_shape.setOutlineColor(sf::Color::Black);
	m_shape.setFillColor(PLAYER_COLOR);

	//-------Пушка-------//
	m_content->assetMan->AddTexture(Textures::CANNON_TEXTURE, "Textures/cannon.png");
	m_cannon.setTexture(m_content->assetMan->GetTexture(Textures::CANNON_TEXTURE));
	m_cannon.setOrigin(15.f, 65.f);
	//-------------------//
}


void PlayerObject::Update(float deltaTime)
{
	GameObject::Update(deltaTime);

	//-------Перезарядка-------//
	if (m_reloadTime > 0.f)
	{
		m_reloadTime -= deltaTime;
	}
	//-------------------------//

	//-------Пушка-------//
	m_cannon.setPosition(m_shape.getPosition());
	
	sf::Vector2f cursorPos = m_content->renderWindow->mapPixelToCoords(sf::Mouse::getPosition(*(m_content->renderWindow.get())));
	m_cannon.setRotation(GetCursorAngle(m_cannon.getPosition(), cursorPos) + 90.f);
	//-------------------//
}

void PlayerObject::ProcessInput()
{
	m_direction = { 0.f,0.f };

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		m_direction.y = -1.f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		m_direction.y = 1.f;

	if ( (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) && (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) )
		m_direction.y = 0.f;


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		m_direction.x = -1.f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		m_direction.x = 1.f;

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) && (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)))
		m_direction.x = 0.f;


	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		if (m_reloadTime <= 0.f)
		{
			m_isShot = true;
			m_reloadTime = m_maxReloadTime;
		}
	}
}

void PlayerObject::Collide(std::shared_ptr<GameObject>& otherObj)
{
}

void PlayerObject::Render()
{
	m_content->renderWindow->draw(m_cannon);

	GameObject::Render();
}

sf::Vector2f PlayerObject::CalculateShootPosition()
{
	float radius = 50.f;
	sf::Vector2f cursorPos = m_content->renderWindow->mapPixelToCoords(sf::Mouse::getPosition(*(m_content->renderWindow.get())));
	
	sf::Vector2f normVec = NormalizeVector(cursorPos - m_shape.getPosition());

	return m_shape.getPosition() + sf::Vector2f(normVec.x * radius, normVec.y * radius);
}