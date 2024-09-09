#pragma once
#include "DxLib.h"
#include <list>
#include <memory>
#include "BaseGame.h"

//É~ÉjÉQÅ[ÉÄÇ«Ç‡
#include"LightGame.h"
#include"HydeGame.h"


//

using namespace std;


class MiniGameManager
{
public:


	MiniGameManager();

	static MiniGameManager* GetInstance();

	static void CreateLightGame(const Vector2& pos = { WIN_WIDTH / 2,WIN_HEIGHT / 2 });
	static void CreateHydeGame(const Vector2& pos = { (WIN_WIDTH / 2)+50,WIN_HEIGHT / 2 });


	static void ManageMiniGames();
	static void Clear();

	static const std::list<std::unique_ptr<BaseGame>>& GetGameList() { return GetInstance()->gameList; };

private:
	void Initialize();
	static list<unique_ptr<BaseGame>> gameList;

	//bool comp(const unique_ptr<BaseGame> lo, const unique_ptr<BaseGame> ro);

};