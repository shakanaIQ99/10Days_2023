#pragma once
#include "struct.h"
#include <array>

class CountDown
{
public:
	static CountDown* Create();

	void Init();

	void Update();

	void Draw();

	const bool GetIsStart() const;

private:
	std::array<BoxTransform, 2> transforms;

	uint32_t startCountTimer = 0;
	const uint32_t startCountTime = 120;

	uint32_t phase = 0;
	
	float easeTimer = 0;

	float easeTime = 0;

	bool isStart = false;
};

