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

	virtual void Render() = 0;
	virtual void Update(float deltaTime) = 0;

	virtual void ProcessInput() = 0;

	virtual void Collide(GameObject& otherObj) = 0;
	
	//----Сеттеры/Геттеры--------------------------------------
	sf::Vector2f GetDirection() { return m_direction; }
	void SetDirection(sf::Vector2f newDir) { m_direction = newDir; }

	std::shared_ptr<sf::CircleShape> GetShape() { return m_shape; }
	void SetShape(std::shared_ptr<sf::CircleShape> newShape) { m_shape = newShape; }

	float GetSpeed() { return m_speed; }
	void SetSpeed(float newSpeed) { m_speed = newSpeed; }

	Alliance GetAlliance() { return m_alliance; }
	void SetAlliance(Alliance newAlliance) { m_alliance = newAlliance; }

	ObjectTypes GetType() { return m_type; }
	void SetSpeed(ObjectTypes newType) { m_type = newType; }
	//---------------------------------------------------------
protected:
	sf::Vector2f m_direction;
	std::shared_ptr<sf::CircleShape> m_shape;
	
	float m_speed;
	
	std::shared_ptr<Content> m_content;

	Alliance m_alliance;

	ObjectTypes m_type;
};

