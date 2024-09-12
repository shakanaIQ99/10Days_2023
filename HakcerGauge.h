#pragma once
#include "BaseGame.h"
#include "GameTime.h"
class HakcerGauge : public BaseGame
{
public:
	HakcerGauge(int layernum, const Vector2& pos);
	~HakcerGauge();
	void Update() override;
	void Draw() override;

private:


	BoxTransform gauge_bar;
	BoxTransform gauge_frame;

};

