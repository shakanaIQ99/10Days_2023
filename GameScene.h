#pragma once
#include"DxLib.h"
#include"Daruma.h"

#include "PileEffect.h"

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

	

	BoxTransform AddButton;
	BoxTransform KeepButton;

	BoxTransform Komas[4];
	BoxTransform KeepKoma;

	int ColorCounts[sizeof(Koma)];

	Koma KeepSlot;
	bool KeepFlag = false;;

	std::vector<Koma> Komalist;

	bool Kyuusai = false;
	

	const int ButtonWidth = 50;
	const int Buttonheight = 20;

	int mouseX, mouseY;

	Vector2 mousePos = { 0,0 };

	// 重ね演出
	std::unique_ptr<PileEffect> pileEffect = nullptr;

	//リソース用変数
	int backGroundGame;
	int pedestal;

	bool Komacatch = false;
};

