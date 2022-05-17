#pragma once
#include "StaticObject.h"

class Orc :public StaticObject
{
public:
	Orc(const sf::Vector2f& scale, int i, int j, int size);
	virtual ~Orc() {}
	
	virtual void handleCollision(MovingObject& gameObject);

private:

};
