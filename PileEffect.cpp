#include "PileEffect.h"
#include "Util.h"
#include "main.h"

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

	for (std::unique_ptr<Cracker>& cracker : crackers)
	{
		cracker->Update();
	}
}

void PileEffect::Draw()
{
	for (std::unique_ptr<Star>& object : objects)
	{
		object->Draw();
	}

	for (std::unique_ptr<Cracker>& cracker : crackers)
	{
		cracker->Draw();
	}
}

void PileEffect::PileSet(const Vector2& pos, const Vector2& range)
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

void PileEffect::SlapSet(const Vector2& pos)
{
	std::unique_ptr<Star> newRight;
	newRight.reset(Star::Create(texNum, pos,
		{ (Util::GetRand(28,40) * 0.1f),(Util::GetRand(10,20) * 0.1f) }));
	objects.push_back(std::move(newRight));

	std::unique_ptr<Star> newFrameRight;
	newFrameRight.reset(Star::Create(texNum2, pos,
		{ (Util::GetRand(28,40) * 0.1f),(Util::GetRand(10,20) * 0.1f) }));
	objects.push_back(std::move(newFrameRight));
}

void PileEffect::FanfarleSet()
{
	for (size_t i = 0; i < 35; i++)
	{
		std::unique_ptr<Cracker> newRight;
		newRight.reset(Cracker::Create(texNum, { 1280,(float)Util::GetRand(WIN_HEIGHT / 2, WIN_HEIGHT * 2 / 3) },
			{ -(float)(Util::GetRand(4,20)),(float)(Util::GetRand(10,35)) }));
		crackers.push_back(std::move(newRight));

		std::unique_ptr<Cracker> newFrameRight;
		newFrameRight.reset(Cracker::Create(texNum2, { 1280,(float)Util::GetRand(WIN_HEIGHT / 2, WIN_HEIGHT * 2/3) },
			{ -(float)(Util::GetRand(4,20)),(float)(Util::GetRand(10,35)) }));
		crackers.push_back(std::move(newFrameRight));

		std::unique_ptr<Cracker> newLeft;
		newLeft.reset(Cracker::Create(texNum, { 0,(float)Util::GetRand(WIN_HEIGHT / 2, WIN_HEIGHT * 2 / 3) },
			{ (float)(Util::GetRand(4,20)),(float)(Util::GetRand(10,35)) }));
		crackers.push_back(std::move(newLeft));

		std::unique_ptr<Cracker> newFrameLeft;
		newFrameLeft.reset(Cracker::Create(texNum2, { 0,(float)Util::GetRand(WIN_HEIGHT / 2, WIN_HEIGHT * 2 / 3) },
			{ (float)(Util::GetRand(4,20)),(float)(Util::GetRand(10,35)) }));
		crackers.push_back(std::move(newFrameLeft));
	}
}
