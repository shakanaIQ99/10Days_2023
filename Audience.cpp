#include "Audience.h"
#include "Util.h"
#include "Ease.h"

bool Audience::isCheers = false;
float Audience::phaseTime = 15;
uint32_t Audience::effectTime = 120;

Audience* Audience::Create()
{
    Audience* instance = new Audience();
    if (instance == nullptr)
    {
        return nullptr;
    }

    instance->Init();

    return instance;
}

void Audience::Init()
{
    transform[0].pos = { 96,720 + 96 };
    transform[0].width = 96;
    transform[0].height = 96;

    transform[1].pos = { 1280 - 96,720 + 96 };
    transform[1].width = 96;
    transform[1].height = 96;

    isCheers = false;
}

void Audience::Update()
{
    if (isCheers)
    {
        effectTimer++;

        if (effectTimer > effectTime)
        {
            phase = 3;
        }

        if (phase == 0)
        {
            phaseTimer++;

            transform[0].pos.y = Ease::OutQuadFloat(720 + 96, 720 - 96, phaseTimer / phaseTime);
            transform[1].pos.y = Ease::OutQuadFloat(720 + 96, 720 - 96, phaseTimer / phaseTime);

            if (phaseTimer >= phaseTime)
            {
                phase++;
                phaseTimer = 0;
            }
        }
        else if (phase == 1)
        {
            phaseTimer++;

            transform[0].pos.y = Ease::InQuadFloat(720 - 96, 720 - 64, phaseTimer / phaseTime);
            transform[1].pos.y = Ease::InQuadFloat(720 - 96, 720 - 64, phaseTimer / phaseTime);

            if (phaseTimer >= phaseTime)
            {
                phase++;
                phaseTimer = 0;
            }
        }
        else if (phase == 2)
        {
            phaseTimer++;

            transform[0].pos.y = Ease::OutQuadFloat(720 - 64, 720 - 96, phaseTimer / phaseTime);
            transform[1].pos.y = Ease::OutQuadFloat(720 - 64, 720 - 96, phaseTimer / phaseTime);

            if (phaseTimer >= phaseTime)
            {
                phase--;
                phaseTimer = 0;
            }
        }
        else if (phase == 3)
        {
            phaseTimer++;

            transform[0].pos.y = Ease::OutQuadFloat(720 - 64, 720 + 96, phaseTimer / phaseTime);
            transform[1].pos.y = Ease::OutQuadFloat(720 - 64, 720 + 96, phaseTimer / phaseTime);

            if (phaseTimer >= phaseTime)
            {
                phase--;
                phaseTimer = 0;
                isCheers = false;
            }
        }
    }
    else
    {
        effectTimer = 0;
        phase = 0;
        phaseTimer = 0;
        transform[0].pos.y = 720 + 96;
        transform[1].pos.y = 720 + 96;
    }
}

void Audience::Draw()
{
    for (size_t i = 0; i < transform.size(); i++)
    {
        Util::DrawBox(transform[i].pos, transform[i].width, transform[i].height, DxLib::GetColor(200, 200, 200), true);
    }
}

void Audience::SetIsCheers(bool isSccces)
{
    isCheers = true;
    if (isSccces)
    {
        phaseTime = 5;

        effectTime = 120;
    }
    else
    {
        phaseTime = 15;

        effectTime = 120;
    }
}
