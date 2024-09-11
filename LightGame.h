#pragma once
#include "BaseGame.h"
#include "Input.h"

class LightGame : public BaseGame
{
public:
	LightGame(int layernum, const Vector2& pos);
	 ~LightGame();
	void Update() override;
	void Draw() override;

private:
	Input* input_ = nullptr;

	BoxTransform tip_;

	bool isLightChange = false;

	int lightCount = 0;

	int lightColor=0;
};

