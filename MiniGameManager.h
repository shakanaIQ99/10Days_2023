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

	static void CreateLightGame(Vector2 pos);
	static void CreateHydeGame(Vector2 pos);


	static void ManageMiniGames();
	static void Clear();

	static const std::list<std::unique_ptr<BaseGame>>& GetGameList() { return GetInstance()->gameList; };

private:
	void Initialize();
	static list<unique_ptr<BaseGame>> gameList;


};