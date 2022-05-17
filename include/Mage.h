#pragma once
#include "Player.h"
#include "Fire.h"

class Mage : public Player
{
public:
	Mage(const sf::Vector2f & scale, int i, int j, int size);
	virtual ~Mage () {}
	void choose(bool state) override;

	virtual void handleCollision(TeleportCell& gameObject) override;
	virtual void handleCollision(Throne& gameObject)override;
	virtual void handleCollision(Key& gameObject)override;
	virtual void handleCollision(Fire& gameObject)override;
	virtual void handleCollision(Orc& gameObject)override;
	virtual void handleCollision(Gate& gameObject)override;

private:

};