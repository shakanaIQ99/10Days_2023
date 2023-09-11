#pragma once
#include "Vector2.h"
#include "struct.h"

class SlapKoma
{
public:
	static SlapKoma* Create(const Vector2& pos_, const int& color_, const Vector2& velocity_);

	void Init(const Vector2& pos_, const int& color_, const Vector2& velocity_);

	void Update();

	void Draw();

	const bool GetIsDead() const;

private:
	BoxTransform box;

	bool isDead = false;

	int texNum = 0;

	double angle = 0;

	int alphaNum = 0;

	Vector2 speed = { 0,0 };
};

