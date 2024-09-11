#pragma once
#include "BaseGame.h"
#include "Input.h"

class HydeGame : public BaseGame
{
public:
	HydeGame(int layernum,const Vector2& pos);
	~HydeGame();
	void Update() override;
	void Draw() override;

private:
	Input* input_ = nullptr;
	BoxTransform hydeObject_;
	BoxTransform player_;
	Vector2 playerMove_;
	int playerColor_;
};

