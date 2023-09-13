#include "Light.h"
#include "Util.h"

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
}

void Light::Update()
{
}

void Light::Draw()
{
}
