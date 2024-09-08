#pragma once
#include "Vector2.h"

class BaseGame
{
public:
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

protected:
	int layer_ = 0;
};