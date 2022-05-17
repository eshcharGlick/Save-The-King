#include "GiftAddDwarf.h"

GiftAddDwarf::GiftAddDwarf(const sf::Vector2f& scale, int i, int j, int size)
	:Gift(scale, i, j, size)
{
}

void GiftAddDwarf::handleCollision(MovingObject& gameObject)
{
	gameObject.handleCollision(*this);
}
