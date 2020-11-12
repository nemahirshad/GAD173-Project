#pragma once

#include "app.h"
#include "Tiles.h"
#include "Button.h"

class Example : public App
{
public:
	Example();
	virtual ~Example();
	virtual bool start();
	virtual void update(float deltaT);
	virtual void render();
	virtual void cleanup();
	static Example &inst();

	sf::Sprite *m_backgroundSprite;

	sf::RectangleShape lines[12][21];
	
	sf::Vector2f pos[12][21];

	sf::Vector2i index;

	sf::Music music;

	sf::Texture transparent;
	sf::Texture red;
	sf::Texture blue;
	sf::Texture green;
	sf::Texture yellow;

	Tiles tiles[21][12];

	int indexX;
	int indexY;
	int selection;
	
	int current;

	bool loaded;

	void Example::Clear();
	void Example::Save();
	void Example::Load();
};
