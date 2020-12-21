#include "example.h"
#include "Tiles.h"
#include <iostream>

#define gridSizeX 19
#define gridSizeY 10
#define gridSpriteSize 46
#define lineLengthY 505.0f
#define lineLengthX 825.0f 
#define spriteScale 0.05f
#define _red 1
#define _blue 2 
#define _green 3 
#define _yellow 4 

Example::Example(): App()
{
}

Example::~Example()
{
}

Example &Example::inst()
{
	static Example s_instance;
	return s_instance;
}

bool Example::start()
{
	m_backgroundSprite = kage::TextureManager::getSprite("data/Assets/Sky.jpg");
	sf::Vector2u resolution = m_backgroundSprite->getTexture()->getSize();
	m_backgroundSprite->setScale(float(m_window.getSize().x) / resolution.x, float(m_window.getSize().y) / resolution.y);

	//Draw grid
	for (int y = 0; y < gridSizeY + 2; y++)
	{
		lines[y][0] = sf::RectangleShape(sf::Vector2f(lineLengthX, 1.0f));
		lines[y][0].setFillColor(sf::Color::Magenta);
		lines[y][0].setPosition(sf::Vector2f(0, gridSpriteSize * y));
		pos[y][0] = sf::Vector2f(0, gridSpriteSize * y);

		for (int x = 1; x < gridSizeX; x++)
		{
			lines[y][x] = sf::RectangleShape(sf::Vector2f(1.0f, lineLengthY));
			lines[y][x].setFillColor(sf::Color::Red);
			lines[y][x].setPosition(sf::Vector2f(gridSpriteSize * x, 0));
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
	transparent.loadFromFile("data/Assets/StartTile.png");
	red.loadFromFile("data/Assets/RedTile.png");
	blue.loadFromFile("data/Assets/BlueTile.jpg");
	green.loadFromFile("data/Assets/GreenTile.jpg");
	yellow.loadFromFile("data/Assets/YellowTile.jpg");

	if (!music.openFromFile("data/Assets/Chocobo.ogg")) 
	{
		return -1;
	}
	music.play();
	return true;
}

void Example::update(float deltaT)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && m_window.hasFocus())
	{
		m_running = false;
	}

	//Check if tile is selected
	if (sf::Mouse::getPosition(m_window).x < (gridSizeX - 1) * gridSpriteSize && sf::Mouse::getPosition(m_window).y < (gridSizeY + 1) * gridSpriteSize && current > 0)
	{
		index = sf::Mouse::getPosition(m_window);
		indexX = index.x / gridSpriteSize;
		indexY = index.y / gridSpriteSize;

		switch (current)
		{
		case _red:
			//Create red tile
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			{
				tiles[indexX][indexY].sprite = sf::Sprite(red);
				tiles[indexX][indexY].sprite.setScale(spriteScale, spriteScale);
				tiles[indexX][indexY].sprite.setPosition(pos[indexY][indexX]);
				tiles[indexX][indexY].id = 1;
			}
			break;

		case _blue:
			//create blue tile
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			{
				tiles[indexX][indexY].sprite = sf::Sprite(blue);
				tiles[indexX][indexY].sprite.setScale(spriteScale, spriteScale);
				tiles[indexX][indexY].sprite.setPosition(pos[indexY][indexX]);
				tiles[indexX][indexY].id = 2;
			}
			break;

		case _green:
			//Create green tile
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			{
				tiles[indexX][indexY].sprite = sf::Sprite(green);
				tiles[indexX][indexY].sprite.setScale(spriteScale, spriteScale);
				tiles[indexX][indexY].sprite.setPosition(pos[indexY][indexX]);
				tiles[indexX][indexY].id = 3;
			}
			break;

		case _yellow:
			//Create yellow tile
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			{
				tiles[indexX][indexY].sprite = sf::Sprite(yellow);
				tiles[indexX][indexY].sprite.setScale(spriteScale, spriteScale);
				tiles[indexX][indexY].sprite.setPosition(pos[indexY][indexX]);
				tiles[indexX][indexY].id = 4;
			}
			break;
		}
	}

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

	ImGui::Begin("Kage2D");
	if (ImGui::Button("Red"))
	{
		current = _red;
	}
	if (ImGui::Button("Blue"))
	{
		current = _blue;
	}
	if (ImGui::Button("Green"))
	{
		current = _green;
	}
	if (ImGui::Button("Yellow"))
	{
		current = _yellow;
	}
	if (ImGui::Button("Clear")) 
	{
		Clear();
	}
	if (ImGui::Button("Save"))
	{
		Save();
	}
	if (ImGui::Button("Load"))
	{
		Load();
	}
	if(ImGui::Button("Exit"))
	{ 
		m_running = false;
	}
	ImGui::End();
}

void Example::render()
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
}

void Example::cleanup()
{
	delete m_backgroundSprite;
}

void Example::Clear() 
{
	for (int i = 0; i < gridSizeX; i++)
	{
		for (int j = 0; j < gridSizeY; j++)
		{
			tiles[i][j].sprite.setTexture(transparent);
			tiles[i][j].id = 0;
		}
	}
}

void Example::Save() 
{
	std::ofstream outfile;
	outfile.open("data/Assets/file.txt", std::fstream::out);

	outfile << "Map" << "\n";

	for (int i = 0; i < 21; i++) 
	{
		for (int j = 0; j < 12; j++)
		{
			outfile << " " << tiles[i][j].id;
		}
		outfile << "\n";
	}

	outfile.close();
}

void Example::Load() 
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