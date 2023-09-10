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
}

void Angry::Update()
{
    lifeTimer++;

    pos.x += velocity.x;
    pos.y += -velocity.y;

    if (lifeTimer >= lifeTime)
    {
        isDead = true;
    }
}

void Angry::Draw()
{
    DxLib::DrawRotaGraph(pos.x, pos.y, 0.2f, angle, texNum, true);
}

const bool Angry::GetIsDead() const
{
    return isDead;
}
