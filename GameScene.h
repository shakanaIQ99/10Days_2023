#pragma once
#include"DxLib.h"
#include"Daruma.h"

class GameScene
{
public:

	void Init();

	void Update();

	void Draw();

private:

	Daruma daruma;

	bool MouseBoxHit(BoxTransform box, Vector2 mousePos);

	void ButtonsDraw();

	void KomaUpdate();


	BoxTransform RedButton;
	BoxTransform GreanButton;
	BoxTransform BlueButton;
	BoxTransform BlackButton;
	

	const int ButtonWidth = 50;
	const int Buttonheight = 20;

	int mouseX, mouseY;

	Vector2 mousePos = { 0,0 };
};

