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

	window_.width = fullwindow_.width;
	window_.height = fullwindow_.height - 48;
	window_.pos = { topBar_.pos.x, topBar_.pos.y + (topBar_.height / 2 + window_.height / 2) };
	fullwindow_.pos = { topBar_.pos.x,topBar_.pos.y + (window_.height / 2) };


	layer_ = layernum;

	gauge_bar.width = 720;
	gauge_frame.width = 720;

	gauge_bar.height = 80;
	gauge_frame.height = 80;

	gauge_bar.pos = window_.pos;
	gauge_frame.pos = window_.pos;
}

HakcerGauge::~HakcerGauge()
{
}

void HakcerGauge::Update()
{
	GameTime::DecreaseTime();




	if (GameTime::GetNowTime() % 30 == 0)
	{
		layer_ = MiniGameManager::GetInstance()->GetMaxLayer() + 1;
	}

	if (Input::GetMouseLeftButton(topBar_) && active_) {
		topBar_.pos = Input::GetMousePos();
		isMove_ = true;
	}
	else
	{
		isMove_ = false;
	}
	window_.pos = { topBar_.pos.x, topBar_.pos.y + (topBar_.height / 2 + window_.height / 2) };

	
	fullwindow_.pos = { topBar_.pos.x,topBar_.pos.y + (window_.height / 2) };
}

void HakcerGauge::Draw()
{
	// ウィンドウ
	Util::DrawBox(window_.pos, window_.width / 2, window_.height / 2, GetColor(0, 0, 0), true);
	Util::DrawBox(topBar_.pos, topBar_.width / 2, topBar_.height / 2, GetColor(255, 255, 255), true);

	DrawBox(gauge_bar.pos.x- gauge_bar.width / 2, gauge_bar.pos.y - gauge_bar.height / 2, gauge_bar.pos.x + (gauge_bar.width*((120-GameTime::GetNowTime())/120)), gauge_bar.pos.y + gauge_bar.height / 2, GetColor(0, 255, 0), true);
	Util::DrawBox(gauge_frame.pos, gauge_frame.width / 2, gauge_frame.height / 2, GetColor(255, 255, 255), false);

	

}
