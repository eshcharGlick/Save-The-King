#pragma once
#include "MovingObject.h"

class Dwarf : public MovingObject
{
public:
	Dwarf(const sf::Vector2f& scale, int i, int j, int size);
	virtual ~Dwarf() {}

	virtual void choose(bool state);
	virtual void move(float deltaTime);

	virtual void handleCollision(MovingObject& gameObject) override;

	virtual void handleCollision(Throne& gameObject)override;
	virtual void handleCollision(Key& gameObject)override;
	virtual void handleCollision(Fire& gameObject)override;
	virtual void handleCollision(Orc& gameObject)override;
	virtual void handleCollision(Gate& gameObject)override;
	virtual void handleCollision(TeleportCell& gameObject)override;
	virtual void notOnTeleport();

	virtual void handleCollision(GiftMoreTime& gameObject)override;
	virtual void handleCollision(GiftLessTime& gameObject)override;
	virtual void handleCollision(GiftAddDwarf& gameObject)override;
	virtual void handleCollision(GiftRemoveDwarf& gameObject)override;

private:
	int m_direction;
};
