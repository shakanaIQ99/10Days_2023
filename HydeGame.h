#pragma once
#include "BaseGame.h"

class HydeGame : public BaseGame
{
public:
	void Init() override;
	void Update() override;
	void Draw() override;

private:
	Vector2 hydeObjectPos_ = {0,0};
	Vector2 hydeObjectSize_ = { 0,0 };
	Vector2 playerPos_ = { 0,0 };
	Vector2 playerSize_ = { 0,0 };
};

