#include "HakcerGauge.h"
#include "Util.h"
#include "Input.h"
#include "MiniGameManager.h"

HakcerGauge::HakcerGauge(int layernum, const Vector2& pos)
{
	fullwindow_.width = 960;
	fullwindow_.height = 540;

	topBar_.width = fullwindow_.width;
	topBar_.height = 48;
	topBar_.pos = pos;

	defaulutpos = pos;

	window_.width = fullwindow_.width;
	window_.height = fullwindow_.height - 48;
	window_.pos = { topBar_.pos.x, topBar_.pos.y + (topBar_.height / 2 + window_.height / 2) };
	fullwindow_.pos = { topBar_.pos.x,topBar_.pos.y + (window_.height / 2) };


	layer_ = layernum;

	dokuroPos = window_.pos;
	dokuroPos.y -= 100;

	gauge_bar.width = 720;
	gauge_frame.width = 720;

	gauge_bar.height = 80;
	gauge_frame.height = 80;

	gauge_bar.pos = { window_.pos.x,window_.pos.y+50 };
	gauge_frame.pos = gauge_bar.pos;
	textpos = { window_.pos.x,window_.pos.y + 150 };

	LoadDivGraph(L"Resources/hackerMark.png", 2, 2, 1, 320, 320, HackerDokuro);
	HackedText = LoadGraph(L"Resources/hacked.png");

}

HakcerGauge::~HakcerGauge()
{
}

void HakcerGauge::Update()
{
	GameTime::DecreaseTime();




	if (GameTime::GetNowTime() % 15 == 0)
	{
		layer_ = MiniGameManager::GetInstance()->GetMaxLayer() + 1;
		changeface = true;
		dokuromove = 10;
		topBar_.pos = defaulutpos;

	}

	if (changeface)
	{
		changetime++;
		if (changetime % 5 == 0)
		{
			dokuromove = dokuromove * -1;
		}

	}
	if (changetime > 60)
	{
		changeface = false;
		changetime = 0;
		dokuromove = 0;
	}
	if (Input::GetTriggerMouseLeftButton(topBar_) && active_) {

		isMove_ = true;
	}
	else if (Input::GetReleaseMouseLeft())
	{
		isMove_ = false;
	}

	if (isMove_)
	{
		topBar_.pos = Input::GetMousePos();
	}
	window_.pos = { topBar_.pos.x, topBar_.pos.y + (topBar_.height / 2 + window_.height / 2) };

	dokuroPos = { window_.pos.x,window_.pos.y - 100 + dokuromove };

	gauge_bar.pos = { window_.pos.x,window_.pos.y + 50 };
	gauge_frame.pos = gauge_bar.pos;
	textpos = { window_.pos.x,window_.pos.y + 150 };
	fullwindow_.pos = { topBar_.pos.x,topBar_.pos.y + (window_.height / 2) };

}

void HakcerGauge::Draw()
{
	// ウィンドウ
	Util::DrawBox(window_.pos, window_.width / 2, window_.height / 2, GetColor(0, 0, 0), true);
	Util::DrawBox(topBar_.pos, topBar_.width / 2, topBar_.height / 2, GetColor(255, 255, 255), true);
	Util::DrawBox(topBar_.pos, topBar_.width / 2, topBar_.height / 2, GetColor(0, 0, 0), false);

	Util::DrawRotaGraph3(dokuroPos,1,1,0,HackerDokuro[(int)changeface]);
	if (GameTime::GetNowTime() % 2 == 0)
	{
		Util::DrawRotaGraph3(textpos, 1, 1, 0, HackedText);
	}
	//Util::DrawRotaGraph3(textpos, 1, 1, 0, HackedText);

	DrawBox(gauge_bar.pos.x- gauge_bar.width / 2, gauge_bar.pos.y - gauge_bar.height / 2, gauge_bar.pos.x - gauge_bar.width / 2 + ((gauge_bar.width/60)*(60-GameTime::GetNowTime())), gauge_bar.pos.y + gauge_bar.height / 2, GetColor(255, 50, 50), true);
	Util::DrawBox(gauge_frame.pos, gauge_frame.width / 2, gauge_frame.height / 2, GetColor(255, 255, 255), false);

	

}
