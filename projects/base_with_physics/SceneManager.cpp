#include "SceneManager.h"

SceneManager::SceneManager(sf::RenderWindow& window) : mainMenu(window, *this), game(window), optionsMenu(window)
{
}

SceneManager::~SceneManager()
{
}

void SceneManager::Run(int index)
{
	m_index = index;
}

void SceneManager::Start()
{
	mainMenu.start();
	optionsMenu.start();
	game.start();
}

void SceneManager::Update(float deltaTime)
{
	switch (m_index)
	{
	case 0:
		mainMenu.update(deltaTime);
		break;

	case 1:
		optionsMenu.update(deltaTime);
		break;

	case 2:
		game.update(deltaTime);
		break;
	}
}

void SceneManager::Render()
{
	switch (m_index)
	{
	case 0:
		mainMenu.render();
		break;

	case 1:
		optionsMenu.render();
		break;

	case 2:
		game.render();
		break;
	}
}
