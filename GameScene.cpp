#include "GameScene.h"
#include"Input.h"
#include"Util.h"
#include"main.h"
#include"GameTime.h"
#include"Score.h"
#include "HydeGame.h"

using namespace Util;


void GameScene::Init()
{
	baseGame_ = std::make_unique<HydeGame>();
	baseGame_->Init();
}

void GameScene::Update()
{
	baseGame_->Update();
}

void GameScene::Draw()
{
	baseGame_->Draw();
}

void GameScene::SetTexture()
{
	//リソース読み込み
	
}

