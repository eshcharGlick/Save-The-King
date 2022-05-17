#include "GameObject.h"
#include <fstream>
#include <ostream>
#include <iostream>

GameObject::GameObject(const sf::Texture& icon, const sf::Vector2f& scale, int i, int j, int size)
{
	m_icon.setTexture(icon);
	m_icon.scale(scale);
	this->setSpritePos(i, j, size);
}

GameObject::~GameObject()
{
}

sf::Sprite GameObject::draw() const
{
	return m_icon;
}

void GameObject::setSpritePos(int i, int j, int size)
{
	m_icon.setPosition((float)(j * size), (float)((i * size) + GAP));
}

sf::FloatRect GameObject::getGlobalBounds() const
{
	return m_icon.getGlobalBounds();
}

bool GameObject::checkCollision(const sf::FloatRect& rec) const
{
	return m_icon.getGlobalBounds().intersects(rec);;
}
