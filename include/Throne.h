#pragma once
#include "StaticObject.h"

class Throne : public StaticObject
{
public:
	Throne(const sf::Vector2f& scale, int i, int j, int size);
	virtual ~Throne();

	virtual void handleCollision(MovingObject& gameObject);

private:

};