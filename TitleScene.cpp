#include "TitleScene.h"
#include "Util.h"
#include"Input.h"
#include"Score.h"
#include "main.h"


void TitleScene::SetTexture()
{

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
	//タスクバーの表示
	Util::DrawBox({ 640,704 }, 1280, 16, GetColor(255, 255, 255), TRUE);
}

void TitleScene::Reset()
{

}
