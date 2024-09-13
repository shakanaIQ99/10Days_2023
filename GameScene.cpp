#include "GameScene.h"
#include"Input.h"
#include"Util.h"
#include"main.h"
#include"GameTime.h"
#include"Score.h"
#include "HydeGame.h"
#include "LightGame.h"
#include "HelpSunGame.h"
#include "KusogakiGame.h"
#include"MiniGameManager.h"

using namespace Util;


void GameScene::Init()
{
	MiniGameManager::Clear();
	endFlag = false;
}


void GameScene::Update()
{
	switch (makeGameNum)
	{
	case 0:
		MiniGameManager::CreateHackerGauge(makeGameNum, { WIN_WIDTH / 2,WIN_HEIGHT / 7 });
		break;
	case 5:
		MiniGameManager::CreateHydeGame(makeGameNum, { Util::GetRand(300.0f,900.0f),Util::GetRand(100.0f,500.0f) });
		break;
	case 10:
		MiniGameManager::CreateLightGame(makeGameNum, { Util::GetRand(300.0f,900.0f),Util::GetRand(100.0f,500.0f) });
		break;
	case 15:
		MiniGameManager::CreateHelpSunGame(makeGameNum, { Util::GetRand(300.0f,900.0f),Util::GetRand(100.0f,500.0f) });
		break;
	case 20:
		MiniGameManager::CreateHydeGame(makeGameNum, { Util::GetRand(300.0f,900.0f),Util::GetRand(100.0f,500.0f) });
		break;
	case 25:
		MiniGameManager::CreateHydeGame(makeGameNum, { Util::GetRand(300.0f,900.0f),Util::GetRand(100.0f,500.0f) });
		break;
	case 30:
		MiniGameManager::CreateHydeGame(makeGameNum, { Util::GetRand(300.0f,900.0f),Util::GetRand(100.0f,500.0f) });
		break;
	case 35:
		MiniGameManager::CreateHydeGame(makeGameNum, { Util::GetRand(300.0f,900.0f),Util::GetRand(100.0f,500.0f) });
		break;
	case 40:
		MiniGameManager::CreateSetumei(makeGameNum, { WIN_WIDTH / 6 + WIN_WIDTH / 2,WIN_HEIGHT / 7 - 50 });
		endFlag = true;

		break;
	}
	if (makeGameNum < 41)
	{
		makeGameNum++;
	}
}

void GameScene::Reset()
{
	MiniGameManager::Clear();
	endFlag = false;
}

void GameScene::Draw()
{
	DrawGraph(0, 0, BackGroundTexture, true);
	MiniGameManager::ManageMiniGames();
	//タスクバーの表示
	Util::DrawBox({ 640,704 }, 1280, 16, GetColor(255, 255, 255), TRUE);

}

void GameScene::SetTexture()
{
	//リソース読み込み
	BackGroundTexture = LoadGraph(L"Resources/backGround/desktop.png");

	
}

