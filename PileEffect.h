#pragma once
#include <list>
#include <memory>

#include "Vector2.h"
#include "Star.h"

class PileEffect
{
public:
	static PileEffect* Create();

	void Init();

	void Update();

	void Draw();

	void Set(const Vector2& pos, const Vector2& range);

private:
	const int PartNum = 5;

	std::list<std::unique_ptr<Star>> objects;

	int texNum = 0;
};

