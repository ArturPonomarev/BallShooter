#include "PlayerObject.h"

#include <iostream>

#include "GameMath.h"

#include "Game.h"
#include "Assets.h"

PlayerObject::PlayerObject(std::shared_ptr<Content>& content) : GameObject(content)
{
	m_cannon.setTexture(m_content->assetMan->GetTexture(Textures::CANNON_TEXTURE));
	m_cannon.setOrigin(15.f, 65.f);

	m_type = ObjectTypes::PLAYER_TYPE;

	//Тест
	m_projectile.setRadius(10.f);
	m_projectile.setOutlineThickness(3);
	m_projectile.setFillColor(sf::Color::Green);
	m_projectile.setOutlineColor(sf::Color::Black);
	m_projectile.setOrigin(10.f, 10.f);
	m_projectile.setPosition(100.f, 100.f);
}


void PlayerObject::Update(float deltaTime)
{
	float dx = deltaTime * m_direction.x * m_speed;
	float dy = deltaTime * m_direction.y * m_speed;

	m_shape->setPosition(m_shape->getPosition() + sf::Vector2f(dx,dy));
	
	m_cannon.setPosition(m_shape->getPosition());
	
	sf::Vector2f cursorPos = m_content->renderWindow->mapPixelToCoords(sf::Mouse::getPosition(*(m_content->renderWindow.get())));
	m_cannon.setRotation(GetCursorAngle(m_cannon.getPosition(), cursorPos) + 90.f);
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
		m_projectile.setPosition(this->CalculateShootPosition());
	}
}

void PlayerObject::Collide(GameObject& otherObj)
{
}

void PlayerObject::Render()
{
	m_content->renderWindow->draw(m_cannon);
	m_content->renderWindow->draw(*m_shape.get());
	

	//Тест
	m_content->renderWindow->draw(m_projectile);
}

sf::Vector2f PlayerObject::CalculateShootPosition()
{
	float radius = 50.f;
	sf::Vector2f cursorPos = m_content->renderWindow->mapPixelToCoords(sf::Mouse::getPosition(*(m_content->renderWindow.get())));
	
	sf::Vector2f normVec = NormalizeVector(cursorPos - m_shape->getPosition());

	return m_shape->getPosition() + sf::Vector2f(normVec.x * radius, normVec.y * radius);
}