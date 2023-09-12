#include "TitleScene.h"
#include "Util.h"
#include"Input.h"

void TitleScene::Init()
{
	boxPos = {100,100};
	title = DxLib::LoadGraph(L"Resources/Scene/title.png");
}

void TitleScene::Update()
{
	Input::SetChengeCursor(true);
}

void TitleScene::Draw()
{
	DxLib::DrawGraph(0, 0, title, TRUE);
	Util::DrawBox(boxPos, width, height, DxLib::GetColor(255, 0, 0), true);
}
