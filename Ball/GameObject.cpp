#include "GameObject.h"

GameObject::GameObject(std::shared_ptr<Content>& content)
{
	m_direction = { 0.f,0.f };

	m_alliance = Alliance::NONE_ALLIANCE;
	m_speed = 0.f;
	m_type = ObjectTypes::NONE_TYPE;

	m_content = content;
}
