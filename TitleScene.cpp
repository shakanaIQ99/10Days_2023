#include "TitleScene.h"
#include "Util.h"
#include"Input.h"
#include"Score.h"

void TitleScene::SetTexture()
{
	title = DxLib::LoadGraph(L"Resources/Scene/title.png");
}

void TitleScene::Init()
{
	boxPos = { 0,0 };
	color = DxLib::GetColor(0, 0, 0);
	Score::Reset();
	
}

void TitleScene::Update()
{
	alphaNum -= 2;

	Input::SetChengeCursor(true);

	if (alphaNum <= 0)
	{
		alphaNum = 0;
	}
}

void TitleScene::Draw()
{
	DxLib::DrawGraph(0, 0, title, TRUE);

	DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, alphaNum);
	Util::DrawBox(boxPos, width, height, color, true);
	DxLib::SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void TitleScene::Reset()
{
	alphaNum = 255;
}
