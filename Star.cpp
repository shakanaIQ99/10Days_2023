#include "Star.h"
#include "Util.h"

Star* Star::Create(const int& texNum_, const Vector2& pos_, const Vector2& velocity_)
{
    Star* instance = new Star();
    if (instance == nullptr)
    {
        return nullptr;
    }

    instance->Init(texNum_, pos_, velocity_);

    return instance;
}

void Star::Init(const int& texNum_, const Vector2& pos_, const Vector2& velocity_)
{
    texNum = texNum_;

    pos = pos_;

    velocity = velocity_;

    range = { 10,10 };

    lifeTimer = 0;

    isDead = false;

    angle = 0;
}

void Star::Update()
{
    lifeTimer++;

    velocity.y -= 0.1f;

    pos.x += velocity.x;
    pos.y += -velocity.y;

    angle++;

    if (lifeTimer >= lifeTime)
    {
        isDead = true;
    }
}

void Star::Draw()
{
    DxLib::DrawRotaGraph(pos.x, pos.y, 0.2f, angle, texNum, true);
}

const bool Star::GetIsDead() const
{
    return isDead;
}
