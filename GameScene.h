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

	void ButtonsDraw();

	void KomaUpdate();


	BoxTransform RedButton;
	BoxTransform GreanButton;
	BoxTransform BlueButton;
	BoxTransform BlackButton;

	BoxTransform AddButton;
	BoxTransform KeepButton;

	BoxTransform Komas[4];

	int ColorCounts[sizeof(Koma)];

	std::vector<Koma> Komalist;

	bool Kyuusai = false;
	

	const int ButtonWidth = 50;
	const int Buttonheight = 20;

	int mouseX, mouseY;

	Vector2 mousePos = { 0,0 };
};

