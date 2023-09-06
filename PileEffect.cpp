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
	texNum = DxLib::LoadGraph(L"Resources/Direction/star.png");
	texNum2 = DxLib::LoadGraph(L"Resources/Direction/starFlame.png");
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
	newRight.reset(Star::Create(texNum, { pos.x + range.x,pos.y - range.y }, 
		{ (Util::GetRand(28,40) * 0.1f),(Util::GetRand(10,20) * 0.1f) }));
	objects.push_back(std::move(newRight));

	std::unique_ptr<Star> newFrameRight;
	newFrameRight.reset(Star::Create(texNum2, { pos.x + range.x,pos.y - range.y },
		{ (Util::GetRand(28,40) * 0.1f),(Util::GetRand(10,20) * 0.1f) }));
	objects.push_back(std::move(newFrameRight));

	std::unique_ptr<Star> newLeft;
	newLeft.reset(Star::Create(texNum, { pos.x - range.x,pos.y - range.y }, 
		{ -(Util::GetRand(28,40) * 0.1f),(Util::GetRand(10,20) * 0.1f) }));
	objects.push_back(std::move(newLeft));

	std::unique_ptr<Star> newFrameLeft;
	newFrameLeft.reset(Star::Create(texNum2, { pos.x - range.x,pos.y - range.y },
		{ -(Util::GetRand(28,40) * 0.1f),(Util::GetRand(10,20) * 0.1f) }));
	objects.push_back(std::move(newFrameLeft));
}
