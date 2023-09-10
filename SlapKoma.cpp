#include "SlapKoma.h"
#include "Util.h"

using namespace Util;

SlapKoma* SlapKoma::Create(const Vector2& pos_, const int& color_)
{
    SlapKoma* slapKoma = new SlapKoma();
    if (slapKoma == nullptr)
    {
        return nullptr;
    }

    slapKoma->Init(pos_, color_);

    return slapKoma;
}

void SlapKoma::Init(const Vector2& pos_, const int& color_)
{
    box.pos = pos_;
    box.width = 32;
    box.height = 16;

    isDead = false;

    color = color_;
}

void SlapKoma::Update()
{
    box.pos.x -= 10;

    if (box.pos.x <= 0)
    {
        isDead = true;
    }
}

void SlapKoma::Draw()
{
    DrawBox(box.pos, box.width, box.height, color, true);
}

const bool SlapKoma::GetIsDead() const
{
    return isDead;
}
