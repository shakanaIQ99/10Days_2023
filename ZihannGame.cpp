#include "ZihannGame.h"
#include "Util.h"

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

	nowZihannki_ = { 0,-20 };
	zihannki_.pos = nowZihannki_ + window_.pos;
	zihannki_.width = 200;
	zihannki_.height = 200;
}

ZihannGame::~ZihannGame()
{
}

void ZihannGame::Update()
{
	DragAct();
}

void ZihannGame::Draw()
{
	// ウィンドウ
	Util::DrawBox(window_.pos, window_.width / 2, window_.height / 2, GetColor(200, 200, 200), true);
	Util::DrawBox(topBar_.pos, topBar_.width / 2, topBar_.height / 2, GetColor(255, 255, 255), true);
	Util::DrawBox(topBar_.pos, topBar_.width / 2, topBar_.height / 2, GetColor(0, 0, 0), false);

	// 自販機
	Util::DrawBox(zihannki_.pos, zihannki_.width / 2, zihannki_.height / 2, GetColor(200, 0, 0), true);
	Util::DrawBox({ zihannki_.pos.x - zihannki_.width * 4 / 5,zihannki_.pos.y },
		zihannki_.width / 4, zihannki_.height / 2, GetColor(0, 200, 0), true);
	Util::DrawBox({ zihannki_.pos.x + zihannki_.width * 4 / 5,zihannki_.pos.y },
		zihannki_.width / 4, zihannki_.height / 2, GetColor(0, 0, 200), true);
}

void ZihannGame::DragAct()
{
	if (input_->GetTriggerMouseLeftButton(topBar_) && active_) {
		isMove_ = true;
	}
	else if (input_->GetReleaseMouseLeft()) {
		isMove_ = false;
	}

	if (isMove_) {
		topBar_.pos = input_->GetMousePos();
	}

	window_.pos = { topBar_.pos.x, topBar_.pos.y + (topBar_.height / 2 + window_.height / 2) };
	zihannki_.pos = nowZihannki_ + window_.pos;
}
