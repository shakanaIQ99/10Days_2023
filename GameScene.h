#pragma once
#include"DxLib.h"
#include"Daruma.h"

#include "PileEffect.h"
#include "Audience.h"

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

	static const int DarumaNum = 3;

	Daruma daruma[DarumaNum];


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
	int DressCounts[sizeof(Dress)];

	Koma KeepSlot;
	Dress KeepSlotDress;
	bool KeepFlag = false;;

	DressKoma Komalist;

	bool Kyuusai = false;

	bool KyuusaiSet = false;


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

	std::unique_ptr<Audience> audience = nullptr;
	bool KomaCatch = false;
	bool KeepCatch = false;

	double CursorAdd = 0.0;
	double CursorKeep = 0.0;
};

