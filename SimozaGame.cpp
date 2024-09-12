#include "SimozaGame.h"
#include "Util.h"

SimozaGame::SimozaGame(int layernum, const Vector2& pos)
{
	input_ = Input::GetInstance();

	topBar_.width = 360;
	topBar_.height = 32 * 3 / 2;
	topBar_.pos = pos;

	window_.width = 360;
	window_.height = 200;
	window_.pos = { topBar_.pos.x, topBar_.pos.y + (topBar_.height / 2 + window_.height / 2) };

	layer_ = layernum;

	nowKamiza_ = { 0,-window_.height * 1.0f / 3.0f };
	kamiza_.pos = { nowKamiza_.x + window_.pos.x,nowKamiza_.y + window_.pos.y };
	kamiza_.width = 200;
	kamiza_.height = 50;

	nowTable_ = { 0,0 };
	table_.pos = nowTable_ + window_.pos;
	table_.width = 200;
	table_.height = 70;
}

SimozaGame::~SimozaGame()
{
}

void SimozaGame::Update()
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
	kamiza_.pos = nowKamiza_ + window_.pos;
	table_.pos = nowTable_ + window_.pos;
}

void SimozaGame::Draw()
{
	// ウィンドウ
	Util::DrawBox(window_.pos, window_.width / 2, window_.height / 2, GetColor(200, 0, 0), true);
	Util::DrawBox(topBar_.pos, topBar_.width / 2, topBar_.height / 2, GetColor(255, 255, 255), true);
	Util::DrawBox(topBar_.pos, topBar_.width / 2, topBar_.height / 2, GetColor(0, 0, 0), false);

	// 上座
	Util::DrawBox(kamiza_.pos, kamiza_.width / 2, kamiza_.height / 2, GetColor(0, 0, 200), true);

	// テーブル
	Util::DrawBox(table_.pos, table_.width / 2, table_.height / 2, GetColor(0, 200, 0), true);

	// 下座

}
