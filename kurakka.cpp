#include "kurakka.h"
#include "main.h"
#include "Util.h"

Cracker* Cracker::Create(const int& texNum_, const Vector2& pos_, const Vector2& velocity_)
{
    Cracker* instance = new Cracker();
    if (instance == nullptr)
    {
        return nullptr;
    }

    instance->Init(texNum_, pos_, velocity_);

    return instance;
}

void Cracker::Init(const int& texNum_, const Vector2& pos_, const Vector2& velocity_)
{
    texNum = texNum_;

    pos = pos_;

    velocity = velocity_;

    isDead = false;

    angle = 0;

    GetCrackerColor();
}

void Cracker::Update()
{
    velocity.y -= 1.5f;

    pos.x += velocity.x;
    pos.y += -velocity.y;

    angle++;

    if (pos.y >= WIN_HEIGHT)
    {
        isDead = true;
    }
}

void Cracker::Draw()
{
    DxLib::SetDrawBright(red, green, blue);
    DxLib::DrawRotaGraph(pos.x, pos.y, 0.5f, angle, texNum, true);
    DxLib::SetDrawBright(255, 255, 255);
}

const bool Cracker::GetIsDead() const
{
    return isDead;
}

void Cracker::GetCrackerColor()
{
    crackerColor = static_cast<CrackerColor>(Util::GetRand(0, 4));

    switch (crackerColor)
    {
    case Cracker::CrackerColor::RED:
        red = 173;
        green = 22;
        blue = 16;
        break;
    case Cracker::CrackerColor::BLUE:
        red = 16;
        green = 30;
        blue = 173;
        break;
    case Cracker::CrackerColor::GREEN:
        red = 47;
        green = 183;
        blue = 51;
        break;
    case Cracker::CrackerColor::YELLOW:
        red = 244;
        green = 220;
        blue = 9;
        break;
    case Cracker::CrackerColor::WHITE:
        red = 230;
        green = 230;
        blue = 230;
        break;
    default:
        break;
    }
}
