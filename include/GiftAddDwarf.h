#pragma once
#include "Gift.h"

class GiftAddDwarf : public Gift
{
public:
	GiftAddDwarf(const sf::Vector2f& scale, int i, int j, int size);
	virtual ~GiftAddDwarf() {}

	virtual void handleCollision(MovingObject& gameObject);
private:

};