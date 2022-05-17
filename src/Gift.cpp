#include "Gift.h"

Gift::Gift(const sf::Vector2f& scale, int i, int j, int size)
	:StaticObject(TextureHolder::instance().getTextures(GIFT_P)[0], scale, i, j, size)
{
}
