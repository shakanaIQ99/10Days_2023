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
	warningExeTexture = LoadGraph(L"Resources/warningExe.png");
	zikkouTexture = LoadGraph(L"Resources/execute.png");
}

void TitleScene::Init()
{

	Score::Reset();
	startExe.pos = { 200,200 };
	startExe.width = 100;
	startExe.height = 100;
	warningpos = { WIN_WIDTH / 2,WIN_HEIGHT / 2 };

	zikkou.width = 180;
	zikkou.height = 106;
	zikkou.pos = { (552 + 336) / 2-16,(478 + 372) / 2 };

	zikkou2.width = 180;
	zikkou2.height = 106;
	zikkou2.pos = { (924 + 740) / 2,zikkou.pos.y };

	scale = 2.0;
	scale2 = 2.0;

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

	switch (titlefasa)
	{
	case EXEFPHASE:
		if (Input::GetTriggerMouseLeftButton(startExe) && doubleClick)
		{
			titlefasa = Titlefase::WARNINGFPHASE;
		}

		if (Input::GetTriggerMouseLeftButton(startExe))
		{
			doubleClick = true;
		}
		break;
	case WARNINGFPHASE:

		if (Input::GetTriggerMouseLeftButton(zikkou) || Input::GetTriggerMouseLeftButton(zikkou2))
		{
			openExe = true;
		}

		if (Input::GetMouseHitBox(zikkou))
		{
			scale = 2.2;
		}
		else
		{
			scale = 2.0;
		}
		if (Input::GetMouseHitBox(zikkou2))
		{
			scale2 = 2.2;
		}
		else
		{
			scale2 = 2.0;
		}


		
		break;
	}
	
	



}

void TitleScene::Draw()
{

	DrawGraph(0, 0, BackGroundTexture, true);
	Util::DrawRotaGraph3(startExe.pos, 1, 1, 0, exeTexture, true);
	if (Input::GetMouseHitBox(startExe)&&titlefasa==Titlefase::EXEFPHASE)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
		DrawBox(startExe.pos.x - startExe.width / 2, startExe.pos.y+10 - startExe.height / 2, startExe.pos.x + startExe.width / 2, startExe.pos.y + 10 + startExe.height / 2, GetColor(200, 200, 200), true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
	DrawFormatString(startExe.pos.x-35, startExe.pos.y+40, GetColor(255, 255, 255), L"Game.exe");

	if (titlefasa == Titlefase::WARNINGFPHASE)
	{
		Util::DrawRotaGraph3(warningpos, 2, 2, 0, warningExeTexture, true);
		Util::DrawRotaGraph3(zikkou.pos, scale, scale, 0, zikkouTexture, true);
		Util::DrawRotaGraph3(zikkou2.pos, scale2, scale2, 0, zikkouTexture, true);
	}
	//タスクバーの表示
	Util::DrawBox({ 640,704 }, 1280, 16, GetColor(255, 255, 255), TRUE);
}

void TitleScene::Reset()
{
	openExe = false;
}
