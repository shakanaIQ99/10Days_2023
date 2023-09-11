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

	void SetIsCheers(const bool isCheers_);
private:
	std::array<BoxTransform,2> transform;

	bool isCheers = false;

	size_t phase = 0;

	float phaseTimer = 0;

	const float phaseTime = 15;
};

