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
	
	//----Сеттеры/Геттеры--------------------------------------
	//Физика
	sf::Vector2f GetDirection() { return m_direction; }
	void SetDirection(sf::Vector2f newDir) { m_direction = newDir; }

	sf::Vector2f GetPosition() { return m_position; }
	void SetPosition(sf::Vector2f newPos) { m_position = newPos; }

	float GetSpeed() { return m_speed; }
	void SetSpeed(float newSpeed) { m_speed = newSpeed; }

	bool GetCollidable() { return m_isCollidable; }
	void SetCollidable(bool newCol) { m_isCollidable = newCol; }
	////////////////////////

	//Форма
	sf::CircleShape GetShape() { return m_shape; }
	void SetShape(sf::CircleShape newShape) { m_shape = newShape; }
	////////////////////////

	//Боевая часть
	Alliance GetAlliance() { return m_alliance; }
	void SetAlliance(Alliance newAlliance) { m_alliance = newAlliance; }

	float GetCurrentHp() { return m_currentHp; }
	void SetCurrentHp(float newCurHp) { m_currentHp = newCurHp; }

	float GetMaxHp() { return m_maxHp; }
	void SetMaxHp(float newMaxHp) { m_maxHp = newMaxHp; }

	bool GetVulnerable() { return m_isVulnerable; }
	void SetVulnerable(bool newVul) { m_isVulnerable = newVul; }
	////////////////////////

	//Тип 
	ObjectTypes GetType() { return m_type; }
	void SetSpeed(ObjectTypes newType) { m_type = newType; }

	//Удаление
	bool GetDelete() { return m_delete; }
	void SetDelete(bool newDelete) { m_delete = newDelete; }
	////////////////////////

	//---------------------------------------------------------
protected:
	//Физика
	sf::Vector2f m_direction;	//есть
	sf::Vector2f m_position;	//есть
	float m_speed;				//есть
	bool m_isCollidable;		//есть


	//Форма
	sf::CircleShape m_shape;	//есть

	//Доступ к контенту (рендервиндов, стейты и т.д.)
	std::shared_ptr<Content> m_content;			//есть

	//Боевая часть
	Alliance m_alliance;		//есть
	float m_currentHp;			//есть
	float m_maxHp;				//есть
	bool m_isVulnerable;		//есть

	//Тип 
	ObjectTypes m_type;			//есть

	//Удаление
	bool m_delete;
};

