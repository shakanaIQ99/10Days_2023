#pragma once
#include "Vector2.h"
#include <array>

class Light
{
public:
	static Light* Create();

	void Init();

	void Update();

	void Draw();

private:
	int texNum = 0;

	std::array<Vector2, 4> pos;

	std::array<double, 4> angle;
};

