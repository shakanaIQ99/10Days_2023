#pragma once
#include "BaseGame.h"
#include "Input.h"

class SimozaGame : public BaseGame
{
public:
	SimozaGame(int layernum, const Vector2& pos);
	~SimozaGame();
	void Update() override;
	void Draw() override;

private:
	Input* input_ = nullptr;

	BoxTransform kamiza_;
	Vector2 nowKamiza_;
	BoxTransform simoza_;
	Vector2 nowSimoza_;
	BoxTransform table_;
	Vector2 nowTable_;
};

