#pragma once
#include "Vector2.h"
#include "struct.h"
#include <array>

class Audience
{
public:
	static Audience* Create();

	void Init();

	void Update();

	void Draw();

	static void SetIsCheers(const bool isSccces = false);
private:
	std::array<BoxTransform,2> transform;

	static bool isCheers;

	size_t phase = 0;

	float phaseTimer = 0;

	static float phaseTime;

	uint32_t effectTimer = 0;

	static uint32_t effectTime;
};

