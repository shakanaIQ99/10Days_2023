#pragma once
#include "Vector2.h"
#include <stdint.h>

class Angry
{
public:
	static Angry* Create(const int& texNum_, const Vector2& pos_, const Vector2& velocity_, const float& angle_);

	void Init(const int& texNum_, const Vector2& pos_, const Vector2& velocity_, const float& angle_);

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

	double Rate = 0;
};

