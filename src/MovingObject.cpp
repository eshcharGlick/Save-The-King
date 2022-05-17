#include "MovingObject.h"


MovingObject::MovingObject(const sf::Texture& icon, const sf::Vector2f& scale, int i, int j, int size)
	:GameObject(icon, scale, i, j, size)
{
	m_lastPos.x = m_icon.getGlobalBounds().left;
	m_lastPos.y = m_icon.getGlobalBounds().top;
}

void MovingObject::setLastPos()
{
	m_lastPos.x = m_icon.getGlobalBounds().left;
	m_lastPos.y = m_icon.getGlobalBounds().top;
}

bool MovingObject::outOfRange()
{
	if (m_icon.getGlobalBounds().left < 0 ||
		m_icon.getGlobalBounds().left + m_icon.getGlobalBounds().width > SIZE ||
		m_icon.getGlobalBounds().top < GAP ||
		m_icon.getGlobalBounds().top + m_icon.getGlobalBounds().height >(float)(SIZE + GAP))
		return true;
	return false;
}

void MovingObject::handleCollision(Wall& gameObject)
{
	m_icon.setPosition(m_lastPos);
}
