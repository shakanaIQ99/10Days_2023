#include "LightGame.h"
#include "Util.h"

void LightGame::Init()
{
	input_ = Input::GetInstance();

	window_.pos = { WIN_WIDTH / 2,WIN_HEIGHT / 2 };
	window_.width = WIN_WIDTH * 1 / 3;
	window_.height = WIN_HEIGHT * 1 / 3;

	tip_.pos = { window_.pos };
	tip_.width = 12;
	tip_.height = 12;

	isLightChange = false;

	lightCount = 0;
}

void LightGame::Update()
{
	if (input_->GetMouseLeftButton(tip_)) {
		tip_.pos.y = input_->GetMousePos().y;
	}

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

	if (tip_.pos.y <= window_.pos.y)
	{
		isLightChange = false;
		tip_.pos.y = window_.pos.y;
	}

	if (tip_.pos.y >= window_.pos.y + 20)
	{
		if (!isLightChange) {
			isLightChange = true;
			lightCount++;
		}
		tip_.pos.y = window_.pos.y;
	}
}

void LightGame::Draw()
{
	// ウィンドウ
	Util::DrawBox(window_.pos, window_.width / 2, window_.height / 2, GetColor(255, 255, 255), false);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 50);
	// 暗転状態
	Util::DrawBox(window_.pos, window_.width / 2, window_.height / 2, lightColor, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	// 紐
	DxLib::DrawLine(window_.pos.x, window_.pos.y - window_.height / 2,
		tip_.pos.x, tip_.pos.y - tip_.height / 2,
		GetColor(255, 255, 255));
	// 先っちょ
	Util::DrawBox(tip_.pos, tip_.width / 2, tip_.height / 2, GetColor(255, 255, 255), false);
}
