#pragma once
#include "StaticObject.h"

class Wall : public StaticObject
{
public:
	Wall(const sf::Vector2f& scale, int i, int j, int size);
	
	virtual ~Wall();

	virtual void handleCollision(MovingObject& gameObject);

private:

};
