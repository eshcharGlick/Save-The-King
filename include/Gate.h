#pragma once
#include "StaticObject.h"

class Gate : public StaticObject
{
public:
	Gate(const sf::Vector2f& scale, int i, int j, int size);
	virtual ~Gate() {}

	virtual void handleCollision(MovingObject& gameObject);

	bool isOpen();
	void openGate();
private:
	bool m_isOpen = false;
};
