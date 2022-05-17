#pragma once

#include "GameObject.h"

class MovingObject : public GameObject
{
public:
	MovingObject(const sf::Texture& icon, const sf::Vector2f& scale, int i, int j, int size);
	virtual ~MovingObject() {}

	virtual void choose(bool state) = 0;
	virtual void move(float deltaTime) = 0;
	virtual void setLastPos();
	bool outOfRange();

	virtual void notOnTeleport() = 0;
	virtual void handleCollision(MovingObject& gameObject) = 0;

	virtual void handleCollision(Throne& gameObject) = 0;
	virtual void handleCollision(Key& gameObject) = 0;
	virtual void handleCollision(Fire& gameObject) = 0;
	virtual void handleCollision(Wall& gameObject)override;
	virtual void handleCollision(Orc& gameObject) = 0;
	virtual void handleCollision(Gate& gameObject) = 0;
	virtual void handleCollision(TeleportCell& gameObject) = 0;
	virtual void handleCollision(GiftMoreTime& gameObject) = 0;
	virtual void handleCollision(GiftLessTime& gameObject) = 0;
	virtual void handleCollision(GiftAddDwarf& gameObject) = 0;
	virtual void handleCollision(GiftRemoveDwarf& gameObject) = 0;

protected:
	sf::Vector2f m_lastPos;

private:

};
