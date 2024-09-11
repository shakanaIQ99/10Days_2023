#include "LightGame.h"
#include "Util.h"

LightGame::LightGame(int layernum, const Vector2& pos)
{
	input_ = Input::GetInstance();

	window_.pos = pos;
	window_.width = 420;
	window_.height = 240;

	layer_ = layernum;

	topBar_.width = window_.width;
	topBar_.height = 32 * 3 / 2;
	topBar_.pos = { window_.pos.x, window_.pos.y - (window_.height / 2 + topBar_.height / 2) };

	tip_.pos = { window_.pos };
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

	if (tip_.pos.y >= window_.pos.y + 100)
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
	Util::DrawBox(window_.pos, window_.width / 2, window_.height / 2, GetColor(200, 200, 200), true);
	Util::DrawBox(topBar_.pos, topBar_.width / 2, topBar_.height / 2, GetColor(255, 255, 255), true);

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
