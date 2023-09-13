#include "SceneChangeEffect.h"
#include "Util.h"
#include "main.h"

SceneChangeEffect* SceneChangeEffect::Create()
{
    SceneChangeEffect* instance = new SceneChangeEffect();
    if (instance == nullptr)
    {
        return nullptr;
    }

    instance->Init();

    return instance;
}

void SceneChangeEffect::Init()
{
    texNum = DxLib::LoadGraph(L"Resources/Direction/white1x1.png");
}

void SceneChangeEffect::Update()
{
    if (isEffect)
    {
        if (isIn)
        {
            alphaNum += 12.75f;

            if (alphaNum > 255)
            {
                alphaNum = 255;
                isIn = false;
                sceneChange = true;
            }
        }

        if (sceneChange)
        {
            isOut = true;
        }

        if (isOut)
        {
            alphaNum -= 12.75f;

            if (alphaNum < 0)
            {
                alphaNum = 0;
                isOut = false;
                isEffect = false;
            }
        }
    }
}

void SceneChangeEffect::Draw()
{
    DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, alphaNum);
    DxLib::DrawExtendGraph(0, 0, WIN_WIDTH, WIN_HEIGHT, texNum, true);
    DxLib::SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

const bool SceneChangeEffect::GetIsChange() const
{
    return sceneChange;
}

const bool SceneChangeEffect::GetIsEffect() const
{
    return isEffect;
}

void SceneChangeEffect::SetIsSceneChange(bool sceneChange_)
{
    sceneChange = sceneChange_;
}

void SceneChangeEffect::EffectStart()
{
    if (!isEffect)
    {
        isEffect = true;
        isIn = true;
    }
}
