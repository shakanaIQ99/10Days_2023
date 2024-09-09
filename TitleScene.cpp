#include "TitleScene.h"
#include "Util.h"
#include"Input.h"
#include"Score.h"
#include "main.h"


void TitleScene::SetTexture()
{
	hacker = DxLib::LoadGraph(L"Resources/backGround/hacker.png");
}

void TitleScene::Init()
{

	Score::Reset();

}

void TitleScene::Update()
{
	drawHacker = true;
}

void TitleScene::Draw()
{
	if (drawHacker)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
		DxLib::DrawGraph(0, 0, hacker, TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	}
}

void TitleScene::Reset()
{

}
