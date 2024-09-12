#include "KusogakiGame.h"
#include "Util.h"

KusogakiGame::KusogakiGame(int layernum, const Vector2& pos)
{
	input_ = Input::GetInstance();

	layer_ = layernum;

	topBar_.width = 420;
	topBar_.height = 32 * 3 / 2;
	topBar_.pos = pos;

	window_.width = 420;
	window_.height = 240;
	window_.pos = { topBar_.pos.x, topBar_.pos.y + (topBar_.height / 2 + window_.height / 2) };

	nowPanels_[0] = { -window_.width * 1.0f / 4.0f,0 };
	nowPanels_[1] = { 0,0 };
	nowPanels_[2] = { window_.width * 1.0f / 4.0f,0 };

	for (size_t i = 0; i < 3; i++) {
		panels_[i].pos = nowPanels_[i] + window_.pos;
		panels_[i].width = 50;
		panels_[i].height = 100;
		isPanels_[i] = false;
	}

	nowButtons_[0] = { nowPanels_[0].x,nowPanels_[0].y - 48 };
	nowButtons_[1] = { nowPanels_[1].x,nowPanels_[1].y - 48 };
	nowButtons_[2] = { nowPanels_[2].x,nowPanels_[2].y - 48 };

	nowButtons_[3] = { nowPanels_[0].x,nowPanels_[0].y + 48 };
	nowButtons_[4] = { nowPanels_[1].x,nowPanels_[1].y + 48 };
	nowButtons_[5] = { nowPanels_[2].x,nowPanels_[2].y + 48 };

	for (size_t i = 0; i < 6; i++) {
		buttons_[i].pos = nowButtons_[i] + window_.pos;
		buttons_[i].width = 32;
		buttons_[i].height = 32;
		buttonColors_[i] = GetColor(255, 255, 255);
	}
}

KusogakiGame::~KusogakiGame()
{
}

void KusogakiGame::Update()
{
	for (size_t i = 0; i < 6; i++) {
		if (input_->GetTriggerMouseLeftButton(buttons_[i])) {
			buttonColors_[i] = GetColor(255, 0, 0);
		}
	}

	if (input_->GetMouseLeftButton(topBar_)) {
		topBar_.pos = input_->GetMousePos();
	}

	window_.pos = { topBar_.pos.x, topBar_.pos.y + (topBar_.height / 2 + window_.height / 2) };
	for (size_t i = 0; i < 3; i++) {
		panels_[i].pos = nowPanels_[i] + window_.pos;
	}

	for (size_t i = 0; i < 6; i++) {
		buttons_[i].pos = nowButtons_[i] + window_.pos;
	}
}

void KusogakiGame::Draw()
{
	// ウィンドウ
	Util::DrawBox(window_.pos, window_.width / 2, window_.height / 2, GetColor(0, 200, 200), true);
	Util::DrawBox(topBar_.pos, topBar_.width / 2, topBar_.height / 2, GetColor(255, 255, 255), true);

	// パネル
	for (size_t i = 0; i < 3; i++) {
		Util::DrawBox(panels_[i].pos, panels_[i].width, panels_[i].height, GetColor(200, 200, 200), true);
	}

	// ボタン
	for (size_t i = 0; i < 6; i++) {
		Util::DrawBox(buttons_[i].pos, buttons_[i].width, buttons_[i].height, buttonColors_[i], true);
	}
}
