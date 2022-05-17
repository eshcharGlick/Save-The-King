#pragma once
#include "SFML/Graphics.hpp"
#include "Macros.h"
#include "TextureHolder.h"

class MovingObject;
class Player;
class King;
class Mage;
class Theif;
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
class GiftMoreTime;
class GiftLessTime;
class GiftAddDwarf;
class GiftRemoveDwarf;

class GameObject
{
public:
	GameObject(const sf::Texture& icon, const sf::Vector2f& scale, int i, int j, int size);
	virtual ~GameObject();

	sf::Sprite draw() const;
	void setSpritePos(int i, int j, int size);
	sf::FloatRect getGlobalBounds() const;

	bool checkCollision(const sf::FloatRect& rec) const;

	virtual void handleCollision(MovingObject& gameObject) = 0;

	virtual void handleCollision(Throne& gameObject) = 0;
	virtual void handleCollision(Key& gameObject) = 0;
	virtual void handleCollision(Fire& gameObject) = 0;
	virtual void handleCollision(Wall& gameObject) = 0;
	virtual void handleCollision(Orc& gameObject) = 0;
	virtual void handleCollision(Gate& gameObject) = 0;
	virtual void handleCollision(TeleportCell& gameObject) = 0;
	virtual void handleCollision(GiftMoreTime& gameObject) = 0;
	virtual void handleCollision(GiftLessTime& gameObject) = 0;
	virtual void handleCollision(GiftAddDwarf& gameObject) = 0;
	virtual void handleCollision(GiftRemoveDwarf& gameObject) = 0;


protected:
	sf::Sprite m_icon;

private:

	
};
