#include "SlapKoma.h"
#include "Util.h"

using namespace Util;

SlapKoma* SlapKoma::Create(const Vector2& pos_, const int& texNum_, const Vector2& velocity_)
{
    SlapKoma* instance = new SlapKoma();
    if (instance == nullptr)
    {
        return nullptr;
    }

    instance->Init(pos_, texNum_,velocity_);

    return instance;
}

void SlapKoma::Init(const Vector2& pos_, const int& texNum_, const Vector2& velocity_)
{
    box.pos = pos_;
    box.width = 32;
    box.height = 16;

    isDead = false;

    texNum = texNum_;

    angle = 0;

    alphaNum = 255;

    speed = velocity_;
}

void SlapKoma::Update()
{
    box.pos.x -= speed.x;
    box.pos.y -= speed.y;

    speed.y -= 2;

    angle++;

    alphaNum -= 5;

    if (box.pos.x <= 0 || box.pos.y >= 1280)
    {
        isDead = true;
    }
}

void SlapKoma::Draw()
{
    DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, alphaNum);
    DrawRotaGraph(box.pos.x, box.pos.y, 1.5f, angle, texNum, true);
    DxLib::SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

const bool SlapKoma::GetIsDead() const
{
    return isDead;
}

void SlapKoma::Reset()
{
    isDead = true;
}
