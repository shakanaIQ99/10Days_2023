#include "PileEffect.h"
#include "Util.h"

PileEffect* PileEffect::Create()
{
	PileEffect* instance = new PileEffect();
	if (instance == nullptr)
	{
		return nullptr;
	}

	instance->Init();

	return instance;
}

void PileEffect::Init()
{
	texNum = DxLib::LoadGraph(L"Resources/Direction/circle.png");
}

void PileEffect::Update()
{
	objects.remove_if([](std::unique_ptr<Star>& object) {return object->GetIsDead(); });

	for (std::unique_ptr<Star>& object : objects)
	{
		object->Update();
	}
}

void PileEffect::Draw()
{
	for (std::unique_ptr<Star>& object : objects)
	{
		object->Draw();
	}
}

void PileEffect::Set(const Vector2& pos, const Vector2& range)
{
	std::unique_ptr<Star> newRight;
	newRight.reset(Star::Create(texNum, { pos.x + range.x,pos.y - range.y }, { (Util::GetRand(8,10) * 0.1f),(Util::GetRand(0,10) * 0.1f) }));
	objects.push_back(std::move(newRight));

	std::unique_ptr<Star> newLeft;
	newLeft.reset(Star::Create(texNum, { pos.x - range.x,pos.y - range.y }, { -(Util::GetRand(8,10) * 0.1f),(Util::GetRand(0,10) * 0.1f) }));
	objects.push_back(std::move(newLeft));
}
