#pragma once
#include <SFML/Graphics.hpp>
#include "Macros.h"
#include "TextureHolder.h"

class Menu
{
public:
	Menu();
	int run(sf::RenderWindow & window);
	void changeSound(bool state);

private:
	void print(sf::RenderWindow& window);
	int buttonPressed(sf::RenderWindow& window , sf::Event event);

	sf::Sprite m_sprites[ELEMENTS];
};