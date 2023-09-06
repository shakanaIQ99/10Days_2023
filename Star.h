#pragma once
#include "Vector2.h"
#include <stdint.h>

class Star
{
public:
	static Star* Create(const int& texNum_, const Vector2& pos_, const Vector2& velocity_);

	void Init(const int& texNum_, const Vector2& pos_, const Vector2& velocity_);

	void Update();

	void Draw();

	const bool GetIsDead() const;
private:
	int texNum = 0;

	Vector2 pos;

	Vector2 velocity;

	Vector2 range;

	int32_t lifeTimer = 0;

	const int32_t lifeTime = 30;

	bool isDead = false;

	double angle = 0;
};

