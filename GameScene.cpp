#include "GameScene.h"
#include"Input.h"
#include"Util.h"
#include"main.h"
#include"GameTime.h"
#include"Score.h"

using namespace Util;


void GameScene::Init()
{
	
}


void GameScene::Update()
{
	
}

void GameScene::Draw()
{
	//タスクバーの表示
	Util::DrawBox({ 640,704 }, 1280, 16, GetColor(255, 255, 255), TRUE);
}

void GameScene::SetTexture()
{
	//リソース読み込み
	
}

