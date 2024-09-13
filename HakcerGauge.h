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

	int HackerDokuro[2];
	int HackedText;

	BoxTransform gauge_bar;
	BoxTransform gauge_frame;

	Vector2 dokuroPos;
	Vector2 textpos;

	Vector2 defaulutpos;

	bool changeface = false;

	int changetime = 0;

	int dokuromove = 0;

	int alpha = 0;

};

