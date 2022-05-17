#pragma once
#include "Mage.h"

Mage::Mage(const sf::Vector2f & scale, int i, int j, int size)
	:Player(TextureHolder::instance().getTextures(MAGE_P)[0], scale, i, j, size)
{
}

void Mage::choose(bool state)
{
	if (state)
		m_icon.setTexture(TextureHolder::instance().getTextures(MAGE_P)[1]);
	else
		m_icon.setTexture(TextureHolder::instance().getTextures(MAGE_P)[0]);
}

void Mage::handleCollision(TeleportCell& gameObject)
{

}

void Mage::handleCollision(Throne& gameObject)
{
	m_icon.setPosition(m_lastPos);
}

void Mage::handleCollision(Key& gameObject)
{
}

void Mage::handleCollision(Fire& gameObject)
{
	gameObject.remove();
}

void Mage::handleCollision(Orc& gameObject)
{
	m_icon.setPosition(m_lastPos);
}

void Mage::handleCollision(Gate& gameObject)
{
	if (!gameObject.isOpen())
	{
		m_icon.setPosition(m_lastPos);
	}
}
