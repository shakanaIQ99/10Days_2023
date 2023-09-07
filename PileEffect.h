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

	void PileSet(const Vector2& pos, const Vector2& range);

	void SlapSet(const Vector2& pos);

private:
	const int PartNum = 5;

	std::list<std::unique_ptr<Star>> objects;

	int texNum = 0;

	int texNum2 = 0;
};

