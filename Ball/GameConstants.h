#pragma once
#include "SFML/Graphics/Color.hpp"

//Спавн врагов
const float ENEMY_SPAWN_TIME = 3.f;
const int MAX_ENEMY_COUNT = 10;
//------------

//Характеристики пуль
const sf::Color BULLET_COLOR = sf::Color::Green;
const float BULLET_RADIUS = 5.f;
const float BULLET_SPEED = 500.f;
const float BULLET_DAMAGE = 1.f;
const float BULLET_SPREAD = 5.f;	//угол разброса пуль в градусах
//-------------------

//Характеристики врагов
const sf::Color ENEMY_COLOR = sf::Color::Magenta;
const float ENEMY_RADIUS = 20.f;
const float ENEMY_SPEED = 90.f;
const float ENEMY_MAX_HEALTH = 5.f;
const float ENEMY_DAMAGE = 1.f;

const float ENEMY_ATTACK_COOLDOWN = 1.f; //не используется
//---------------------


//Характеристики игрока
const sf::Color PLAYER_COLOR = sf::Color::Red;
const float PLAYER_RADIUS = 25.f;
const float PLAYER_SPEED = 100.f;
const float PLAYER_RELOAD_TIME = 0.1f;
const float PLAYER_MAX_HEALTH = 1000.f;
//---------------------
