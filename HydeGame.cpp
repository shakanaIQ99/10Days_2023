#include "HydeGame.h"
#include "Util.h"
#include "Collision.h"

HydeGame::HydeGame(int layernum, const Vector2& pos)
{
	input_ = Input::GetInstance();

	window_.pos = pos;
	window_.width = 360;
	window_.height = 200;

	layer_ = layernum;

	topBar_.width = window_.width;
	topBar_.height = 32 * 3 / 2;
	topBar_.pos = { window_.pos.x, window_.pos.y - (window_.height / 2 + topBar_.height / 2) };

	hydeObject_.pos = { window_.pos.x + 60.0f,window_.pos.y + 55.0f };
	hydeObject_.width = 140;
	hydeObject_.height = 90;
	player_.pos = { window_.pos.x - 80.0f,window_.pos.y + 75.0f };
	player_.width = 120;
	player_.height = 50;
}

HydeGame::~HydeGame()
{
}

void HydeGame::Init(){
	input_ = Input::GetInstance();

	window_.pos = { WIN_WIDTH / 2,WIN_HEIGHT / 2 };
	window_.width = WIN_WIDTH * 2 / 7;
	window_.height = WIN_HEIGHT * 2 / 7;

	topBar_.width = window_.width;
	topBar_.height = 32 * 3 / 2;
	topBar_.pos = { window_.pos.x, window_.pos.y - (window_.height / 2 + topBar_.height / 2) };

	hydeObject_.pos = { window_.pos.x + 60.0f,window_.pos.y + 55.0f };
	hydeObject_.width = 140;
	hydeObject_.height = 90;
	player_.pos = { window_.pos.x - 60.0f,window_.pos.y + 60.0f };
	player_.width = 120;
	player_.height = 50;
}

void HydeGame::Update(){
	if (input_->GetMouseLeftButton(player_)) {
		player_.pos.x = input_->GetMousePos().x;
	}

	if (Collision::BoxToBoxCollision(player_, hydeObject_, true)) {
		playerColor_ = GetColor(0, 255, 0);
	}
	else {
		playerColor_ = GetColor(0, 0, 255);
	}

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
	// 隠れる場所
	Util::DrawBox(hydeObject_.pos, hydeObject_.width / 2, hydeObject_.height / 2, GetColor(255, 0, 0), false);
	// プレイヤー
	Util::DrawBox(player_.pos, player_.width / 2, player_.height / 2, playerColor_, true);
}
