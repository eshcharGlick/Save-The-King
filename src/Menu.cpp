#include "Menu.h"

//-----------------------------------------------------------------------------
Menu::Menu()
{
	for (int i = 0; i < ELEMENTS ; i++)
	{
		m_sprites[i].setTexture(TextureHolder::instance().getTextures(MENU_P)[i]);

		if (i == NEW_GAME)
			m_sprites[i].setPosition(125.0f, 450.0f);
		
		if (i == CONTINUE)
			m_sprites[i].setPosition(525.0f, 450.0f);
		
		if (i == TUTORIAL)
			m_sprites[i].setPosition(125.0f, 650.0f);

		if (i == EXIT)
			m_sprites[i].setPosition(525.0f, 650.0f);
		
		if (i == SOUND)
			m_sprites[i].setPosition(75.0f, 825.0f);

		if (i == LOGO)
			m_sprites[i].setPosition(25.0f, 150.0f);
	}
}

//-----------------------------------------------------------------------------
void Menu::print(sf::RenderWindow& window)
{
	for (int i = 0; i < ELEMENTS ; i++)
		window.draw(m_sprites[i]);

	window.display();
}

//-----------------------------------------------------------------------------
int Menu::run(sf::RenderWindow& window)
{
	int action = 0;
	while (window.isOpen())
	{
		print(window);

		sf::Event event;
		while (window.waitEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseButtonReleased:
				action = buttonPressed(window, event);
				
				if (action >= QUIT && action <= SOUND)
					return action;
			}
		}
	}
	return QUIT;
}

void Menu::changeSound(bool state)
{
	if (state)
		m_sprites[SOUND].setTexture(TextureHolder::instance().getTextures(MENU_P)[SOUND_ON]);
	else
		m_sprites[SOUND].setTexture(TextureHolder::instance().getTextures(MENU_P)[SOUND_OFF]);
}

//-----------------------------------------------------------------------------
int Menu::buttonPressed(sf::RenderWindow& window ,sf::Event event)
{
	auto location = window.mapPixelToCoords({ event.mouseButton.x,event.mouseButton.y });

	if (m_sprites[NEW_GAME].getGlobalBounds().contains(location))
		return NEW_GAME;

	if (m_sprites[CONTINUE].getGlobalBounds().contains(location))
		return CONTINUE;

	if (m_sprites[TUTORIAL].getGlobalBounds().contains(location))
		return TUTORIAL;

	if (m_sprites[SOUND].getGlobalBounds().contains(location))
		return SOUND;

	if (m_sprites[EXIT].getGlobalBounds().contains(location))
		return QUIT;

	return NOTHING;
}