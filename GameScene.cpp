#include "GameScene.h"
#include"Input.h"

void GameScene::Init()
{
	daruma.Init();
}

void GameScene::Update()
{
	Input::InputUpdate();
	daruma.Update();

}

void GameScene::Draw()
{
	daruma.Draw();
}
