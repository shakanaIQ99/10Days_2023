#include "ResultScene.h"
#include"DxLib.h"
#include"Util.h"
#include"Easing.h"
#include"main.h"



void ResultScene::SetTexture()
{
	HaikeiGHandle= LoadGraph(L"Resources/Scene/game.png");
}

void ResultScene::Init()
{
	sceneNum = 0;
	resultScore = 0;
	timer = 0;
}

void ResultScene::Update()
{
	if (sceneNum == 0)
	{
		resultScore = (int)easeOutQuint(0, (double)Score::GetScore(), (double)timer, 120.0);
		timer++;
	}
	if (sceneNum == 1)
	{

	}

	if (timer >= 120)
	{
		timer = 120;
	}
}

void ResultScene::Draw()
{

	DrawGraph(0, 0, HaikeiGHandle, true);

	DrawFormatString(WIN_WIDTH / 2, WIN_HEIGHT / 4, GetColor(255, 255, 255), L"score:%d", resultScore);


}
