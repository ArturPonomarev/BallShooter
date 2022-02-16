#include "BulletObject.h"

#include "Game.h"

#include "GameConstants.h"


BulletObject::BulletObject(std::shared_ptr<Content>& content) : GameObject(content)
{
	m_type = ObjectTypes::BULLET_TYPE;

	m_speed = BULLET_SPEED;
	m_isVulnerable = true;
	m_isCollidable = true;
	
	//-----Форма пули-----//
	m_shape.setRadius(BULLET_RADIUS);
	m_shape.setFillColor(BULLET_COLOR);
	m_shape.setOutlineThickness(2);
	m_shape.setOutlineColor(sf::Color::Black);
	//--------------------//

	m_damage = BULLET_DAMAGE;
}


void BulletObject::Render()
{
	GameObject::Render();
}

void BulletObject::Update(float deltaTime)
{
	GameObject::Update(deltaTime);
}

void BulletObject::ProcessInput()
{
}

void BulletObject::Collide(std::shared_ptr<GameObject>& otherObj)
{
	if (otherObj->GetAlliance() != m_alliance)
	{
		otherObj->GetDamage(m_damage);
		m_damage = 0;
		m_delete = true;
	}
}
