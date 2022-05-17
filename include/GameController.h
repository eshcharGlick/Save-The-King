#pragma once

#include <vector>
#include <string>
#include "SFML/Graphics.hpp"
#include "Macros.h"
#include "Board.h"
#include "GameWindow.h"
#include "AudioHolder.h"



class GameController
{
public:
	GameController();
	void run();

private:
	// members
	Board m_board;
	GameWindow m_window ;

	int m_level = 1;
	int m_currPlayer = 0; // 0 - king , 1 - mage , 2 - warrior , 3 - thief
	bool m_timeLimit = false;
	bool m_sound = true;


	// function
	void runGame( int level);
	void tutorial();
	void restartPlayer();
	void changeSound();
	void close();
	void finishGame();
	void gameOver();

	int runLevel(int level);
	int readNumOfLevel()const;

	void finishLevel(int level);



};