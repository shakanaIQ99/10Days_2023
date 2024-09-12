#include "HelpSunGame.h"
#include "Util.h"

HelpSunGame::HelpSunGame(int layernum, const Vector2& pos)
{
	input_ = Input::GetInstance();

	topBar_.width = 360;
	topBar_.height = 32 * 3 / 2;
	topBar_.pos = pos;

	window_.width = 360;
	window_.height = 200;
	window_.pos = { topBar_.pos.x, topBar_.pos.y + (topBar_.height / 2 + window_.height / 2) };

	sun_.pos = window_.pos;
	sun_.width = 120;
	sun_.height = 120;

	layer_ = layernum;

	for (size_t i = 0; i < CLOUD_NUM; i++)
	{
		nowClouds_[i] = { Util::GetRand(-70.0f,70.0f) ,
			Util::GetRand(-70.0f,70.0f) };
		clouds_[i].pos = { nowClouds_[i].x + window_.pos.x,
			nowClouds_[i].y + window_.pos.y };
		clouds_[i].width = 90;
		clouds_[i].height = 80;
		isClouds_[i] = true;
	}
}

HelpSunGame::~HelpSunGame()
{
}

void HelpSunGame::Update()
{
	for (size_t i = 0; i < CLOUD_NUM; i++)
	{
		if (input_->GetTriggerMouseLeftButton(clouds_[i])) {
			isClouds_[i] = false;
		}
	}

	if (input_->GetMouseLeftButton(topBar_)) {
		topBar_.pos = input_->GetMousePos();
	}

	window_.pos = { topBar_.pos.x, topBar_.pos.y + (topBar_.height / 2 + window_.height / 2) };

	sun_.pos = nowSun_ + window_.pos;
	for (size_t i = 0; i < CLOUD_NUM; i++) {
		clouds_[i].pos = nowClouds_[i] + window_.pos;
	}
}

void HelpSunGame::Draw()
{
	// ウィンドウ
	Util::DrawBox(window_.pos, window_.width / 2, window_.height / 2, GetColor(200, 0, 200), true);
	Util::DrawBox(topBar_.pos, topBar_.width / 2, topBar_.height / 2, GetColor(255, 255, 255), true);
	Util::DrawBox(sun_.pos, sun_.width / 2, sun_.height / 2, GetColor(255, 0, 0), true);
	for (size_t i = 0; i < CLOUD_NUM; i++)
	{
		if (isClouds_[i]) {
			Util::DrawBox(clouds_[i].pos, clouds_[i].width / 2, clouds_[i].height / 2, GetColor(150, 150, 150), true);
		}
	}
}
