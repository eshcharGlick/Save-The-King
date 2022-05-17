#pragma once
#include "Player.h"
#include "TeleportCell.h"

class King : public Player
{
public:
	King(const sf::Vector2f & scale, int i, int j, int size);
	virtual ~King () {}
	void choose(bool state) override;

	virtual void handleCollision(TeleportCell& gameObject) override;
	virtual void handleCollision(Throne& gameObject)override;
	virtual void handleCollision(Key& gameObject)override;
	virtual void handleCollision(Fire& gameObject)override;
	virtual void handleCollision(Orc& gameObject)override;
	virtual void handleCollision(Gate& gameObject)override;
	
	bool win();

private:
	bool m_win = false;
};
