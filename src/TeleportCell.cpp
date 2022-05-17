#pragma once

#include "TeleportCell.h"

TeleportCell::TeleportCell(const sf::Vector2f& scale, int i, int j, int size, char id)
	:StaticObject(TextureHolder::instance().getTextures(TELEPORT_P)[0], scale, i, j, size) , m_id (id - '0')
{
}

int TeleportCell::getId()
{
	return m_id;
}

sf::Vector2f TeleportCell::getOtherPos()
{
	return m_otherPos;
}

void TeleportCell::setOtherPos(sf::FloatRect rec)
{
	m_otherPos.y = rec.top;
	m_otherPos.x = rec.left;
}

void TeleportCell::handleCollision(MovingObject& gameObject)
{
	gameObject.handleCollision(*this);
}
