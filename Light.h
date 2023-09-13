#pragma once
#include "Vector2.h"
#include <array>

class Light
{
public:
	enum struct LightColor : int
	{
		RED,
		BLUE,
		GREEN,
		YELLOW
	};

	static Light* Create();

	void Init();

	void Update();

	void Draw();

	static void SetRot();

	void GetCrackerColor();

private:
	int texNum = 0;

	std::array<Vector2, 4> pos;

	std::array<double, 4> angle;

	std::array<double, 4> rot;

	static bool isRot;

	uint32_t effectTimer = 0;

	const uint32_t effectTime = 120;

	int32_t red = 0;
	int32_t green = 0;
	int32_t blue = 0;

	bool resultColor = false;

	LightColor crackerColor;
};

