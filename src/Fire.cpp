#include "Fire.h"

Fire::Fire(const sf::Vector2f& scale, int i, int j, int size)
	:StaticObject(TextureHolder::instance().getTextures(FIRE_P)[0], scale, i, j, size)
{
}

void Fire::handleCollision(MovingObject& gameObject)
{
	gameObject.handleCollision(*this);
}

