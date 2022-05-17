#pragma once
#include "StaticObject.h"

class Gift : public StaticObject
{
public:
	Gift(const sf::Vector2f& scale, int i, int j, int size);
	virtual ~Gift() {}

private:

};
