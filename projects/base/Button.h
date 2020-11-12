#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Button
{
public:
	sf::Sprite sprite;

	Button();
	~Button();

	void SetPosition(float x, float y);
	void Load(sf::Texture texture, float scale);
};

