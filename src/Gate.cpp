#include "Gate.h"

Gate::Gate(const sf::Vector2f& scale, int i, int j, int size) 
	:StaticObject(TextureHolder::instance().getTextures(GATE_P)[0], scale, i, j, size)
{
}

void Gate::handleCollision(MovingObject& gameObject)
{
	gameObject.handleCollision(*this);
}

bool Gate::isOpen()
{
	return m_isOpen;
}

void Gate::openGate()
{
	m_isOpen = true;
	m_icon.setTexture(TextureHolder::instance().getTextures(GATE_P)[1]);
}
