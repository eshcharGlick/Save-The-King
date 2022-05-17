#include "Key.h"

Key::Key(const sf::Vector2f& scale, int i, int j, int size)
	:StaticObject(TextureHolder::instance().getTextures(KEY_P)[0], scale, i, j, size)
{
}

Key::~Key()
{
}

void Key::handleCollision(MovingObject& gameObject)
{
	gameObject.handleCollision(*this);
}
