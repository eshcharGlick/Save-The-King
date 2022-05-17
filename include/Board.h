#pragma once

#include "Macros.h"
#include "MovingObject.h"
#include "StaticObject.h"
#include "SFML/Graphics.hpp"
#include "TextureHolder.h"

#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include <fstream>

class MovingObject;
class Player;
class King;
class Mage;
class Thief;
class Warrior;
class Dwarf;

class StaticObject;
class Orc;
class Key;
class Fire;
class Wall;
class Gate;
class Throne;
class TeleportCell;
class Gift;

class Board
{
public:
	Board();
	void InitializeLevel(int level);

	int getRows() const;
	int getCols() const;
	int getTime() const;

	int TimeRemaining() const;

	int staticSize() const;
	int teleportSize() const;
	int dwarfSize() const;

	void moveThePlayer(float deltaTime, int currPlayer);
	void moveDwarfs(float deltaTime);
	void clearObjects();
	void choosePlayer(int oldPlayer);

	void handleCollisions(int currPlayer);
	void setLastPos(int currPlayer);
	void updateCollision();

	bool isWin();
	bool handleTime(float deltaTime);

	sf::Sprite getStatic(int i) const;
	sf::Sprite getTeleport(int i) const;
	sf::Sprite getPlayers(int i) const;
	sf::Sprite getDwarfs(int i) const;

private:
	int m_rows,
		m_cols,
		m_size,
		m_time;
	float m_timePassed = 0;
	bool m_win = false;
	sf::Vector2f m_scale;
	std::vector <std::string> m_board;

	std::vector <std::vector < std::unique_ptr<MovingObject>>> m_players;
	std::vector < std::unique_ptr<MovingObject>> m_dwarfs;
	std::vector < std::unique_ptr<StaticObject>> m_static;
	std::vector < std::unique_ptr<StaticObject>> m_teleport;
	
	void readLevel(int level);
	void createObjects();
	void setObject(char element, sf::Vector2f scale, int i, int j, int size);
	void calculateScale();
	void sortTeleport();

	std::unique_ptr<StaticObject> createStaticObject(char element, int i, int j);
	std::unique_ptr<StaticObject> chooseGift( int i, int j);
	std::unique_ptr<MovingObject> createMoveableObject(char element, int i, int j);

};
