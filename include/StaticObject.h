#pragma once
#include "GameObject.h"
#include "MovingObject.h"

class StaticObject : public GameObject
{
public:
	StaticObject(const sf::Texture& icon, const sf::Vector2f& scale, int i, int j, int size);
	virtual ~StaticObject();

	virtual void handleCollision(MovingObject& gameObject) = 0;

	virtual void handleCollision(Throne& gameObject);
	virtual void handleCollision(Key& gameObject);
	virtual void handleCollision(Fire& gameObject);
	virtual void handleCollision(Wall& gameObject);
	virtual void handleCollision(Orc& gameObject);
	virtual void handleCollision(Gate& gameObject);
	virtual void handleCollision(TeleportCell& gameObject);
	virtual void handleCollision(GiftMoreTime& gameObject)override;
	virtual void handleCollision(GiftLessTime& gameObject)override;
	virtual void handleCollision(GiftAddDwarf& gameObject)override;
	virtual void handleCollision(GiftRemoveDwarf& gameObject)override;

	void remove();
	bool isExsit();

protected:
	bool m_exsit = true;

private:
	
};
