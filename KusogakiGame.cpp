#include "KusogakiGame.h"
#include "Util.h"

KusogakiGame::KusogakiGame(int layernum, const Vector2& pos)
{
	input_ = Input::GetInstance();

	window_.pos = pos;
	window_.width = 420;
	window_.height = 240;

	layer_ = layernum;

	topBar_.width = window_.width;
	topBar_.height = 32 * 3 / 2;
	topBar_.pos = { window_.pos.x, window_.pos.y - (window_.height / 2 + topBar_.height / 2) };

	fullwindow_.width = topBar_.width;
	fullwindow_.height = topBar_.height + window_.height;
	fullwindow_.pos = { topBar_.pos.x,topBar_.pos.y + (window_.height / 2) };
}

KusogakiGame::~KusogakiGame()
{
}

void KusogakiGame::Update()
{

	fullwindow_.pos = { topBar_.pos.x,topBar_.pos.y + (window_.height / 2) };
}

void KusogakiGame::Draw()
{
	// ウィンドウ
	Util::DrawBox(window_.pos, window_.width / 2, window_.height / 2, GetColor(0, 200, 200), true);
	Util::DrawBox(topBar_.pos, topBar_.width / 2, topBar_.height / 2, GetColor(255, 255, 255), true);
}
