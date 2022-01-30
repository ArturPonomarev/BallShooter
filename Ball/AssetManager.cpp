#include "AssetManager.h"

#include <iostream>

AssetManager::AssetManager()
{
}

AssetManager::~AssetManager()
{
}

void AssetManager::Init()
{
}

void AssetManager::AddTexture(int key, std::string path)
{
	sf::Texture newTexture;
	
	if (newTexture.loadFromFile(path))
		m_textures.emplace(key, std::move(std::make_shared<sf::Texture>(newTexture)));		
}

void AssetManager::AddFont(int key, std::string path)
{
	sf::Font newFont;

	if (newFont.loadFromFile(path))
		m_fonts.emplace(key, std::move(std::make_shared<sf::Font>(newFont)));
}

sf::Texture& AssetManager::GetTexture(int key)
{
	return *(m_textures.at(key).get());
}

sf::Font& AssetManager::GetFont(int key)
{
	return *(m_fonts.at(key).get());
}