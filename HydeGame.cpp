#include "HydeGame.h"

void HydeGame::Init()
{
	windowPos_ = { WIN_WIDTH / 2,WIN_HEIGHT / 2 };
	windowSize_ = { WIN_WIDTH * 1 / 5,WIN_HEIGHT * 1 / 5 };
	hydeObjectPos_ = { windowPos_.x + 60.0f,windowPos_.y + 55.0f };
	hydeObjectSize_ = { 70,35 };
	playerPos_ = { windowPos_.x - 60.0f,windowPos_.y + 60.0f };
	playerSize_ = { 60,25 };
}

void HydeGame::Update()
{
}

void HydeGame::Draw()
{
	// ウィンドウ
	Vector2 windowLeftTop = { windowPos_.x - windowSize_.x / 2,windowPos_.y - windowSize_.y / 2 };
	Vector2 windowRightBottom = { windowPos_.x + windowSize_.x / 2,windowPos_.y + windowSize_.y / 2 };
	DrawBox(windowLeftTop.x, windowLeftTop.y, windowRightBottom.x, windowRightBottom.y, GetColor(255, 255, 255), false);
	// 隠れる場所
	Vector2 hydeObjectLeftTop = { hydeObjectPos_.x - hydeObjectSize_.x / 2,hydeObjectPos_.y - hydeObjectSize_.y / 2 };
	Vector2 hydeObjectRightBottom = { hydeObjectPos_.x + hydeObjectSize_.x / 2,hydeObjectPos_.y + hydeObjectSize_.y / 2 };
	DrawBox(hydeObjectLeftTop.x, hydeObjectLeftTop.y, hydeObjectRightBottom.x, hydeObjectRightBottom.y, GetColor(255, 0, 0), false);
	// プレイヤー
	Vector2 playerLeftTop = { playerPos_.x - playerSize_.x / 2,playerPos_.y - playerSize_.y / 2 };
	Vector2 playerRightBottom = { playerPos_.x + playerSize_.x / 2,playerPos_.y + playerSize_.y / 2 };
	DrawBox(playerLeftTop.x, playerLeftTop.y, playerRightBottom.x, playerRightBottom.y, GetColor(0, 0, 255), true);
}
