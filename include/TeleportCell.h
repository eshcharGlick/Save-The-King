#pragma once
#include "StaticObject.h"


class TeleportCell : public StaticObject
{
public:
	TeleportCell(const sf::Vector2f& scale, int i, int j, int size , char id);
	virtual ~TeleportCell () {}

	int getId();
	sf::Vector2f getOtherPos();
	void setOtherPos(sf::FloatRect rec);

	virtual void handleCollision(MovingObject& gameObject);

private:
	int m_id;
	sf::Vector2f m_otherPos;

};
