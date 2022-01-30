#include "PlayerCreator.h"

#include "Assets.h"
#include "Game.h"

std::shared_ptr<GameObject>PlayerCreator::CreateObject(std::shared_ptr<Content>& content, sf::Vector2f pos, sf::Vector2f dir, Alliance ally)
{
	std::shared_ptr<GameObject> player = std::make_shared<PlayerObject>(content);

	player->SetSpeed(150.f);

	std::shared_ptr<sf::CircleShape> newShape = std::make_shared<sf::CircleShape>();

	newShape->setFillColor(sf::Color::Red);
	newShape->setRadius(30);
	newShape->setOutlineThickness(5);
	newShape->setOutlineColor(sf::Color::Black);
	newShape->setOrigin(30.f, 30.f);
	newShape->setPosition(pos);

	player->SetShape(std::move(newShape));

	return player;
}
