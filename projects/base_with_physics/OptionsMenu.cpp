#include "OptionsMenu.h"

OptionsMenu::OptionsMenu(sf::RenderWindow& window) : m_window(window)
{
}

OptionsMenu::~OptionsMenu()
{
}

bool OptionsMenu::start()
{
	m_backgroundSprite = kage::TextureManager::getSprite("data/sky.jpg");

	return true;
}

void OptionsMenu::update(float deltaT)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && m_window.hasFocus())
	{

	}
}

void OptionsMenu::render()
{
	m_window.draw(*m_backgroundSprite);
}

void OptionsMenu::cleanup()
{
	delete m_backgroundSprite;
}

