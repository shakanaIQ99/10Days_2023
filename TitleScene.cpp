#include "TitleScene.h"
#include "Util.h"
#include"Input.h"
#include"Score.h"
#include "main.h"


void TitleScene::SetTexture()
{

	//リソース読み込み
	BackGroundTexture = LoadGraph(L"Resources/backGround/desktop.png");
	exeTexture= LoadGraph(L"Resources/Startexe.png");
}

void TitleScene::Init()
{

	Score::Reset();
	startExe.pos = { 200,200 };
	startExe.width = 100;
	startExe.height = 100;

}

void TitleScene::Update()
{
	if (doubleClick)
	{
		doubleClickTimer++;
	}
	if (doubleClickTimer >= 30)
	{
		doubleClick = false;
		doubleClickTimer = 0;
	}

	if (Input::GetTriggerMouseLeftButton(startExe) && doubleClick)
	{
		openExe = true;
	}

	if (Input::GetTriggerMouseLeftButton(startExe))
	{
		doubleClick = true;
	}
	



}

void TitleScene::Draw()
{

	DrawGraph(0, 0, BackGroundTexture, true);
	Util::DrawRotaGraph3(startExe.pos, 1, 1, 0, exeTexture, true);
	if (Input::GetMouseHitBox(startExe))
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
		DrawBox(startExe.pos.x - startExe.width / 2, startExe.pos.y+10 - startExe.height / 2, startExe.pos.x + startExe.width / 2, startExe.pos.y + 10 + startExe.height / 2, GetColor(200, 200, 200), true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
	DrawFormatString(startExe.pos.x-35, startExe.pos.y+40, GetColor(255, 255, 255), L"Game.exe");
	//タスクバーの表示
	Util::DrawBox({ 640,704 }, 1280, 16, GetColor(255, 255, 255), TRUE);
}

void TitleScene::Reset()
{
	openExe = false;
}
