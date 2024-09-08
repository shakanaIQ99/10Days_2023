#pragma once
#include "BaseGame.h"
#include "Input.h"

class LightGame : public BaseGame
{
public:
	void Init() override;
	void Update() override;
	void Draw() override;

private:
	Input* input_ = nullptr;

	BoxTransform tip_;

	bool isLightChange = false;

	int lightCount = 0;

	int lightColor;
};

