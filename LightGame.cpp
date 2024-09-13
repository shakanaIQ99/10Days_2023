#include "LightGame.h"
#include "Util.h"

LightGame::LightGame(int layernum, const Vector2& pos)
{
	input_ = Input::GetInstance();

	topBar_.width = 420;
	topBar_.height = 32 * 3 / 2;
	topBar_.pos = pos;

	window_.width = 420;
	window_.height = 240;
	window_.pos = { topBar_.pos.x, topBar_.pos.y + (topBar_.height / 2 + window_.height / 2) };

	fullwindow_.width = topBar_.width;
	fullwindow_.height = topBar_.height + window_.height;
	fullwindow_.pos = { topBar_.pos.x,topBar_.pos.y + (window_.height / 2) };

	layer_ = layernum;

	nowTip_ = { 0,0 };
	tip_.pos = nowTip_ + window_.pos;
	tip_.width = 36;
	tip_.height = 36;

	isLightChange = false;

	lightCount = 0;
	lightColor = 0;
}

LightGame::~LightGame()
{
}

void LightGame::Update()
{
	DragAct();

	switch (lightCount)
	{
	case 0:
		lightColor = GetColor(0, 0, 0);
		break;
	case 1:
		lightColor = GetColor(255, 165, 0);
		break;
	case 2:
		lightColor = GetColor(255, 255, 255);
		break;
	default:
		break;
	}

	if (lightCount >= 2) {
		end_ = true;
	}
}

void LightGame::Draw()
{
	// ウィンドウ
	Util::DrawBox(window_.pos, window_.width / 2, window_.height / 2, GetColor(200, 200, 200), true);
	Util::DrawBox(topBar_.pos, topBar_.width / 2, topBar_.height / 2, GetColor(255, 255, 255), true);
	Util::DrawBox(topBar_.pos, topBar_.width / 2, topBar_.height / 2, GetColor(0, 0, 0), false);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 50);
	// 暗転状態
	Util::DrawBox(window_.pos, window_.width / 2, window_.height / 2, lightColor, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	// 紐
	DxLib::DrawLine((int)window_.pos.x, (int)window_.pos.y - (int)window_.height / 2,
		(int)tip_.pos.x, (int)tip_.pos.y - (int)tip_.height / 2,
		GetColor(255, 255, 255));
	// 先っちょ
	Util::DrawBox(tip_.pos, tip_.width / 2, tip_.height / 2, GetColor(255, 255, 255), false);
}

void LightGame::DragAct()
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

	if (nowTip_.y < 0) {
		nowTip_.y = 0;
	}
	else if (nowTip_.y >= 100)
	{
		lightCount++;
		isTip_ = false;
		nowTip_.y = 0;
	}
	else {
		if (input_->GetTriggerMouseLeftButton(tip_) && active_) {
			isTip_ = true;
		}
		else if (input_->GetReleaseMouseLeft()) {
			isTip_ = false;
		}

		if (isTip_) {
			nowTip_.y = input_->GetMousePos().y - window_.pos.y;
		}
	}

	window_.pos = { topBar_.pos.x, topBar_.pos.y + (topBar_.height / 2 + window_.height / 2) };
	tip_.pos = nowTip_ + window_.pos;
}
