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

    resultColor = false;
}

void Light::Update()
{
    if (isRot)
    {
        if (!resultColor)
        {
            GetCrackerColor();
            resultColor = true;
        }

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
        resultColor = false;
    }
}

void Light::Draw()
{
    for (size_t i = 0; i < 4; i++)
    {
        if (isRot)
        {
            DxLib::SetDrawBright(red, green, blue);
        }
        else
        {
            DxLib::SetDrawBright(255, 255, 255);
        }

        Util::DrawRotaGraph3C(pos[i], 64, 255, 1.5f, 1.7f, angle[i], texNum, true);
        DxLib::SetDrawBright(255, 255, 255);
    }
}

void Light::SetRot()
{
    isRot = true;
}

void Light::GetCrackerColor()
{
    crackerColor = static_cast<LightColor>(Util::GetRand(0, 3));

    switch (crackerColor)
    {
    case Light::LightColor::RED:
        red = 173;
        green = 22;
        blue = 16;
        break;
    case Light::LightColor::BLUE:
        red = 16;
        green = 30;
        blue = 173;
        break;
    case Light::LightColor::GREEN:
        red = 47;
        green = 183;
        blue = 51;
        break;
    case Light::LightColor::YELLOW:
        red = 244;
        green = 220;
        blue = 9;
        break;
    default:
        break;
    }
}
