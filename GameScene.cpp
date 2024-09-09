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
	MiniGameManager::CreateHydeGame();
	MiniGameManager::CreateLightGame();
}


void GameScene::Update()
{
	
}

void GameScene::Draw()
{
	MiniGameManager::ManageMiniGames();
}

void GameScene::SetTexture()
{
	//リソース読み込み
	
}

