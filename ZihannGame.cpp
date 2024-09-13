#include "ZihannGame.h"

ZihannGame::ZihannGame(int layernum, const Vector2& pos)
{
	input_ = Input::GetInstance();

	layer_ = layernum;

	topBar_.width = 420;
	topBar_.height = 32 * 3 / 2;
	topBar_.pos = pos;

	window_.width = 420;
	window_.height = 240;
	window_.pos = { topBar_.pos.x, topBar_.pos.y + (topBar_.height / 2 + window_.height / 2) };
}

ZihannGame::~ZihannGame()
{
}

void ZihannGame::Update()
{
}

void ZihannGame::Draw()
{
}
