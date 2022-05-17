#include "GiftRemoveDwarf.h"

GiftRemoveDwarf::GiftRemoveDwarf(const sf::Vector2f& scale, int i, int j, int size)
	:Gift(scale, i, j, size)
{
}

void GiftRemoveDwarf::handleCollision(MovingObject& gameObject)
{
	gameObject.handleCollision(*this);
}
