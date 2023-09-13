#include "GameScene.h"
#include"Input.h"
#include"Util.h"
#include"main.h"
#include"GameTime.h"
#include"Score.h"

using namespace Util;

int GameScene::backGroundGame;
int GameScene::pedestal;
int GameScene::frame[3];

void GameScene::Init()
{
	daruma[0].Init(Vector2(WIN_WIDTH / 4, 470.0f));
    daruma[1].Init(Vector2((WIN_WIDTH / 4 )*3, 470.0f));

    daruma[2].Init(Vector2((WIN_WIDTH / 2), 470.0f),true);

	clickSE = LoadSoundMem(L"Resources/Music/click.mp3");
	getSE = LoadSoundMem(L"Resources/Music/get.mp3");
	putSE = LoadSoundMem(L"Resources/Music/put.mp3");

    for (int i = 0; i < DarumaNum; i++)
    {
        daruma[i].Order();
    }

	for (int i = 0; i < 3; i++)
	{
		Komas[i + 1].pos = { ((float)WIN_WIDTH / 2.0f) + 160 + 160 * i,((float)WIN_HEIGHT / 6.0f) * 4.7f };
		Komas[i + 1].width = ButtonWidth;
		Komas[i + 1].height = Buttonheight;
	}

	AddButton.pos = { (float)WIN_WIDTH / 2.0f,((float)WIN_HEIGHT / 8.0f) * 7.0f };
	AddButton.width = 60;
	AddButton.height = 60;

	KeepButton.pos = { (float)WIN_WIDTH / 4.0f,((float)WIN_HEIGHT / 8.0f) * 7.0f };
	KeepButton.width = 60;
	KeepButton.height = 60;

	railButton.pos = { (float)WIN_WIDTH / 1.26f,((float)WIN_HEIGHT / 8.0f) * 7.6f };
	railButton.width = 60;
	railButton.height = 60;

	Komas[0].pos = AddButton.pos;
	Komas[0].width = ButtonWidth;
	Komas[0].height = Buttonheight;

	KeepKoma.pos = KeepButton.pos;
	KeepKoma.width = ButtonWidth;
	KeepKoma.height = Buttonheight;
    
    pileEffect.reset(PileEffect::Create());
    Komalist.koma.clear();
    Komalist.huku.clear();

	for (int colorCounts : ColorCounts)
	{
		colorCounts = 0;
	}

	audience.reset(Audience::Create());

    GameTime::Reset();
  
    Kyuusai = false;
	preDress = Dress::BOOTS;
	KomaSlotUpdate();

	light.reset(Light::Create());

	countDown.reset(CountDown::Create());

	isGameStart = false;
}


void GameScene::Update()
{
	CursorAdd = 0.0;
	CursorKeep = 0.0;
	Kyuusai = true;

	countDown->Update();

	if (countDown->GetIsStart())
	{
		isGameStart = true;
	}

	if (Komacatch || Input::GetMouseHitBox(AddButton) || Input::GetMouseHitBox(KeepButton))
	{
		Input::SetChengeCursor(false);
	}
	else
	{
		Input::SetChengeCursor(true);
	}

	KomaSlotUpdate();

	if (isGameStart)
	{
		if (Input::GetMouseHitBox(AddButton) && !Komacatch)CursorAdd = 0.3;
		if (Input::GetMouseHitBox(KeepButton) && !Komacatch)CursorKeep = 0.3;
		GameTime::DecreaseTime();
		KomaUpdate();

		for (int i = 0; i < DarumaNum; i++)
		{
			daruma[i].SetCatchOn(Komacatch);
			daruma[i].Update();
		}

		pileEffect->Update();

		audience->Update();
	}

	light->Update();
}

