#pragma once
#include "StaticObject.h"

class Fire : public StaticObject
{
public:
	Fire(const sf::Vector2f& scale, int i, int j, int size);
	virtual ~Fire() {}

	virtual void handleCollision(MovingObject& gameObject);

private:
	bool m_visible = false;
};
