#include "ZihannGame.h"
#include "Util.h"

ZihannGame::ZihannGame(int layernum, const Vector2& pos)
{
	input_ = Input::GetInstance();

	layer_ = layernum;

	topBar_.width = 480;
	topBar_.height = 32 * 3 / 2;
	topBar_.pos = pos;

	window_.width = 480;
	window_.height = 240;
	window_.pos = { topBar_.pos.x, topBar_.pos.y + (topBar_.height / 2 + window_.height / 2) };

	fullwindow_.width = topBar_.width;
	fullwindow_.height = topBar_.height + window_.height;
	fullwindow_.pos = { topBar_.pos.x,topBar_.pos.y + (window_.height / 2) };

	nowZihannki_ = { 0,0 };
	zihannki_.pos = nowZihannki_ + window_.pos;
	zihannki_.width = 200;
	zihannki_.height = 240;

	zihannkiBottom_.pos = { zihannki_.pos.x, zihannki_.pos.y + 30 };
	zihannkiBottom_.width = 200;
	zihannkiBottom_.height = 100;

	nowCoin_ = { 50,-50 };
	coin_.pos = nowCoin_ + window_.pos;
	coin_.width = 50;
	coin_.height = 50;

	//リソース読み込み
	ZihannTexture_ = LoadGraph(L"Resources/miniGame/item/center.png");
	ZihannRightTexture_ = LoadGraph(L"Resources/miniGame/item/right.png");
	ZihannLeftTexture_ = LoadGraph(L"Resources/miniGame/item/left.png");
	CoinTexture_ = LoadGraph(L"Resources/miniGame/item/coin.png");
	ZihannBottom_ = LoadGraph(L"Resources/miniGame/item/under.png");
}

ZihannGame::~ZihannGame()
{
}

void ZihannGame::Update()
{
	DragAct();

	ClickAct();
}

void ZihannGame::Draw()
{
	// ウィンドウ
	Util::DrawBox(window_.pos, window_.width / 2, window_.height / 2, GetColor(200, 200, 200), true);
	Util::DrawBox(topBar_.pos, topBar_.width / 2, topBar_.height / 2, GetColor(255, 255, 255), true);
	Util::DrawBox(topBar_.pos, topBar_.width / 2, topBar_.height / 2, GetColor(0, 0, 0), false);

	switch (phase_)
	{
	case ZihannGame::ZihannMae:
		// 自販機
		DrawRotaGraph(zihannki_.pos.x - zihannki_.width * 4 / 5, zihannki_.pos.y, 1.0f, 0, ZihannLeftTexture_, true);

		DrawRotaGraph(zihannki_.pos.x + zihannki_.width * 4 / 5, zihannki_.pos.y, 1.0f, 0, ZihannRightTexture_, true);

		DrawRotaGraph(zihannki_.pos.x, zihannki_.pos.y, 1.0f, 0, ZihannTexture_, true);
		break;
	case ZihannGame::ZihannSita:
		DrawGraph(window_.pos.x - window_.width / 2, window_.pos.y - window_.height / 2, ZihannBottom_, true);
		DrawGraph(coin_.pos.x - coin_.width / 2, coin_.pos.y - coin_.height / 2, CoinTexture_, true);
		break;
	default:
		break;
	}
}

void ZihannGame::DragAct()
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
	zihannki_.pos = nowZihannki_ + window_.pos;
	zihannkiBottom_.pos = { zihannki_.pos.x, zihannki_.pos.y + 70 };
	coin_.pos = nowCoin_ + window_.pos;

	fullwindow_.pos = { topBar_.pos.x,topBar_.pos.y + (window_.height / 2) };
}

void ZihannGame::ClickAct()
{
	switch (phase_)
	{
	case ZihannGame::ZihannMae:
		if (input_->GetTriggerMouseLeftButton(zihannkiBottom_) && active_) {
			phase_ = ZihannSita;
		}
		break;
	case ZihannGame::ZihannSita:
		if (input_->GetTriggerMouseLeftButton(coin_) && active_) {
			end_ = true;
		}
		break;
	default:
		break;
	}
}
