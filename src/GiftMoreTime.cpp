#include "GiftMoreTime.h"

GiftMoreTime::GiftMoreTime(const sf::Vector2f& scale, int i, int j, int size)
	:Gift(scale, i, j, size)
{
}

void GiftMoreTime::handleCollision(MovingObject& gameObject)
{
	gameObject.handleCollision(*this);
}
