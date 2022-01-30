#pragma once

#include <SFML/Graphics.hpp>

#include <memory>
#include <map>
#include <string>



class AssetManager
{
public:
	AssetManager();
	~AssetManager();

	void Init();

	void AddTexture(int key, std::string path);
	void AddFont(int key, std::string path);

	sf::Texture& GetTexture(int key);
	sf::Font& GetFont(int key);

private:
	std::map<int, std::shared_ptr<sf::Texture>> m_textures;
	std::map<int, std::shared_ptr<sf::Font>> m_fonts;
};

