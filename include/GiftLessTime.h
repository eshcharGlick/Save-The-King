#pragma once
#include "Gift.h"

class GiftLessTime : public Gift
{
public:
	GiftLessTime(const sf::Vector2f& scale, int i, int j, int size);
	virtual ~GiftLessTime() {}

	virtual void handleCollision(MovingObject& gameObject);
private:

};