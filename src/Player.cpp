#pragma once
#include "Player.h"

bool Player::m_lessTime = false;
bool Player::m_moreTime = false;
bool Player::m_removeDwarf = false;

Player::Player(const sf::Texture& icon, const sf::Vector2f & scale , int i, int j , int size)
	:MovingObject(icon, scale,i,j,size)
{
}

Player::~Player()
{
}

void Player::choose(bool state)
{
}

void Player::move(float deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		m_icon.move(-deltaTime * SPEED, 0.f);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		m_icon.move(deltaTime * SPEED, 0.f);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		m_icon.move(0.f, -deltaTime * SPEED);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		m_icon.move(0.f ,deltaTime * SPEED);

	if (outOfRange())
		m_icon.setPosition(m_lastPos);
}

void Player::handleCollision(MovingObject& gameObject)
{
	if (&gameObject == this)
		return;

	m_icon.setPosition(m_lastPos);
	if (dynamic_cast <Dwarf*>(&gameObject))
		gameObject.handleCollision(*this);
}

void Player::notOnTeleport()
{
	m_onTeleport = false;
}

void Player::handleCollision(GiftMoreTime& gameObject)
{
	m_moreTime = true;
	gameObject.remove();
}

void Player::handleCollision(GiftLessTime& gameObject)
{
	m_lessTime = true;
	gameObject.remove();
}

void Player::handleCollision(GiftAddDwarf& gameObject)
{
	m_icon.setPosition(m_lastPos);
	gameObject.remove();
}

void Player::handleCollision(GiftRemoveDwarf& gameObject)
{
	m_removeDwarf = true;
	gameObject.remove();
}

bool Player::moreTime()
{
	if (m_moreTime)
	{
		m_moreTime = false;
		return true;
	}
	return false;
}

bool Player::lessTime()
{
	if (m_lessTime)
	{
		m_lessTime = false;
		return true;
	}
	return false;
}

bool Player::removeDwarf()
{
	if (m_removeDwarf)
	{
		m_removeDwarf = false;
		return true;
	}
	return false;
}