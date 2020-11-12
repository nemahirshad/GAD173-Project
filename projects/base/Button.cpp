#include "Button.h"
#include <iostream>

Button::Button()
{
}

Button::~Button()
{
}

void Button::SetPosition(float x, float y)
{
    sprite.setPosition(x, y);
}

void Button::Load(sf::Texture texture, float scale)
{
	sprite = sf::Sprite(texture);
	sprite.setScale(sf::Vector2f(scale, scale));
}

