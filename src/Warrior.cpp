#pragma once
#include "Warrior.h"

Warrior::Warrior(const sf::Vector2f & scale, int i, int j, int size)
	:Player(TextureHolder::instance().getTextures(WARRIOR_P)[0], scale, i, j, size)
{
}

void Warrior::choose(bool state)
{
	if (state)
		m_icon.setTexture(TextureHolder::instance().getTextures(WARRIOR_P)[1]);
	else
		m_icon.setTexture(TextureHolder::instance().getTextures(WARRIOR_P)[0]);
}

void Warrior::handleCollision(TeleportCell& gameObject)
{
	if (!m_onTeleport)
	{
		m_icon.setPosition(gameObject.getOtherPos());
		m_onTeleport = true;
	}
}

void Warrior::handleCollision(Throne& gameObject)
{
	m_icon.setPosition(m_lastPos);
}

void Warrior::handleCollision(Key& gameObject)
{
}

void Warrior::handleCollision(Fire& gameObject)
{
	m_icon.setPosition(m_lastPos);
}

void Warrior::handleCollision(Orc& gameObject)
{
	gameObject.remove();
}

void Warrior::handleCollision(Gate& gameObject)
{
	if (!gameObject.isOpen())
	{
		m_icon.setPosition(m_lastPos);
	}
}