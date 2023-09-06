#include "GameScene.h"
#include"Input.h"
#include"Util.h"
#include"main.h"

using namespace Util;

void GameScene::Init()
{
    daruma.Init(Vector2(WIN_WIDTH / 2.0f, 470.0f));

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

    KeepKoma.pos = { 0,0 };
    KeepKoma.width = ButtonWidth;
    KeepKoma.height = Buttonheight;

    daruma.Order();
    Komalist.clear();

    for (int colorCounts: ColorCounts)
    {
        colorCounts = 0;
    }
  
}


void GameScene::Update()
{
    KomaUpdate();

    if (KeepFlag)
    {
        KeepKoma.pos = KeepButton.pos;
    }

	daruma.Update();  
}

void GameScene::Draw()
{
	daruma.Draw();
    ButtonsDraw();
}


void GameScene::ButtonsDraw()
{
    DrawBox(AddButton.pos, AddButton.width, AddButton.height, GetColor(255, 255, 0), false);
    DrawBox(KeepButton.pos, KeepButton.width, KeepButton.height, GetColor(0, 255, 255), false);
    int floar = 0;
    for (auto itr = Komalist.begin(); itr != Komalist.end(); itr++)
    {
        DrawBox(Komas[floar].pos, Komas[floar].width, Komas[floar].height, daruma.GetKomaColor(*itr), true);
        floar++;
    }
    if (KeepFlag)DrawBox(KeepKoma.pos, KeepKoma.width, KeepKoma.height, daruma.GetKomaColor(KeepSlot), true);
}

void GameScene::KomaUpdate()
{
    if (Komalist.size() < 4)
    {
        Koma AddKoma = static_cast<Koma>(GetRand(0, sizeof(Koma)-1));
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
        if(!Kyuusai)Komalist.push_back(AddKoma);
        
    }

    if (Input::GetTriggerMouseLeftButton(AddButton))
    {
        Komacatch = true;
    }

    if (Komacatch)
    {
        Komas[0].pos = Input::GetMousePos();
        if (Input::GetReleaseMouseLeft())
        {
            if (Input::GetMouseHitBox(daruma.GetDragAndDropArea()))
            {
                if (!daruma.MaxKoma())
                {
                    daruma.ClickAddKoma(Komalist.front());
                    Komalist.erase(Komalist.begin());
                }
               
            }
            Komas[0].pos = AddButton.pos;
            Komacatch = false;
            
        }
    }

    

   /* if (Input::GetTriggerMouseLeftButton(AddButton)&&!daruma.MaxKoma())
    {
        daruma.ClickAddKoma(Komalist.front());
        Komalist.erase(Komalist.begin());
    }*/
    if (Input::GetTriggerMouseLeftButton(KeepButton))
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
    if (Input::GetTriggerMouseLeftButton(daruma.GetKomaTransform()))
    {
        if (daruma.GetBeKoma())daruma.ClickRemoveKoma();
    }
    if (Input::GetTriggerMouseLeftButton(daruma.GetHead())) daruma.Order();
}
