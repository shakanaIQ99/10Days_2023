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
	
    GetMousePoint(&mouseX, &mouseY);
    mousePos = { (float)mouseX,(float)mouseY };

   
    KomaUpdate();

	daruma.Update();

   
}

void GameScene::Draw()
{
	daruma.Draw();
    ButtonsDraw();
}

bool GameScene::MouseBoxHit(BoxTransform box, Vector2 mousePos)
{
    if (box.pos.x - (float)box.width <= mousePos.x &&
        box.pos.x + (float)box.width >= mousePos.x &&
        box.pos.y - (float)box.height <= mousePos.y &&
        box.pos.y + (float)box.height >= mousePos.y)
    {
        return true;
    }
    return false;
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
    if (Input::GetTriggerMouseLeft())
    {
        if (MouseBoxHit(RedButton, mousePos))
        {
            daruma.ClickAddKoma(Koma::RED);
        }
        if (MouseBoxHit(GreanButton, mousePos))
        {
            daruma.ClickAddKoma(Koma::GREEN);
        }
        if (MouseBoxHit(BlueButton, mousePos))
        {
            daruma.ClickAddKoma(Koma::BLUE);
        }
        if (MouseBoxHit(BlackButton, mousePos))
        {
            daruma.ClickAddKoma(Koma::BLACK);
        }
        if (MouseBoxHit(daruma.GetKomaTransform(), mousePos))
        {
            if (daruma.GetBeKoma())
            {
                daruma.ClickRemoveKoma();
            }
        }
        if (MouseBoxHit(daruma.GetHead(), mousePos))
        {
            daruma.HeadReset();
        }
    }
   


}
