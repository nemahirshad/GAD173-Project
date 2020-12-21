#pragma once

#include "app.h"
#include "kage2dutil/physics.h"
#include "Tiles.h"

class Game
{
private:
	sf::RenderWindow& m_window;
	sf::Sprite* m_backgroundSprite;
	sf::Sprite paddle;
public:
	Game(sf::RenderWindow& m_window);
	virtual ~Game();
	virtual bool start();
	virtual void update(float deltaT);
	virtual void render();
	virtual void cleanup();

	sf::RectangleShape lines[12][21];

	sf::Vector2f pos[12][21];

	sf::Vector2i index;

	sf::Music music;

	sf::Texture red;
	sf::Texture blue;
	sf::Texture green;
	sf::Texture yellow;
	sf::Texture paddleTexture;

	Tiles tiles[21][12];

	int indexX;
	int indexY;

	int changeX = 0;

	bool loaded;

	void Game::Load();
};
