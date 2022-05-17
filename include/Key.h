#pragma once

#include "StaticObject.h"

class Key : public StaticObject
{
public:
	Key(const sf::Vector2f& scale, int i, int j, int size);
	virtual ~Key();

	virtual void handleCollision(MovingObject& gameObject);

private:

};