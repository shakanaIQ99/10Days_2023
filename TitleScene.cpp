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


}

void TitleScene::Draw()
{
	DxLib::DrawGraph(0,0,hacker,TRUE);
}

void TitleScene::Reset()
{

}
