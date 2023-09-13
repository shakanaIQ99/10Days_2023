#include "CountDown.h"
#include "Util.h"
#include "main.h"
#include "Ease.h"

CountDown* CountDown::Create()
{
    CountDown* instance = new CountDown();
    if (instance == nullptr)
    {
        return nullptr;
    }

    instance->Init();

    return instance;
}

void CountDown::Init()
{
    for (size_t i = 0; i < 2; i++)
    {
        transforms[i].pos.x = WIN_WIDTH / 2;
        transforms[i].width = WIN_WIDTH;
        transforms[i].height = WIN_HEIGHT;
    }

    transforms[0].pos.y = WIN_HEIGHT * 1 / 4;
    transforms[1].pos.y = WIN_HEIGHT * 3 / 4;

    phase = 0;

    startCountTimer = 0;

    isStart = false;
}

void CountDown::Update()
{
    if (phase == 0)
    {
        easeTime = 30;

        easeTimer++;

        if (easeTimer > easeTime)
        {
            easeTimer = 0;
            phase++;
        }
    }
    else if (phase == 1)
    {
        easeTime = 30;

        easeTimer++;

        transforms[0].pos.y = Ease::OutQuadFloat(WIN_HEIGHT * 1 / 4, WIN_HEIGHT * 1 / 5, easeTimer / easeTime);
        transforms[1].pos.y = Ease::OutQuadFloat(WIN_HEIGHT * 3 / 4, WIN_HEIGHT * 4 / 5, easeTimer / easeTime);

        if (easeTimer > easeTime)
        {
            easeTimer = 0;
            phase++;
        }
    }
    else if (phase == 2)
    {
        easeTime = 30;

        easeTimer++;

        if (easeTimer > easeTime)
        {
            easeTimer = 0;
            phase++;
        }
    }
    else if (phase == 3)
    {
        if (startCountTimer > startCountTime)
        {
            isStart = true;
            phase++;
        }
        else
        {
            startCountTimer++;
        }
    }
    else if (phase == 4)
    {
        easeTime = 30;

        easeTimer++;

        transforms[0].pos.y = Ease::OutQuadFloat(WIN_HEIGHT * 1 / 5, -WIN_HEIGHT * 1 / 2, easeTimer / easeTime);
        transforms[1].pos.y = Ease::OutQuadFloat(WIN_HEIGHT * 4 / 5, WIN_HEIGHT * 3 / 2, easeTimer / easeTime);

        if (easeTimer > easeTime)
        {
            easeTimer = 0;
            phase++;
        }
    }
}

void CountDown::Draw()
{
    for (size_t i = 0; i < 2; i++)
    {
        DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
        Util::DrawBox(transforms[i].pos, transforms[i].width / 2, transforms[i].height / 4, GetColor(0, 0, 0), true);
        DxLib::SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    }
}

const bool CountDown::GetIsStart() const
{
    return isStart;
}
