#pragma once
#include "BaseGame.h"
#include "Input.h"

class LightGame : public BaseGame
{
public:
	LightGame(const Vector2& pos = { WIN_WIDTH / 2,WIN_HEIGHT / 2 });
	 ~LightGame();
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

