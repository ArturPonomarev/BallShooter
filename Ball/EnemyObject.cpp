#include "EnemyObject.h"
#include "GameConstants.h"
#include "GameMath.h"

EnemyObject::EnemyObject(std::shared_ptr<Content>& content) : GameObject(content)
{
	m_isVulnerable = true;
	m_isCollidable = true;

	m_alliance = Alliance::ENEMY_ALLIANCE;
	m_type = ObjectTypes::ENEMY_TYPE;

	m_maxHp = ENEMY_MAX_HEALTH;
	m_speed = ENEMY_SPEED;
	
	m_attackCooldownTime = ENEMY_ATTACK_COOLDOWN;
	m_attackCooldownTimer = m_attackCooldownTime;
	m_damage = ENEMY_DAMAGE;

	m_shape.setRadius(ENEMY_RADIUS);
	m_shape.setOutlineThickness(5);
	m_shape.setOutlineColor(sf::Color::Black);
	m_shape.setFillColor(ENEMY_COLOR);
}

EnemyObject::~EnemyObject()
{
}

void EnemyObject::Update(float deltaTime)
{
	GameObject::Update(deltaTime);

	m_direction = NormalizeVector(Direction(m_position, m_player->GetPosition()));
}

void EnemyObject::ProcessInput()
{

}

void EnemyObject::Collide(std::shared_ptr<GameObject>& otherObj)
{
	if (otherObj->GetType() == ObjectTypes::PLAYER_TYPE)
	{
		otherObj->GetDamage(m_damage);
		m_delete = true;
	}
}
