#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Tiles
{
public:

	sf::Sprite sprite;

	int id;

	Tiles();
	~Tiles();

	void Load(sf::Texture texture, float scale);
};

