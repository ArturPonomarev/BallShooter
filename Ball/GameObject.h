#pragma once

#include "SFML/Graphics.hpp"
#include "Assets.h"

#include <memory>

struct Content;

class GameObject
{
public:
	GameObject(std::shared_ptr<Content>& content);
	virtual ~GameObject() {};

	virtual void Init() = 0;

	virtual void Render();
	virtual void Update(float deltaTime);

	virtual void ProcessInput() = 0;

	virtual void Collide(GameObject& otherObj) = 0;

	virtual void GetDamage(float dmg);
	
	//----�������/�������--------------------------------------
	//������
	sf::Vector2f GetDirection() { return m_direction; }
	void SetDirection(sf::Vector2f newDir) { m_direction = newDir; }

	sf::Vector2f GetPosition() { return m_position; }
	void SetPosition(sf::Vector2f newPos) { m_position = newPos; }

	float GetSpeed() { return m_speed; }
	void SetSpeed(float newSpeed) { m_speed = newSpeed; }

	bool GetCollidable() { return m_isCollidable; }
	void SetCollidable(bool newCol) { m_isCollidable = newCol; }
	////////////////////////

	//�����
	sf::CircleShape GetShape() { return m_shape; }
	void SetShape(sf::CircleShape newShape) { m_shape = newShape; }
	////////////////////////

	//������ �����
	Alliance GetAlliance() { return m_alliance; }
	void SetAlliance(Alliance newAlliance) { m_alliance = newAlliance; }

	float GetCurrentHp() { return m_currentHp; }
	void SetCurrentHp(float newCurHp) { m_currentHp = newCurHp; }

	float GetMaxHp() { return m_maxHp; }
	void SetMaxHp(float newMaxHp) { m_maxHp = newMaxHp; }

	bool GetVulnerable() { return m_isVulnerable; }
	void SetVulnerable(bool newVul) { m_isVulnerable = newVul; }
	////////////////////////

	//��� 
	ObjectTypes GetType() { return m_type; }
	void SetSpeed(ObjectTypes newType) { m_type = newType; }

	//��������
	bool GetDelete() { return m_delete; }
	void SetDelete(bool newDelete) { m_delete = newDelete; }
	////////////////////////

	//---------------------------------------------------------
protected:
	//������
	sf::Vector2f m_direction;	//����
	sf::Vector2f m_position;	//����
	float m_speed;				//����
	bool m_isCollidable;		//����


	//�����
	sf::CircleShape m_shape;	//����

	//������ � �������� (������������, ������ � �.�.)
	std::shared_ptr<Content> m_content;			//����

	//������ �����
	Alliance m_alliance;		//����
	float m_currentHp;			//����
	float m_maxHp;				//����
	bool m_isVulnerable;		//����

	//��� 
	ObjectTypes m_type;			//����

	//��������
	bool m_delete;
};

