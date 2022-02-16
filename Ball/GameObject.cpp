#include "GameObject.h"

#include "Game.h"

GameObject::GameObject(std::shared_ptr<Content>& content)
{
	m_direction = { 0.f,0.f };
	m_position = { 0.f, 0.f };
	m_speed = 0.f;

	m_isCollidable = true;
	m_isVulnerable = true;

	m_alliance = Alliance::NONE_ALLIANCE;
	m_maxHp = 1;
	

	m_type = ObjectTypes::NONE_TYPE;

	m_content = content;
}

void GameObject::Init()
{
	m_currentHp = m_maxHp;
	m_shape.setOrigin(m_shape.getRadius(), m_shape.getRadius());
}

void GameObject::Render()
{
	m_shape.setPosition(m_position);
	
	m_content->renderWindow->draw(m_shape);
}

void GameObject::Update(float deltaTime)
{
	if (m_currentHp <= 0.f)
		m_delete = true;
}

void GameObject::GetDamage(float dmg)
{
	if (m_isVulnerable)
		m_currentHp -= dmg;
}
