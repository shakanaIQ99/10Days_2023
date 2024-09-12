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
}


void GameScene::Update()
{
	
}

void GameScene::Draw()
{
	DrawGraph(0, 0, BackGroundTexture, true);
	MiniGameManager::ManageMiniGames();

}

void GameScene::SetTexture()
{
	//リソース読み込み
	BackGroundTexture = LoadGraph(L"Resources/backGround/desktop.png");
	
}

