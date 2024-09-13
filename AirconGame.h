#pragma once
#include "BaseGame.h"
#include "Input.h"
#include <array>

class AirconGame : public BaseGame
{
public:
	AirconGame(int layernum, const Vector2& pos);
	~AirconGame();
	void Update() override;
	void Draw() override;

private:
	void DragAct();
	void ClickAct();

private:
	Input* input_ = nullptr;

	BoxTransform aircon_;
	Vector2 nowAircon_;

	BoxTransform remocon_;
	Vector2 nowRemocon_;

	BoxTransform temperatureNum_;
	BoxTransform upButton_;
	BoxTransform downButton_;

	int temperature_ = 0;

	int upButtonColor_;
	int downButtonColor_;

	int NumGhandle_[10];
};

