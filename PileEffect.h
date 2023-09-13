#pragma once
#include <list>
#include <memory>

#include "Vector2.h"
#include "Star.h"
#include "kurakka.h"

class PileEffect
{
public:
	static PileEffect* Create();

	void Init();

	void Update();

	void Draw();

	void PileSet(const Vector2& pos, const Vector2& range);

	void SlapSet(const Vector2& pos);

	void FanfarleSet();

	void SmallCracker(const Vector2& pos_);

private:
	std::list<std::unique_ptr<Star>> objects;
	std::list<std::unique_ptr<Cracker>> crackers;

	int texNum = 0;

	int texNum2 = 0;
};

