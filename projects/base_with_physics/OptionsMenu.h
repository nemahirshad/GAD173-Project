#pragma once

#include "app.h"
#include "kage2dutil/physics.h"

class OptionsMenu
{
private:
	sf::RenderWindow& m_window;
	sf::Sprite* m_backgroundSprite;
public:
	OptionsMenu(sf::RenderWindow& m_window);
	virtual ~OptionsMenu();
	virtual bool start();
	virtual void update(float deltaT);
	virtual void render();
	virtual void cleanup();
};
