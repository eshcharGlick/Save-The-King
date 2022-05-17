#pragma once
#include "Player.h"
#include "Orc.h"
#include "TeleportCell.h"

class Warrior : public Player
{
public:
	Warrior(const sf::Vector2f & scale, int i, int j, int size);
	virtual ~Warrior() {}
	void choose(bool state) override;

	virtual void handleCollision(TeleportCell& gameObject) override;
	virtual void handleCollision(Throne& gameObject)override;
	virtual void handleCollision(Key& gameObject)override;
	virtual void handleCollision(Fire& gameObject)override;
	virtual void handleCollision(Orc& gameObject)override;
	virtual void handleCollision(Gate& gameObject)override;

private:

};