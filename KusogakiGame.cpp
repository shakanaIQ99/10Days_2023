#include "KusogakiGame.h"
#include "Util.h"

void KusogakiGame::Init()
{
	input_ = Input::GetInstance();

	window_.pos = { WIN_WIDTH * 2 / 3,WIN_HEIGHT * 2 / 3 };
	window_.width = WIN_WIDTH * 1 / 3;
	window_.height = WIN_HEIGHT * 1 / 3;

	testBox.pos = { WIN_WIDTH * 1 / 3,WIN_HEIGHT * 1 / 3 };
	testBox.width = WIN_WIDTH * 2 / 7;
	testBox.height = WIN_HEIGHT * 2 / 7;
}

void KusogakiGame::Update()
{
}

void KusogakiGame::Draw()
{
	// �E�B���h�E
	Util::DrawBox(window_.pos, window_.width / 2, window_.height / 2, GetColor(255, 255, 255), false);
	Util::DrawBox(testBox.pos, testBox.width / 2, testBox.height / 2, GetColor(255, 255, 255), false);
}
