#pragma once
#include "King.h"


King::King(const sf::Vector2f & scale, int i, int j, int size)
	:Player(TextureHolder::instance().getTextures(KING_P)[1], scale, i, j, size)
{
}

void King::choose(bool state)
{
	if (state)
		m_icon.setTexture(TextureHolder::instance().getTextures(KING_P)[1]);
	else
		m_icon.setTexture(TextureHolder::instance().getTextures(KING_P)[0]);
}

void King::handleCollision(TeleportCell& gameObject)
{
	if (!m_onTeleport)
	{
		m_icon.setPosition(gameObject.getOtherPos());
		m_onTeleport = true;
	}
}

void King::handleCollision(Throne& gameObject)
{
	m_win = true;
}

void King::handleCollision(Key& gameObject)
{
}

void King::handleCollision(Fire& gameObject)
{
	m_icon.setPosition(m_lastPos);
}

void King::handleCollision(Orc& gameObject)
{
	m_icon.setPosition(m_lastPos);
}

void King::handleCollision(Gate& gameObject)
{
	if (!gameObject.isOpen())
	{
		m_icon.setPosition(m_lastPos);
	}
}

bool King::win()
{
	return m_win;
}