void GameScene::Draw()
{
    DrawGraph(0, 0, backGroundGame, TRUE);
    DrawRotaGraph3(Vector2(WIN_WIDTH / 4, 530.0f), 1.0, 1.0, 0, pedestal);
    DrawRotaGraph3(Vector2(WIN_WIDTH / 2, 530.0f), 1.0, 1.0, 0, pedestal);
    DrawRotaGraph3(Vector2((WIN_WIDTH/4)*3, 530.0f), 1.0, 1.0, 0, pedestal);

	light->Draw();

	audience->Draw();

    for (int i = 0; i < DarumaNum; i++)
    {
	    daruma[i].Draw();

	}
	ButtonsDraw();

	pileEffect->Draw();

	int scrNum = GameTime::GetNowTime();
	int i = 0;

	while (i < 3)
	{
		Vector2 pos = { 300.0f, 250.0f };
		pos.x = pos.x - (32 * (i - 1));
		int j = scrNum % 10;
		if(i==2)
		{
			j = GameTime::GetNowTime() / 60;
			pos.x -= 10.0f;
		}
		if (i == 1)
		{
			int pretime = GameTime::GetNowTime();
			
			if (pretime <= 60)
			{
				pretime = GameTime::GetNowTime() + 60;
			}
			if (GameTime::GetNowTime() == 120|| GameTime::GetNowTime() == 60)
			{
				pretime = 60;
			}
			j = (pretime -60) / 10;
		}
		DrawGraph(pos.x, pos.y, Score::GetNumGHandle(j), true);
		scrNum /= 10.0f;
		i++;
	}


    Score::Draw();

	countDown->Draw();

}

void GameScene::SetTexture()
{
	//ÉäÉ\Å[ÉXì«Ç›çûÇ›
	backGroundGame = LoadGraph(L"Resources/Scene/game.png");
	pedestal = LoadGraph(L"Resources/Scene/pedestal.png");

	frame[0] = LoadGraph(L"Resources/Frame/mainFrame.png");
	frame[1] = LoadGraph(L"Resources/Frame/subFrame.png");
	frame[2] = LoadGraph(L"Resources/Frame/railFrame.png");
}


void GameScene::ButtonsDraw()
{
	DrawRotaGraph3(AddButton.pos, 1.8, 1.9, 0, frame[0]);
	DrawRotaGraph3(KeepButton.pos, 2, 2, 0, frame[1]);
	DrawRotaGraph3(railButton.pos, 2.0, 1.3, 0, frame[2]);

	int floar = 0;
	for (auto itr = Komalist.koma.begin(); itr != Komalist.koma.end(); itr++)
	{
		if (floar == 0)
		{
			DrawRotaGraph3(Komas[floar].pos, 1.6 + CursorAdd, 1.6 + CursorAdd, 0, Daruma::GetKomaColor(*itr));
		}
		else
		{
			Vector2 prePos = Komas[floar].pos;
			prePos.y += 80.0f;

			DrawRotaGraph3(prePos, 1.6, 1.6, 0, Daruma::GetKomaColor(*itr));
		}
		floar++;
	}
	int Dressfloar = 0;
	for (auto itr = Komalist.huku.begin(); itr != Komalist.huku.end(); itr++)
	{
		if (Dressfloar == 0)
		{
			DrawRotaGraph3(Komas[Dressfloar].pos, 1.6 + CursorAdd, 1.6 + CursorAdd, 0, Daruma::GetDress(*itr));
		}
		else
		{
			Vector2 prePos = Komas[Dressfloar].pos;
			prePos.y += 80.0f;

			DrawRotaGraph3(prePos, 1.6, 1.6, 0, Daruma::GetDress(*itr));
		}
		Dressfloar++;
	}
	if (KeepFlag)
	{
		DrawRotaGraph3(KeepKoma.pos, 1.6 + CursorKeep, 1.6 + CursorKeep, 0, Daruma::GetKomaColor(KeepSlot));
		DrawRotaGraph3(KeepKoma.pos, 1.6 + CursorKeep, 1.6 + CursorKeep, 0, Daruma::GetDress(KeepSlotDress));
	}
}

void GameScene::KomaUpdate()
{
	if (Input::GetTriggerMouseLeftButton(AddButton))
	{
		KomaCatch = true;
		Komacatch = true;

		PlaySoundMem(getSE, DX_PLAYTYPE_BACK);

	}
	if (Input::GetTriggerMouseLeftButton(KeepButton) && KeepFlag)
	{
		KeepCatch = true;
		Komacatch = true;

		PlaySoundMem(getSE, DX_PLAYTYPE_BACK);
	}
	if (KomaCatch)
	{
		Komas[0].pos = Input::GetMousePos();
		if (Input::GetReleaseMouseLeft())
		{
			AddAction(KeepCatch);
			KeepAction();
			Komas[0].pos = AddButton.pos;
			KomaCatch = false;
			Komacatch = false;

			PlaySoundMem(putSE, DX_PLAYTYPE_BACK);
		}
	}
	if (KeepCatch)
	{
		KeepKoma.pos = Input::GetMousePos();
		if (Input::GetReleaseMouseLeft())
		{
			AddAction(KeepCatch);
			KeepKoma.pos = KeepButton.pos;
			KeepCatch = false;
			Komacatch = false;

			PlaySoundMem(putSE, DX_PLAYTYPE_BACK);
		}
	}

	HammerAction();
}

