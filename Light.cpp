#include "Light.h"
#include "Util.h"
#include "main.h"

bool Light::isRot = false;

Light* Light::Create()
{
    Light* instance = new Light();
    if (instance == nullptr)
    {
        return nullptr;
    }

    instance->Init();

    return instance;
}

void Light::Init()
{
    texNum = DxLib::LoadGraph(L"Resources/Direction/stageLight.png");

    pos[0] = { 378,434 };
    pos[1] = { 169,434};

    pos[2] = { 902,434 };
    pos[3] = { 1112,434 };

    effectTimer = 0;
    angle[0] = 0.7f;
    angle[1] = 0.52f;
    angle[2] = -0.7f;
    angle[3] = -0.52f;

    rot[0] = 0.05f;
    rot[1] = 0.05f;

    rot[2] = -0.05f;
    rot[3] = -0.05f;
}

void Light::Update()
{
    if (isRot)
    {
        effectTimer++;

        for (size_t i = 0; i < 4; i++)
        {
            angle[i] += rot[i];

            if (angle[i] > 1.0f || angle[i] < -1.0f)
            {
                rot[i] *= -1;
            }
        }

        if (effectTimer > effectTime)
        {
            isRot = false;
        }
    }
    else
    {
        effectTimer = 0;
        angle[0] = 0.7f;
        angle[1] = 0.52f;
        angle[2] = -0.7f;
        angle[3] = -0.52f;
    }
}

void Light::Draw()
{
    for (size_t i = 0; i < 4; i++)
    {
        Util::DrawRotaGraph3C(pos[i], 64, 255, 1.5f, 1.7f, angle[i], texNum, true);
    }
}

void Light::SetRot()
{
    isRot = true;
}
