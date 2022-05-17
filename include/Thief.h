#pragma once
#include "Player.h"
#include "Key.h"
#include "TeleportCell.h"

class Thief : public Player
{
public:

	Thief(const sf::Vector2f & scale, int i, int j, int size);
	virtual ~Thief() {}
	void choose(bool state) override;

	bool haveKey();
	bool peekKey();
	
	virtual void handleCollision(TeleportCell& gameObject) override;
	virtual void handleCollision(Throne& gameObject)override;
	virtual void handleCollision(Key& gameObject)override;
	virtual void handleCollision(Fire& gameObject)override;
	virtual void handleCollision(Orc& gameObject)override;
	virtual void handleCollision(Gate& gameObject)override;

private:
	
	bool m_haveKey = false;

};