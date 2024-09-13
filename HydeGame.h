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
	void DragAct();
	void TableCollision();

private:
	Input* input_ = nullptr;
	BoxTransform hydeObject_;
	Vector2 nowHydeObject_;
	BoxTransform player_;
	Vector2 nowPlayer_;
	int playerColor_;
};

