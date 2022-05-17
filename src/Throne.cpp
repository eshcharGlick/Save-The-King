#include "Throne.h"

Throne::Throne(const sf::Vector2f& scale, int i, int j, int size)
	: StaticObject(TextureHolder::instance().getTextures(THRONE_P)[0], scale, i, j, size)
{
}

Throne::~Throne()
{
}

void Throne::handleCollision(MovingObject& gameObject)
{
	gameObject.handleCollision(*this);
}
