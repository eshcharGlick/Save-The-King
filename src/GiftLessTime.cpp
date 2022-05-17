#include "GiftLessTime.h"

GiftLessTime::GiftLessTime(const sf::Vector2f& scale, int i, int j, int size)
	:Gift(scale, i, j, size)
{
}

void GiftLessTime::handleCollision(MovingObject& gameObject)
{
	gameObject.handleCollision(*this);
}
