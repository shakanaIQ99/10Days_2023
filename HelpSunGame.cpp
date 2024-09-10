#include "HelpSunGame.h"
#include "Util.h"

HelpSunGame::HelpSunGame(int layernum, const Vector2& pos)
{
	input_ = Input::GetInstance();

	window_.pos = pos;
	window_.width = 360;
	window_.height = 200;

	topBar_.width = window_.width;
	topBar_.height = 32 * 3 / 2;
	topBar_.pos = { window_.pos.x, window_.pos.y - (window_.height / 2 + topBar_.height / 2) };

	sun_.pos = window_.pos;
	sun_.width = 120;
	sun_.height = 120;

	layer_ = layernum;

	for (size_t i = 0; i < CLOUD_NUM; i++)
	{
		clouds_[i].pos = { sun_.pos.x + Util::GetRand(-sun_.width / 2,sun_.width / 2),
			sun_.pos.y + Util::GetRand(-sun_.height / 2,sun_.height / 2) };
		clouds_[i].width = (int)Util::GetRand(50.0f, 100.0f);
		clouds_[i].height = (int)clouds_[i].width - 10;
		isClouds_[i] = true;
	}
}

HelpSunGame::~HelpSunGame()
{
}

void HelpSunGame::Init()
{
	input_ = Input::GetInstance();

	window_.pos = { WIN_WIDTH / 2,WIN_HEIGHT / 2 };
	window_.width = WIN_WIDTH * 2 / 7;
	window_.height = WIN_HEIGHT * 2 / 7;

	topBar_.width = window_.width;
	topBar_.height = 32 * 3/2;
	topBar_.pos = { window_.pos.x, window_.pos.y - (window_.height / 2 + topBar_.height / 2) };

	sun_.pos = window_.pos;
	sun_.width = 120;
	sun_.height = 120;

	for (size_t i = 0; i < CLOUD_NUM; i++)
	{
		clouds_[i].pos = { sun_.pos.x + Util::GetRand(-sun_.width / 2,sun_.width / 2),
			sun_.pos.y + Util::GetRand(-sun_.height / 2,sun_.height / 2) };
		clouds_[i].width = (int)Util::GetRand(50.0f, 100.0f);
		clouds_[i].height = (int)clouds_[i].width - 10;
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
	Util::DrawBox(window_.pos, window_.width / 2, window_.height / 2, GetColor(255, 0, 255), true);
	Util::DrawBox(topBar_.pos, topBar_.width / 2, topBar_.height / 2, GetColor(255, 255, 255), false);
	Util::DrawBox(sun_.pos, sun_.width / 2, sun_.height / 2, GetColor(255, 0, 0), true);
	for (size_t i = 0; i < CLOUD_NUM; i++)
	{
		if (isClouds_[i]) {
			Util::DrawBox(clouds_[i].pos, clouds_[i].width / 2, clouds_[i].height / 2, GetColor(150, 150, 150), true);
		}
	}
}
