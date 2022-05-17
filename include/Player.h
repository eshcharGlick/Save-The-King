#pragma once
#include "MovingObject.h"
#include "Gate.h"
#include "Gift.h"
#include "Dwarf.h"
#include "GiftMoreTime.h"
#include "GiftLessTime.h"
#include "GiftAddDwarf.h"
#include "GiftRemoveDwarf.h"

class Player : public MovingObject
{
public:
	Player(const sf::Texture& icon, const sf::Vector2f & scale, int i, int j, int size);

	virtual ~Player();
	virtual void choose(bool state);
	void move(float deltaTime) override;
	
	virtual void handleCollision(MovingObject& gameObject) override;
	virtual void handleCollision(TeleportCell& gameObject) = 0;
	virtual void notOnTeleport();
	virtual void handleCollision(GiftMoreTime& gameObject)override;
	virtual void handleCollision(GiftLessTime& gameObject)override;
	virtual void handleCollision(GiftAddDwarf& gameObject)override;
	virtual void handleCollision(GiftRemoveDwarf& gameObject)override;

	static bool moreTime();
	static bool lessTime();
	static bool removeDwarf();

protected:
	bool m_onTeleport;
private:
	static bool m_moreTime;
	static bool m_lessTime;
	static bool m_removeDwarf;

};