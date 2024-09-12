#include "HydeGame.h"
#include "Util.h"
#include "Collision.h"

HydeGame::HydeGame(int layernum, const Vector2& pos)
{
	input_ = Input::GetInstance();

	topBar_.width = 360;
	topBar_.height = 32 * 3 / 2;
	topBar_.pos = pos;

	window_.width = 360;
	window_.height = 200;
	window_.pos = { topBar_.pos.x, topBar_.pos.y + (topBar_.height / 2 + window_.height / 2) };

	layer_ = layernum;

	nowHydeObject_ = { 60.0f,55.0f };
	hydeObject_.pos = nowHydeObject_ + window_.pos;
	hydeObject_.width = 140;
	hydeObject_.height = 90;

	nowPlayer_ = { -80.0f,75.0f };
	player_.pos = nowPlayer_ + window_.pos;
	player_.width = 120;
	player_.height = 50;
}

HydeGame::~HydeGame()
{
}

void HydeGame::Update(){
	if (input_->GetMouseLeftButton(topBar_)) {
		topBar_.pos = input_->GetMousePos();
	}

	if (input_->GetMouseLeftButton(player_)) {
		nowPlayer_.x = input_->GetMousePos().x - window_.pos.x;
	}

	if (Collision::BoxToBoxCollision(player_, hydeObject_, true)) {
		playerColor_ = GetColor(0, 255, 0);
	}
	else {
		playerColor_ = GetColor(0, 0, 255);
	}

	window_.pos = { topBar_.pos.x, topBar_.pos.y + (topBar_.height / 2 + window_.height / 2) };
	player_.pos = nowPlayer_ + window_.pos;
	hydeObject_.pos = nowHydeObject_ + window_.pos;

	// プレイヤーが画面外に出ないように
	if (player_.pos.x - player_.width / 2 <= window_.pos.x - window_.width / 2){
		player_.pos.x = window_.pos.x - window_.width / 2 + player_.width / 2;
	}
	if (player_.pos.x + player_.width / 2 >= window_.pos.x + window_.width / 2) {
		player_.pos.x = window_.pos.x + window_.width / 2 - player_.width / 2;
	}
}

void HydeGame::Draw(){
	// ウィンドウ
	Util::DrawBox(window_.pos, window_.width / 2, window_.height / 2, GetColor(200, 200, 0), true);
	Util::DrawBox(topBar_.pos, topBar_.width / 2, topBar_.height / 2, GetColor(255, 255, 255), true);
	Util::DrawBox(topBar_.pos, topBar_.width / 2, topBar_.height / 2, GetColor(0, 0, 0), false);
	// 隠れる場所
	Util::DrawBox(hydeObject_.pos, hydeObject_.width / 2, hydeObject_.height / 2, GetColor(255, 0, 0), false);
	// プレイヤー
	Util::DrawBox(player_.pos, player_.width / 2, player_.height / 2, playerColor_, true);
}
