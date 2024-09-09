#include "HelpSunGame.h"
#include "Util.h"

void HelpSunGame::Init()
{
	input_ = Input::GetInstance();

	window_.pos = { WIN_WIDTH / 2,WIN_HEIGHT / 2 };
	window_.width = WIN_WIDTH * 1 / 3;
	window_.height = WIN_HEIGHT * 1 / 3;

	sun_.pos = window_.pos;
	sun_.width = 120;
	sun_.height = 120;

	for (size_t i = 0; i < CLOUD_NUM; i++)
	{
		clouds_[i].pos = { sun_.pos.x + Util::GetRand(-sun_.width / 2,sun_.width / 2),
			sun_.pos.y + Util::GetRand(-sun_.height / 2,sun_.height / 2) };
		clouds_[i].width = Util::GetRand(50.0f, 100.0f);
		clouds_[i].height = clouds_[i].width - 10.0f;
		isClouds_[i] = true;
	}
}

void HelpSunGame::Update()
{
	for (size_t i = 0; i < CLOUD_NUM; i++)
	{
		if (input_->GetTriggerMouseLeftButton(clouds_[i])) {
			isClouds_[i] = false;
		}
	}
}

void HelpSunGame::Draw()
{
	// ウィンドウ
	Util::DrawBox(window_.pos, window_.width / 2, window_.height / 2, GetColor(255, 255, 255), false);
	Util::DrawBox(sun_.pos, sun_.width / 2, sun_.height / 2, GetColor(255, 0, 0), true);
	for (size_t i = 0; i < CLOUD_NUM; i++)
	{
		if (isClouds_[i]) {
			Util::DrawBox(clouds_[i].pos, clouds_[i].width / 2, clouds_[i].height / 2, GetColor(150, 150, 150), true);
		}
	}
}
