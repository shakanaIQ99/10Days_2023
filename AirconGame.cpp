#include "AirconGame.h"
#include "Util.h"

AirconGame::AirconGame(int layernum, const Vector2& pos)
{
	input_ = Input::GetInstance();

	layer_ = layernum;

	topBar_.width = 420;
	topBar_.height = 32 * 3 / 2;
	topBar_.pos = pos;

	window_.width = 420;
	window_.height = 240;
	window_.pos = { topBar_.pos.x, topBar_.pos.y + (topBar_.height / 2 + window_.height / 2) };

	nowAircon_ = { -105,-60 };
	aircon_.pos = nowAircon_ + window_.pos;
	aircon_.width = 180;
	aircon_.height = 60;

	nowRemocon_ = { 105,30 };
	remocon_.pos = nowRemocon_ + window_.pos;
	remocon_.width = 150;
	remocon_.height = 180;

	temperatureNum_.pos = { remocon_.pos.x, remocon_.pos.y - 40 };
	temperatureNum_.width = 120;
	temperatureNum_.height = 50;

	upButton_.pos = { remocon_.pos.x + 30,remocon_.pos.y + 20 };
	upButton_.width = 50;
	upButton_.height = 50;

	downButton_.pos = { remocon_.pos.x - 30,remocon_.pos.y + 20 };
	downButton_.width = 50;
	downButton_.height = 50;

	LoadDivGraph(L"Resources/Number/number.png", 10, 10, 1, 32, 64, NumGhandle_);
}

AirconGame::~AirconGame()
{
}

void AirconGame::Update()
{
	DragAct();
	ClickAct();
}

void AirconGame::Draw()
{
	// ウィンドウ
	Util::DrawBox(window_.pos, window_.width / 2, window_.height / 2, GetColor(200, 200, 200), true);
	Util::DrawBox(topBar_.pos, topBar_.width / 2, topBar_.height / 2, GetColor(255, 255, 255), true);
	Util::DrawBox(topBar_.pos, topBar_.width / 2, topBar_.height / 2, GetColor(0, 0, 0), false);

	DrawLine(window_.pos.x, window_.pos.y - window_.height / 2,
		window_.pos.x, window_.pos.y + window_.height / 2, GetColor(0, 0, 0), 5);

	Util::DrawBox(aircon_.pos, aircon_.width / 2, aircon_.height / 2, GetColor(0, 0, 0), true);

	Util::DrawBox(remocon_.pos, remocon_.width / 2, remocon_.height / 2, GetColor(0, 0, 0), true);
	Util::DrawBox(temperatureNum_.pos, temperatureNum_.width / 2, temperatureNum_.height / 2, GetColor(150, 150, 150), true);
	Util::DrawBox(upButton_.pos, upButton_.width / 2, upButton_.height / 2, upButtonColor_, true);
	Util::DrawBox(downButton_.pos, downButton_.width / 2, downButton_.height / 2, downButtonColor_, true);
}

void AirconGame::DragAct()
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

	window_.pos = { topBar_.pos.x, topBar_.pos.y + (topBar_.height / 2 + window_.height / 2) };
	aircon_.pos = nowAircon_ + window_.pos;
	remocon_.pos = nowRemocon_ + window_.pos;
	temperatureNum_.pos = { remocon_.pos.x, remocon_.pos.y - 50 };
	upButton_.pos = { remocon_.pos.x + 30,remocon_.pos.y + 20 };
	downButton_.pos = { remocon_.pos.x - 30,remocon_.pos.y + 20 };
}

void AirconGame::ClickAct()
{
	if (input_->GetTriggerMouseLeftButton(upButton_) && active_) {
		upButtonColor_ = GetColor(250, 250, 250);
		temperature_++;
	}
	else {
		upButtonColor_ = GetColor(150, 150, 150);
	}

	if (input_->GetTriggerMouseLeftButton(downButton_) && active_) {
		downButtonColor_ = GetColor(250, 250, 250);
		temperature_--;
	}
	else {
		downButtonColor_ = GetColor(150, 150, 150);
	}
}
