#pragma once
#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Menu.h"

class GameWindow
{
public:
	GameWindow();
	void openWindow();
	bool isOpen();
	void finishLevel(int level);
	void finishGame();
	void tutorial();
	void gameOver();
	void changeSound(bool state);
	void close();

	void print(const Board& board,int level, int currPlayer);
	
	void printStatic(const Board& board);
	void printTeleport(const Board& board);
	void printPlayers(const Board& board);
	void printDwarfs(const Board& board);

	bool pollEvent(sf::Event& event);

	int runMenu();

private:
	Menu m_menu;
	sf::Text m_time , m_level , m_currPlayer , m_message;
	sf::Font m_font;
	sf::Image m_icon;
	sf::Sprite m_background;
	sf::RenderWindow m_window;

	void initializeText();
	void printText(const Board& board,int level, int currPlayer);
};