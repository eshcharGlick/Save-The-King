#pragma once
#include "Gift.h"

class GiftMoreTime : public Gift
{
public:
	GiftMoreTime(const sf::Vector2f& scale, int i, int j, int size);
	virtual ~GiftMoreTime() {}

	virtual void handleCollision(MovingObject& gameObject);
private:

};