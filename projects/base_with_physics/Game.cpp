#include "Game.h"

#define gridSizeX 19
#define gridSizeY 10
#define gridSpriteSize 46
#define lineLengthX 505.0f
#define lineLengthY 825.0f 
#define spriteScale 0.05f
#define _red 1
#define _blue 2 
#define _green 3 
#define _yellow 4 

Game::Game(sf::RenderWindow& window) : m_window(window)
{
}

Game::~Game()
{
}

bool Game::start()
{
	m_backgroundSprite = kage::TextureManager::getSprite("data/sky.jpg");
	sf::Vector2u resolution = m_backgroundSprite->getTexture()->getSize();
	m_backgroundSprite->setScale(float(m_window.getSize().x) / resolution.x, float(m_window.getSize().y) / resolution.y);

	//Set Positions
	for (int y = 0; y < gridSizeY + 2; y++)
	{
		pos[y][0] = sf::Vector2f(0, gridSpriteSize * y);

		for (int x = 1; x < gridSizeX; x++)
		{
			pos[y][x] = sf::Vector2f(gridSpriteSize * x, gridSpriteSize * y);
		}
	}

	//Initialize Tiles
	for (int i = 0; i < gridSizeX; i++)
	{
		for (int j = 0; j < gridSizeY; j++)
		{
			tiles[i][j].id = 0;
		}
	}

	//Loading Textures 
	red.loadFromFile("data/Assets/RedTile.png");
	blue.loadFromFile("data/Assets/BlueTile.jpg");
	green.loadFromFile("data/Assets/GreenTile.jpg");
	yellow.loadFromFile("data/Assets/YellowTile.jpg");
	paddleTexture.loadFromFile("data/Assets/paddle.jpg");

	paddle.setTexture(paddleTexture);
	paddle.setScale(0.5f, 0.5f);
	paddle.setPosition(sf::Vector2f(m_window.getSize().x / 2 - paddle.getGlobalBounds().width / 2,
		(m_window.getSize().y / 2 - paddle.getGlobalBounds().height / 2) + 100));

	//music.openFromFile("data/Assets/Chocobo.mp3");

	return true;
}

void Game::update(float deltaT)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
	{
		Load();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		changeX = -3;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		changeX = 3;
	}
	else
	{
		changeX = 0;
	}

	paddle.move(changeX, 0);

	if (loaded)
	{
		for (int i = 0; i < 21; i++)
		{
			for (int j = 0; j < 12; j++)
			{
				switch (tiles[i][j].id)
				{
				case _red:

					tiles[i][j].sprite = sf::Sprite(red);
					tiles[i][j].sprite.setScale(spriteScale, spriteScale);
					tiles[i][j].sprite.setPosition(pos[j][i]);

					break;
				case _blue:
					tiles[i][j].sprite = sf::Sprite(blue);
					tiles[i][j].sprite.setScale(spriteScale, spriteScale);
					tiles[i][j].sprite.setPosition(pos[j][i]);

					break;
				case _green:
					tiles[i][j].sprite = sf::Sprite(green);
					tiles[i][j].sprite.setScale(spriteScale, spriteScale);
					tiles[i][j].sprite.setPosition(pos[j][i]);

					break;
				case _yellow:
					tiles[i][j].sprite = sf::Sprite(yellow);
					tiles[i][j].sprite.setScale(spriteScale, spriteScale);
					tiles[i][j].sprite.setPosition(pos[j][i]);

					break;
				}

			}

		}

	}

}

void Game::render()
{
	m_window.draw(*m_backgroundSprite);

	for (int y = 0; y < 12; y++)
	{
		for (int x = 0; x < 21; x++)
		{
			m_window.draw(lines[y][x]);
		}
	}

	for (int i = 0; i < 21; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			m_window.draw(tiles[i][j].sprite);
		}
	}

	m_window.draw(paddle);
}

void Game::cleanup()
{
	delete m_backgroundSprite;
}

void Game::Load()
{
	std::ifstream outfile("data/Assets/file.txt");

	std::string ignore;

	outfile >> ignore;

	for (int i = 0; i < 21; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			outfile >> tiles[i][j].id;
		}
	}

	outfile.close();

	loaded = true;
}