void GameScene::KomaSlotUpdate()
{
	Dress AddDress;

	while(Komalist.koma.size() < 4)
    {
        Koma AddKoma = static_cast<Koma>(GetRand(0, sizeof(Koma) - 1));
		do
		{
			AddDress = static_cast<Dress>(GetRand(0, sizeof(Dress) - 1));
		} while (preDress == AddDress);
		
		preDress = AddDress;
       
        if (Kyuusai)
        {
            for (int i = 0; i < sizeof(Koma); i++)
            {
                for (auto itr = Komalist.koma.begin(); itr != Komalist.koma.end(); itr++)
                {
                    KyuusaiSet = true;
                    if (*itr == static_cast<Koma>(i))
                    {
                        KyuusaiSet = false;
                        break;
                    }
                }
                if (KyuusaiSet)
                {
                    Komalist.koma.push_back(static_cast<Koma>(i));
                    Komalist.huku.push_back(AddDress);
                    break;
                }

            }

        }
        
        if (!Kyuusai)
        {
            Komalist.koma.push_back(AddKoma);
            Komalist.huku.push_back(AddDress);
        }

    }
   
}

void GameScene::KeepAction()
{
	if (Input::GetMouseHitBox(KeepButton))
	{
		Koma preKoma = KeepSlot;
		Dress preDress = KeepSlotDress;

		KeepSlot = Komalist.koma.front();
		KeepSlotDress = Komalist.huku.front();

		Komalist.koma.erase(Komalist.koma.begin());
		Komalist.huku.erase(Komalist.huku.begin());
		if (KeepFlag)
		{
			Komalist.koma.insert(Komalist.koma.begin(), preKoma);
			Komalist.huku.insert(Komalist.huku.begin(), preDress);
		}
		KeepFlag = true;

	}
	else
	{
		KeepKoma.pos = KeepButton.pos;
	}
}

void GameScene::HammerAction()
{
    for (int i = 0; i < DarumaNum; i++)
    {
        if (Input::GetTriggerMouseLeftButton(daruma[i].GetKomaTransform()))
        {
			PlaySoundMem(clickSE, DX_PLAYTYPE_BACK);

            if (daruma[i].GetBeKoma())
            {
                daruma[i].ClickRemoveKoma();
                pileEffect->SlapSet(daruma[i].GetKomaTransform().pos);
            }
        }
        if (Input::GetTriggerMouseLeftButton(daruma[i].GetHead()))
        {

			PlaySoundMem(clickSE, DX_PLAYTYPE_BACK);

            if (!daruma[i].GetMode())
            {
                GameTime::LossTime(5);
                daruma[i].SlapEffect();
                daruma[i].Order();
            }
        }
    }
    
}

void GameScene::AddAction(bool keep)
{
    for (int i = 0; i < DarumaNum; i++)
    {
        if (Input::GetMouseHitBox(daruma[i].GetDragAndDropArea()))
        {
            if (!daruma[i].MaxKoma())
            {
                if (keep)
                {
                    daruma[i].ClickAddKoma(KeepSlot);
                    daruma[i].ClickAddDress(KeepSlotDress);
                    KeepFlag = false;
                }
                else
                {
                    daruma[i].ClickAddKoma(Komalist.koma.front());
                    daruma[i].ClickAddDress(Komalist.huku.front());
                    Komalist.koma.erase(Komalist.koma.begin());
                    Komalist.huku.erase(Komalist.huku.begin());
                }
                
                for (size_t j = 0; j < 2; j++)
                {
                    pileEffect->PileSet(daruma[i].GetKomaTransform().pos,
                        { (float)daruma[i].GetKomaTransform().width, (float)daruma[i].GetKomaTransform().height });
                }
            }

		}
		else
		{
			if (keep)
			{
				KeepKoma.pos = KeepButton.pos;
			}
		}
	}
}
