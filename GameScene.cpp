#include "GameScene.h"
#include"Input.h"
#include"Util.h"
#include"main.h"

using namespace Util;

void GameScene::Init()
{
	daruma.Init();

   /* RedButton.pos = { 320.0f-160.0f,600.0f };
    GreanButton.pos = { 320.0f * 2.0f - 160.0f,600.0f };
    BlueButton.pos = { 320.0f * 3.0f - 160.0f,600.0f };
    BlackButton.pos = { 320.0f * 4.0f - 160.0f,600.0f };

    RedButton.width = ButtonWidth;
    RedButton.height = Buttonheight;

    GreanButton.width = ButtonWidth;
    GreanButton.height = Buttonheight;

    BlueButton.width = ButtonWidth;
    BlueButton.height = Buttonheight;

    BlackButton.width = ButtonWidth;
    BlackButton.height = Buttonheight;*/


    for (int i = 0; i < 3; i++)
    {
        Komas[i + 1].pos = { ((float)WIN_WIDTH / 2.0f)+160+160*i,((float)WIN_HEIGHT / 6.0f) * 5.0f };
        Komas[i + 1].width = ButtonWidth;
        Komas[i + 1].height = Buttonheight;
    }

    AddButton.pos = {(float)WIN_WIDTH/2.0f,((float)WIN_HEIGHT/6.0f)*5.0f};
    AddButton.width = 60;
    AddButton.height = 60;

    Komas[0].pos = AddButton.pos;
    Komas[0].width = ButtonWidth;
    Komas[0].height = Buttonheight;

    daruma.Order();
    Komalist.clear();
  
}


void GameScene::Update()
{
    KomaUpdate();

	daruma.Update();  
}

void GameScene::Draw()
{
	daruma.Draw();
    ButtonsDraw();
}


void GameScene::ButtonsDraw()
{
   /* DrawBox(RedButton.pos, RedButton.width, RedButton.height, GetColor(255, 0, 0), true);
    DrawBox(GreanButton.pos, GreanButton.width, GreanButton.height, GetColor(0, 255, 0), true);
    DrawBox(BlueButton.pos, BlueButton.width, BlueButton.height, GetColor(0, 0, 255), true);
    DrawBox(BlackButton.pos, BlackButton.width, BlackButton.height, GetColor(0, 0, 0), true);*/
    DrawBox(AddButton.pos, AddButton.width, AddButton.height, GetColor(255, 255, 0), false);
    int floar = 0;
    for (auto itr = Komalist.begin(); itr != Komalist.end(); itr++)
    {
        //DrawBox(Komas[static_cast<int>(*itr)].pos, Komas[static_cast<int>(*itr)].width, Komas[static_cast<int>(*itr)].height, daruma.GetKomaColor(*itr), true);
        DrawBox(Komas[floar].pos, Komas[floar].width, Komas[floar].height, daruma.GetKomaColor(*itr), true);
        floar++;
    }
}

void GameScene::KomaUpdate()
{
    if (Komalist.size() < 4)
    {
        Koma AddKoma = static_cast<Koma>(GetRand(0, sizeof(Koma)-1));

        Komalist.push_back(AddKoma);
    }

    if (Input::GetTriggerMouseLeftButton(AddButton))
    {
        daruma.ClickAddKoma(Komalist.front());
        Komalist.erase(Komalist.begin());
    }
    if (Input::GetTriggerMouseLeftButton(daruma.GetKomaTransform()))
    {
        if (daruma.GetBeKoma())daruma.ClickRemoveKoma();
    }
    if (Input::GetTriggerMouseLeftButton(daruma.GetHead())) daruma.HeadReset();



    /*if (Input::GetTriggerMouseLeftButton(RedButton))daruma.ClickAddKoma(Koma::RED);
    if (Input::GetTriggerMouseLeftButton(GreanButton))daruma.ClickAddKoma(Koma::GREEN);
    if (Input::GetTriggerMouseLeftButton(BlueButton))daruma.ClickAddKoma(Koma::BLUE);
    if (Input::GetTriggerMouseLeftButton(BlackButton))daruma.ClickAddKoma(Koma::BLACK);
    if (Input::GetTriggerMouseLeftButton(daruma.GetKomaTransform()))
    {
        if (daruma.GetBeKoma())daruma.ClickRemoveKoma();
    }
    if (Input::GetTriggerMouseLeftButton(daruma.GetHead())) daruma.HeadReset();*/
}
