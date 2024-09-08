#pragma once
#include "BaseGame.h"
#include "Input.h"

class HydeGame : public BaseGame
{
public:
	void Init() override;
	void Update() override;
	void Draw() override;

private:
	Input* input_ = nullptr;
	BoxTransform hydeObject_;
	BoxTransform player_;
	int playerColor_;
};

