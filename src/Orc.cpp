#include "Orc.h"

Orc::Orc(const sf::Vector2f& scale, int i, int j, int size)
	:StaticObject(TextureHolder::instance().getTextures(ORC_P)[0], scale, i, j, size)
{
}

void Orc::handleCollision(MovingObject& gameObject)
{
	gameObject.handleCollision(*this);
}
