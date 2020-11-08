#include "example.h"

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
	m_backgroundSprite = kage::TextureManager::getSprite("data/sky.jpg");
	sf::Vector2u resolution = m_backgroundSprite->getTexture()->getSize();
	m_backgroundSprite->setScale(float(m_window.getSize().x) / resolution.x, float(m_window.getSize().y) / resolution.y);


	for (int y = 0; y < 33; y++)
	{
		lines[y][0] = sf::RectangleShape(sf::Vector2f(1024.0f, 1.0f));
		lines[y][0].setFillColor(sf::Color::Red);
		lines[y][0].setPosition(sf::Vector2f(0, 32 * y));

		for (int x = 1; x < 33; x++)
		{
			lines[y][x] = sf::RectangleShape(sf::Vector2f(1024.0f, 1.0f));
			lines[y][x].setFillColor(sf::Color::Red);
			lines[y][x].setPosition(sf::Vector2f(32 * x, 0));
			lines[y][x].rotate(90);
		}
	}

	return true;
}

void Example::update(float deltaT)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && m_window.hasFocus())
	{
		m_running = false;
	}

	ImGui::Begin("Kage2D");
	if(ImGui::Button("Exit"))
	{ 
		m_running = false;
	}
	ImGui::End();
}

void Example::render()
{
	m_window.draw(*m_backgroundSprite);

	for (int y = 0; y < 33; y++)
	{
		for (int x = 0; x < 33; x++)
		{
			m_window.draw(lines[y][x]);
		}
	}
}

void Example::cleanup()
{
	delete m_backgroundSprite;
}

