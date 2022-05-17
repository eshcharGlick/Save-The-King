#pragma once
#include "Thief.h"

Thief::Thief(const sf::Vector2f & scale, int i, int j, int size)
	:Player(TextureHolder::instance().getTextures(THIEF_P)[0], scale, i, j, size)
{
}

void Thief::choose(bool state)
{
	if (!state&& !haveKey())
		m_icon.setTexture(TextureHolder::instance().getTextures(THIEF_P)[0]);
	else if (state && !haveKey())
		m_icon.setTexture(TextureHolder::instance().getTextures(THIEF_P)[1]);
	else if (!state && haveKey())
		m_icon.setTexture(TextureHolder::instance().getTextures(THIEF_P)[2]);
	else if (state && haveKey())
		m_icon.setTexture(TextureHolder::instance().getTextures(THIEF_P)[3]);
}

bool Thief::haveKey()
{
	return m_haveKey;
}

bool Thief::peekKey()
{
	m_icon.setTexture(TextureHolder::instance().getTextures(THIEF_P)[3]);
	if (!haveKey())
	{
		m_haveKey = true;
		return true;
	}
	return false;
}

void Thief::handleCollision(TeleportCell& gameObject)
{
	if (!m_onTeleport)
	{
		m_icon.setPosition(gameObject.getOtherPos());
		m_onTeleport = true;
	}
}

void Thief::handleCollision(Throne& gameObject)
{
	m_icon.setPosition(m_lastPos);
}

void Thief::handleCollision(Key& gameObject)
{
	if (peekKey())
	{
		//
		gameObject.remove();
	}
}

void Thief::handleCollision(Fire& gameObject)
{
	m_icon.setPosition(m_lastPos);
}

void Thief::handleCollision(Orc& gameObject)
{
	m_icon.setPosition(m_lastPos);
}

void Thief::handleCollision(Gate& gameObject)
{
	if (!gameObject.isOpen())
	{
		if (haveKey())
		{
			gameObject.openGate();
			m_haveKey = false;
			m_icon.setTexture(TextureHolder::instance().getTextures(THIEF_P)[1]);
		}
		else
			m_icon.setPosition(m_lastPos);
	}
}
