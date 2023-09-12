#include "GameScene.h"
#include"Input.h"
#include"Util.h"
#include"main.h"
#include"GameTime.h"

using namespace Util;

void GameScene::Init()
{
	daruma[0].Init(Vector2(WIN_WIDTH / 4, 470.0f));
    daruma[1].Init(Vector2((WIN_WIDTH / 4 )*3, 470.0f));

    daruma[2].Init(Vector2((WIN_WIDTH / 2), 470.0f),true);

    for (int i = 0; i < DarumaNum; i++)
    {
        daruma[i].Order();
    }

    //ƒŠƒ\[ƒX“Ç‚Ýž‚Ý
    backGroundGame = LoadGraph(L"Resources/Scene/game.png");
    pedestal = LoadGraph(L"Resources/Scene/pedestal.png");

   
    for (int i = 0; i < 3; i++)
    {
        Komas[i + 1].pos = { ((float)WIN_WIDTH / 2.0f)+160+160*i,((float)WIN_HEIGHT / 6.0f) * 5.0f };
        Komas[i + 1].width = ButtonWidth;
        Komas[i + 1].height = Buttonheight;
    }

    AddButton.pos = {(float)WIN_WIDTH/2.0f,((float)WIN_HEIGHT/8.0f)*7.0f};
    AddButton.width = 60;
    AddButton.height = 60;

    KeepButton.pos = { (float)WIN_WIDTH / 4.0f,((float)WIN_HEIGHT / 8.0f) * 7.0f };
    KeepButton.width = 60;
    KeepButton.height = 60;

    Komas[0].pos = AddButton.pos;
    Komas[0].width = ButtonWidth;
    Komas[0].height = Buttonheight;

    KeepKoma.pos = KeepButton.pos;
    KeepKoma.width = ButtonWidth;
    KeepKoma.height = Buttonheight;

   
    
    pileEffect.reset(PileEffect::Create());
    Komalist.koma.clear();

    for (int colorCounts: ColorCounts)
    {
        colorCounts = 0;
    }

    audience.reset(Audience::Create());

    GameTime::Reset();
  
}


void GameScene::Update()
{
    CursorAdd = 0.0;
    CursorKeep = 0.0;

    if (Komacatch || Input::GetMouseHitBox(AddButton) || Input::GetMouseHitBox(KeepButton))
    {
        Input::SetChengeCursor(false);
    }
    else
    {
        Input::SetChengeCursor(true);
    }

    if (Input::GetMouseHitBox(AddButton)&&!Komacatch)CursorAdd = 0.3;
    if (Input::GetMouseHitBox(KeepButton)&& !Komacatch)CursorKeep = 0.3;
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

void GameScene::Draw()
{
    DrawGraph(0, 0, backGroundGame, TRUE);
    DrawRotaGraph3(Vector2(WIN_WIDTH / 4, 530.0f), 1.0, 1.0, 0, pedestal);
    DrawRotaGraph3(Vector2(WIN_WIDTH / 2, 530.0f), 1.0, 1.0, 0, pedestal);
    DrawRotaGraph3(Vector2((WIN_WIDTH/4)*3, 530.0f), 1.0, 1.0, 0, pedestal);
    //DrawGraph(780, 450, pedestal, TRUE);

    audience->Draw();

    for (int i = 0; i < DarumaNum; i++)
    {
	    daruma[i].Draw();

    }
    ButtonsDraw();

    pileEffect->Draw();

    DrawFormatString(WIN_WIDTH/2-20, WIN_HEIGHT / 2, GetColor(255, 255, 255), L"Time:%d", GameTime::GetNowTime());
}


void GameScene::ButtonsDraw()
{

    DrawBox(AddButton.pos, AddButton.width, AddButton.height, GetColor(255, 255, 0), false);
    DrawBox(KeepButton.pos, KeepButton.width, KeepButton.height, GetColor(0, 255, 255), false);
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
   
    KomaSlotUpdate();

    if (Input::GetTriggerMouseLeftButton(AddButton))
    {
        KomaCatch = true;
        Komacatch = true;
    }
    if (Input::GetTriggerMouseLeftButton(KeepButton)&&KeepFlag)
    {
        KeepCatch = true;
        Komacatch = true;
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
           

        }
    }

    HammerAction();

   
   
}

void GameScene::KomaSlotUpdate()
{
    if (Komalist.koma.size() < 4)
    {
        Koma AddKoma = static_cast<Koma>(GetRand(0, sizeof(Koma) - 1));
        Dress AddDress = static_cast<Dress>(GetRand(0, sizeof(Dress) - 1));
        Kyuusai = false;
        switch (AddKoma)
        {
        case Koma::RED:
            ColorCounts[static_cast<int>(Koma::RED)] = 0;
            break;
        case Koma::BLUE:
            ColorCounts[static_cast<int>(Koma::BLUE)] = 0;
            break;
        case Koma::GREEN:
            ColorCounts[static_cast<int>(Koma::GREEN)] = 0;
            break;
        case Koma::YELLOW:
            ColorCounts[static_cast<int>(Koma::YELLOW)] = 0;
            break;
        }
        for (int i = 0; i < sizeof(Koma); i++)
        {
            ColorCounts[i]++;
            if (ColorCounts[i] > 4)
            {
                Kyuusai = true;
                Komalist.koma.push_back(static_cast<Koma>(i));
                Komalist.huku.push_back(AddDress);
                ColorCounts[i] = 0;
                break;
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
            if (daruma[i].GetBeKoma())
            {
                daruma[i].ClickRemoveKoma();
                pileEffect->SlapSet(daruma[i].GetKomaTransform().pos);
            }
        }
        if (Input::GetTriggerMouseLeftButton(daruma[i].GetHead()))
        {
            if (daruma[i].GetMode())
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
