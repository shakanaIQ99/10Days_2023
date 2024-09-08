#pragma once
#include "Vector2.h"

class BaseGame
{
public:
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	int GetLayer() {
		return layer_;
	}

	bool GetEnd() {
		return end_;
	}

protected:
	int layer_ = 50;
	bool end_ = false;
};