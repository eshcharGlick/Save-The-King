#include "StaticObject.h"

StaticObject::StaticObject(const sf::Texture& icon, const sf::Vector2f& scale, int i, int j, int size)
	:GameObject(icon, scale, i, j, size)
{
}

StaticObject::~StaticObject()
{
}

void StaticObject::handleCollision(Throne& gameObject)
{
}

void StaticObject::handleCollision(Key& gameObject)
{
}

void StaticObject::handleCollision(Fire& gameObject)
{
}

void StaticObject::handleCollision(Wall& gameObject)
{
}

void StaticObject::handleCollision(Orc& gameObject)
{
}

void StaticObject::handleCollision(Gate& gameObject)
{
}

void StaticObject::handleCollision(TeleportCell& gameObject)
{
}

void StaticObject::handleCollision(GiftMoreTime& gameObject)
{
}

void StaticObject::handleCollision(GiftLessTime& gameObject)
{
}

void StaticObject::handleCollision(GiftAddDwarf& gameObject)
{
}

void StaticObject::handleCollision(GiftRemoveDwarf& gameObject)
{
}

void StaticObject::remove()
{
	m_exsit = false;
}

bool StaticObject::isExsit()
{
	return m_exsit;
}
