#pragma once
#include "Dwarf.h"

Dwarf::Dwarf(const sf::Vector2f& scale, int i, int j, int size)
	:MovingObject(TextureHolder::instance().getTextures(DWARF_P)[0], scale, i, j, size)
{
}

void Dwarf::choose(bool state)
{
}

void Dwarf::move(float deltaTime)
{
	static float times = 4.f;
	times += deltaTime;

	if (times > 2.f)
	{
		m_direction = (rand() % 4);
		times = 0;
	}
	if (m_direction == 0)
		m_icon.move(-deltaTime * SPEED, 0.f);
	else if (m_direction == 1)
		m_icon.move(deltaTime * SPEED, 0.f);
	else if (m_direction == 2)
		m_icon.move(0.f, -deltaTime * SPEED);
	else if (m_direction == 3)
		m_icon.move(0.f, deltaTime * SPEED);

	if (outOfRange())
		m_icon.setPosition(m_lastPos);
}

void Dwarf::handleCollision(MovingObject& gameObject)
{
	if (&gameObject == this)
		return;

	m_icon.setPosition(m_lastPos);
}

void Dwarf::handleCollision(Throne& gameObject)
{
	m_icon.setPosition(m_lastPos);
}

void Dwarf::handleCollision(Key& gameObject)
{
}

void Dwarf::handleCollision(Fire& gameObject)
{
	m_icon.setPosition(m_lastPos);
}

void Dwarf::handleCollision(Orc& gameObject)
{
	m_icon.setPosition(m_lastPos);
}

void Dwarf::handleCollision(Gate& gameObject)
{
	m_icon.setPosition(m_lastPos);
}

void Dwarf::handleCollision(TeleportCell& gameObject)
{
	m_icon.setPosition(m_lastPos);
}

void Dwarf::notOnTeleport()
{
}

void Dwarf::handleCollision(GiftMoreTime& gameObject)
{
	m_icon.setPosition(m_lastPos);
}

void Dwarf::handleCollision(GiftLessTime& gameObject)
{
	m_icon.setPosition(m_lastPos);
}

void Dwarf::handleCollision(GiftAddDwarf& gameObject)
{
	m_icon.setPosition(m_lastPos);
}

void Dwarf::handleCollision(GiftRemoveDwarf& gameObject)
{
	m_icon.setPosition(m_lastPos);
}
