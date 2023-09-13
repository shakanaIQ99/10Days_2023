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

	static void SetRot();

private:
	int texNum = 0;

	std::array<Vector2, 4> pos;

	std::array<double, 4> angle;

	std::array<double, 4> rot;

	static bool isRot;

	uint32_t effectTimer = 0;

	const uint32_t effectTime = 60;
};

