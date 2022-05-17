#include "Wall.h"

Wall::Wall(const sf::Vector2f& scale, int i, int j, int size)
	:StaticObject(TextureHolder::instance().getTextures(WALL_P)[0], scale, i, j, size)
{
}

Wall::~Wall()
{
}

void Wall::handleCollision(MovingObject& gameObject)
{
	gameObject.handleCollision(*this);
}
