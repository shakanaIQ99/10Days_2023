#include "GameScene.h"
#include"Input.h"
#include"Util.h"

using namespace Util;

void GameScene::Init()
{
	daruma.Init();

    RedButton.pos = { 320.0f-160.0f,600.0f };
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
    BlackButton.height = Buttonheight;

    
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
    DrawBox(RedButton.pos, RedButton.width, RedButton.height, GetColor(255, 0, 0), true);
    DrawBox(GreanButton.pos, GreanButton.width, GreanButton.height, GetColor(0, 255, 0), true);
    DrawBox(BlueButton.pos, BlueButton.width, BlueButton.height, GetColor(0, 0, 255), true);
    DrawBox(BlackButton.pos, BlackButton.width, BlackButton.height, GetColor(0, 0, 0), true);
}

void GameScene::KomaUpdate()
{
    if (Input::GetTriggerMouseLeftButton(RedButton))daruma.ClickAddKoma(Koma::RED);
    if (Input::GetTriggerMouseLeftButton(GreanButton))daruma.ClickAddKoma(Koma::GREEN);
    if (Input::GetTriggerMouseLeftButton(BlueButton))daruma.ClickAddKoma(Koma::BLUE);
    if (Input::GetTriggerMouseLeftButton(BlackButton))daruma.ClickAddKoma(Koma::BLACK);
    if (Input::GetTriggerMouseLeftButton(daruma.GetKomaTransform()))
    {
        if (daruma.GetBeKoma())daruma.ClickRemoveKoma();
    }
    if (Input::GetTriggerMouseLeftButton(daruma.GetHead())) daruma.HeadReset();
}
