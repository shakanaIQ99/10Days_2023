#include "Angry.h"
#include "Util.h"

Angry* Angry::Create(const int& texNum_, const Vector2& pos_, const Vector2& velocity_, const float& angle_)
{
    Angry* instance = new Angry();
    if (instance == nullptr)
    {
        return nullptr;
    }

    instance->Init(texNum_, pos_, velocity_, angle_);

    return instance;
}

void Angry::Init(const int& texNum_, const Vector2& pos_, const Vector2& velocity_, const float& angle_)
{
    texNum = texNum_;

    pos = pos_;

    velocity = velocity_;

    range = { 10,10 };

    lifeTimer = 0;

    isDead = false;

    angle = angle_;

    Rate = 1;
}

void Angry::Update()
{
    lifeTimer++;

    pos.x += velocity.x;
    pos.y += -velocity.y;

    Rate -= 0.02f;

    if (lifeTimer >= lifeTime)
    {
        isDead = true;
    }
}

void Angry::Draw()
{
    DxLib::DrawRotaGraph(pos.x, pos.y, Rate, angle, texNum, true);
    //Util::DrawRoTaGraph3(pos, 0, 0, angle, texNum);
}

const bool Angry::GetIsDead() const
{
    return isDead;
}
