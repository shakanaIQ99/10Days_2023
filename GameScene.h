#pragma once
#include"DxLib.h"
#include"Daruma.h"

#include "PileEffect.h"

enum struct GameType
{
	TUTORIAL,
	MAIN
};

class GameScene
{
public:

	void Init();

	void Update();

	void Draw();

private:

	Daruma daruma[2];

	Daruma preDaruma;

	void ButtonsDraw();

	void KomaUpdate();

	void KomaSlotUpdate();

	void KeepAction();

	void HammerAction();

	void AddAction(bool keep);


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

	bool KomaCatch = false;
	bool KeepCatch = false;
};

