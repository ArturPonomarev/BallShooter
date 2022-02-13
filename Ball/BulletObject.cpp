#include "BulletObject.h"

#include "Game.h"



BulletObject::BulletObject(std::shared_ptr<Content>& content) : GameObject(content)
{
	m_type = ObjectTypes::BULLET_TYPE;

	m_speed = 400.f;
	m_isVulnerable = true;
	m_isCollidable = true;
	
	//-----Пуля-----//
	m_shape.setRadius(5);
	m_shape.setOrigin(m_shape.getRadius(), m_shape.getRadius());

	m_shape.setFillColor(sf::Color::Green);
	m_shape.setOutlineThickness(2);
	m_shape.setOutlineColor(sf::Color::Black);

	//--------------//

	m_damage = 1.f;
}

void BulletObject::Init()
{
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

void BulletObject::Collide(GameObject& otherObj)
{
	otherObj.GetDamage(m_damage);

	m_delete = true;
}
