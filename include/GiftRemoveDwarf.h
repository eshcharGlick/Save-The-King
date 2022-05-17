#pragma once
#include "Gift.h"

class GiftRemoveDwarf : public Gift
{
public:
	GiftRemoveDwarf(const sf::Vector2f& scale, int i, int j, int size);
	virtual ~GiftRemoveDwarf() {}

	virtual void handleCollision(MovingObject& gameObject);
private:

};