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

	fullwindow_.width = topBar_.width;
	fullwindow_.height = topBar_.height + window_.height;
	fullwindow_.pos = { topBar_.pos.x,topBar_.pos.y + (window_.height / 2) };

	layer_ = layernum;

	nowKamiza_ = { 0,-window_.height * 1.0f / 3.0f };
	kamiza_.pos = { nowKamiza_.x + window_.pos.x,nowKamiza_.y + window_.pos.y };
	kamiza_.width = 200;
	kamiza_.height = 50;

	nowTable_ = { 0,0 };
	table_.pos = nowTable_ + window_.pos;
	table_.width = 200;
	table_.height = 70;

	nowSimoza_ = { 0,window_.height * 1.0f / 3.0f };
	simoza_.pos = { nowSimoza_.x + window_.pos.x,nowSimoza_.y + window_.pos.y };
	simoza_.width = 150;
	simoza_.height = 50;

	isSelect_ = false;
	isKamiza_ = false;
	isSimoza_ = false;

	kamizaColor_ = GetColor(0, 0, 200);
	simozaColor_ = GetColor(200, 200, 0);
}

SimozaGame::~SimozaGame()
{
}

void SimozaGame::Update()
{
	DragAct();

	SelectAct();
}

void SimozaGame::Draw()
{
	// ウィンドウ
	Util::DrawBox(window_.pos, window_.width / 2, window_.height / 2, GetColor(200, 0, 0), true);
	Util::DrawBox(topBar_.pos, topBar_.width / 2, topBar_.height / 2, GetColor(255, 255, 255), true);
	Util::DrawBox(topBar_.pos, topBar_.width / 2, topBar_.height / 2, GetColor(0, 0, 0), false);

	// 上座
	Util::DrawBox(kamiza_.pos, kamiza_.width / 2, kamiza_.height / 2, kamizaColor_, true);

	// テーブル
	Util::DrawBox(table_.pos, table_.width / 2, table_.height / 2, GetColor(0, 200, 0), true);

	// 下座
	Util::DrawBox(simoza_.pos, simoza_.width / 2, simoza_.height / 2, simozaColor_, true);
}

void SimozaGame::DragAct()
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
	simoza_.pos = nowSimoza_ + window_.pos;

	fullwindow_.pos = { topBar_.pos.x,topBar_.pos.y + (window_.height / 2) };
}

void SimozaGame::SelectAct()
{
	if (!isSelect_) {
		if (input_->GetTriggerMouseLeftButton(kamiza_) && active_) {
			isSelect_ = true;
			isKamiza_ = true;
		}

		if (input_->GetTriggerMouseLeftButton(simoza_) && active_) {
			isSelect_ = true;
			isSimoza_ = true;
		}
	}

	if (isKamiza_) {
		kamizaColor_ = GetColor(0, 0, 0);
		isKamiza_ = false;
		isSelect_ = false;
	}
	else {
		kamizaColor_ = GetColor(0, 0, 200);
	}

	if (isSimoza_) {
		simozaColor_ = GetColor(0, 0, 0);
		end_ = true;
	}
	else {
		simozaColor_ = GetColor(200, 200, 0);
	}
}
