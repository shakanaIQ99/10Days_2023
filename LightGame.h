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
	void DragAct();

private:
	Input* input_ = nullptr;

	BoxTransform tip_;
	Vector2 nowTip_;
	bool isTip_ = false;

	bool isLightChange = false;

	int lightCount = 0;

	int lightColor=0;

	int BackTexture_;
	int LightTexture_;
	int TipTexture_;
};

