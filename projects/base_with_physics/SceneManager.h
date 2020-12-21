#pragma once
#include "OptionsMenu.h"
#include "Game.h"
#include "MainMenu.h"

class SceneManager
{
private:
	OptionsMenu optionsMenu;
	Game game;
	MainMenu mainMenu;
	int m_index = 0;

public:
	SceneManager(sf::RenderWindow& window);
	~SceneManager();

	void Run(int index);

	void Start();
	void Update(float deltaTime);
	void Render();
};

