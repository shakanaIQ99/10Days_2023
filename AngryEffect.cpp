#include "AngryEffect.h"
#include "Util.h"

AngryEffect* AngryEffect::Create()
{
	AngryEffect* instance = new AngryEffect();
	if (instance == nullptr)
	{
		return nullptr;
	}

	instance->Init();

	return instance;
}

void AngryEffect::Init()
{
	texNum = DxLib::LoadGraph(L"Resources/Direction/smoke.png");
}

void AngryEffect::Update()
{
	objects.remove_if([](std::unique_ptr<Angry>& object) {return object->GetIsDead(); });

	for (std::unique_ptr<Angry>& object : objects)
	{
		object->Update();
	}
}

void AngryEffect::Draw()
{
	for (std::unique_ptr<Angry>& object : objects)
	{
		object->Draw();
	}
}

void AngryEffect::Set(const Vector2& pos, const Vector2& range)
{
	std::unique_ptr<Angry> newRight;
	newRight.reset(Angry::Create(texNum, { pos.x + range.x,pos.y - range.y }, { 1,1 }, 0.8f));
	objects.push_back(std::move(newRight));

	std::unique_ptr<Angry> newLeft;
	newLeft.reset(Angry::Create(texNum, { pos.x - range.x,pos.y - range.y }, { -1,1 }, -0.8f));
	objects.push_back(std::move(newLeft));
}
