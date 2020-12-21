#pragma once

#include "app.h"
#include "kage2dutil/physics.h"

#define TEXTS_ARRAY_SIZE 3

class SceneManager;

class MainMenu
{
private:
	sf::RenderWindow& m_window;
	SceneManager& m_sceneManager;
	sf::Font font;
	sf::Text texts[TEXTS_ARRAY_SIZE];

public:
	MainMenu(sf::RenderWindow& m_window, SceneManager& sceneManager);
	virtual ~MainMenu();
	virtual bool start();
	virtual void update(float deltaT);
	virtual void render();
	virtual void cleanup();

	int selectedItem = 0;
	bool isKeyRelesedPreviously = true;
};
