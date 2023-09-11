#include "GameScene.h"
#include"Input.h"
#include"Util.h"
#include"main.h"
#include"GameTime.h"

using namespace Util;

void GameScene::Init()
{
	daruma[0].Init(Vector2(345.0f, 470.0f));
    daruma[1].Init(Vector2(780.0f+145.0f, 470.0f));
    for (int i = 0; i < 2; i++)
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

    AddButton.pos = {(float)WIN_WIDTH/2.0f,((float)WIN_HEIGHT/6.0f)*5.0f};
    AddButton.width = 60;
    AddButton.height = 60;

    KeepButton.pos = { (float)WIN_WIDTH / 4.0f,((float)WIN_HEIGHT / 6.0f) * 5.0f };
    KeepButton.width = 60;
    KeepButton.height = 60;

    Komas[0].pos = AddButton.pos;
    Komas[0].width = ButtonWidth;
    Komas[0].height = Buttonheight;

    KeepKoma.pos = KeepButton.pos;
    KeepKoma.width = ButtonWidth;
    KeepKoma.height = Buttonheight;

   
    
    pileEffect.reset(PileEffect::Create());
    Komalist.clear();

    for (int colorCounts: ColorCounts)
    {
        colorCounts = 0;
    }

    GameTime::Reset();
  
}


void GameScene::Update()
{
    GameTime::DecreaseTime();
    KomaUpdate();

    pileEffect->Update();
    /*if (KeepFlag)
    {
        
    }*/
    for (int i = 0; i < 2; i++)
    {
	    daruma[i].Update();
    }
}

void GameScene::Draw()
{
    DrawGraph(0, 0, backGroundGame, TRUE);
    DrawGraph(200, 450, pedestal, TRUE);
    DrawGraph(780, 450, pedestal, TRUE);
    for (int i = 0; i < 2; i++)
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
    for (auto itr = Komalist.begin(); itr != Komalist.end(); itr++)
    {
        //DrawBox(Komas[floar].pos, Komas[floar].width, Komas[floar].height, Daruma::GetKomaColor(*itr), true);
        DrawRotaGraph3(Komas[floar].pos, 1.6, 1.6, 0, Daruma::GetKomaColor(*itr));
        floar++;
    }
    if (KeepFlag) DrawRotaGraph3(KeepKoma.pos, 1.6, 1.6, 0, Daruma::GetKomaColor(KeepSlot));
}

void GameScene::KomaUpdate()
{
   
    KomaSlotUpdate();

    if (Input::GetTriggerMouseLeftButton(AddButton))
    {
        KomaCatch = true;
    }
    if (Input::GetTriggerMouseLeftButton(KeepButton)&&KeepFlag)
    {
        KeepCatch = true;
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
           

        }
    }

    HammerAction();

   
   
}

void GameScene::KomaSlotUpdate()
{
    if (Komalist.size() < 4)
    {
        Koma AddKoma = static_cast<Koma>(GetRand(0, sizeof(Koma) - 1));
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
                Komalist.push_back(static_cast<Koma>(i));
                ColorCounts[i] = 0;
                break;
            }
        }
        if (!Kyuusai)Komalist.push_back(AddKoma);

    }
}

void GameScene::KeepAction()
{
    if (Input::GetMouseHitBox(KeepButton))
    {
        Koma preKoma = KeepSlot;
        KeepSlot = Komalist.front();
        Komalist.erase(Komalist.begin());
        if (KeepFlag)
        {
            Komalist.insert(Komalist.begin(), preKoma);
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
    for (int i = 0; i < 2; i++)
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
            GameTime::LossTime(5);
            daruma[i].Order();
        }
    }
    
}

void GameScene::AddAction(bool keep)
{
    for (int i = 0; i < 2; i++)
    {
        if (Input::GetMouseHitBox(daruma[i].GetDragAndDropArea()))
        {
            if (!daruma[i].MaxKoma())
            {
                if (keep)
                {
                    daruma[i].ClickAddKoma(KeepSlot);
                    KeepFlag = false;
                }
                else
                {
                    daruma[i].ClickAddKoma(Komalist.front());
                    Komalist.erase(Komalist.begin());
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
