#include "ResultScene.h"
#include"DxLib.h"
#include"Util.h"
#include"Easing.h"
#include"main.h"
#include"Input.h"
#include "Ease.h"

void ResultScene::SetTexture()
{
	LoadDivGraph(L"Resources/backGround/gameover.png", 4, 4, 1, 1280, 720, GameOverTexture);
	GameClearTexture = LoadGraph(L"Resources/gameclear/clear.png");
	loserTexture = LoadGraph(L"Resources/gameclear/haker.png");
}

void ResultScene::Init()
{
	gameovercounttimer = 0;
	gameover_flag = false;
	changeScene = false;
}

void ResultScene::Update()
{
	if (gameover_flag)
	{
		gameovercounttimer++;

		if (gameovercounttimer >= frame * 4)
		{
			gameovercounttimer = 0;
		}

		gameovercount = gameovercounttimer / frame;

	}
	else
	{

	}
	
	if (Input::GetTriggerMouseLeft())
	{
		changeScene = true;
	}


}

void ResultScene::Draw()
{
	if(gameover_flag)DrawGraph(0, 0, GameOverTexture[gameovercount], true);
	else
	{
		DrawGraph(0, 0, GameClearTexture, true);
		Util::DrawRotaGraph3({ 160.0f,720.0f - 160.0f }, 1, 1, angle+=0.1f, loserTexture, true);
	}
}

void ResultScene::Reset()
{
	gameovercounttimer = 0;
	changeScene = false;
	gameover_flag = false;
}
