#pragma once
#include "DxLib.h"
#include <list>
#include <memory>
#include "BaseGame.h"

//ミニゲームども
#include"LightGame.h"
#include"HydeGame.h"
#include"KusogakiGame.h"
#include"HelpSunGame.h"
#include"HakcerGauge.h"
#include"SetumeiTextFile.h"
#include"SimozaGame.h"
#include"ZihannGame.h"
#include"AirconGame.h"
//

using namespace std;


class MiniGameManager
{
public:


	MiniGameManager();

	static MiniGameManager* GetInstance();


	static void CreateLightGame(int LayerNum, const Vector2& pos = { (WIN_WIDTH / 2)-50,WIN_HEIGHT / 2 });
	static void CreateHydeGame(int LayerNum, const Vector2& pos = { (WIN_WIDTH / 2)+50,WIN_HEIGHT / 2 });
	static void CreateHelpSunGame(int LayerNum, const Vector2& pos = { WIN_WIDTH / 2,(WIN_HEIGHT / 2)+50 });
	static void CreateKusogakiGame(int LayerNum, const Vector2& pos = { WIN_WIDTH / 2,(WIN_HEIGHT / 2) - 50 });
	static void CreateSimozaGame(int LayerNum, const Vector2& pos = { WIN_WIDTH / 2 - 50,(WIN_HEIGHT / 2) - 50 });
	static void CreateZihannGame(int LayerNum, const Vector2& pos = { WIN_WIDTH / 2 - 50,(WIN_HEIGHT / 2) - 100 });
	static void CreateHackerGauge(int LayerNum, const Vector2& pos = { WIN_WIDTH / 2,(WIN_HEIGHT / 2) - 50 });
	static void CreateSetumei(int LayerNum, const Vector2& pos = { WIN_WIDTH / 2,(WIN_HEIGHT / 2) - 50 });


	static void ManageMiniGames();
	static const int GetMaxLayer() { return GetInstance()->Maxlayer; };
	static void Clear();

	static const std::list<std::unique_ptr<BaseGame>>& GetGameList() { return GetInstance()->gameList; };

private:
	void Initialize();
	static list<unique_ptr<BaseGame>> gameList;
	int Maxlayer;
	//bool comp(const unique_ptr<BaseGame> lo, const unique_ptr<BaseGame> ro);

};