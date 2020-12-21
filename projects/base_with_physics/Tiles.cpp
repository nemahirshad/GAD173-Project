#include "Tiles.h"

Tiles::Tiles()
{
}

Tiles::~Tiles()
{
}

void Tiles::Load(sf::Texture texture, float scale)
{
	sprite = sf::Sprite(texture);
	sprite.setScale(sf::Vector2f(scale, scale));
}
