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
	MiniGameManager::CreateHydeGame(0);
	MiniGameManager::CreateLightGame(1);
	MiniGameManager::CreateHelpSunGame(2);
	MiniGameManager::CreateKusogakiGame(3);
	MiniGameManager::CreateHackerGauge(4, { WIN_WIDTH / 2,WIN_HEIGHT / 7 });
}


void GameScene::Update()
{
	
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

