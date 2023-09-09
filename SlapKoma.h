#pragma once
#include "Vector2.h"
#include "struct.h"

class SlapKoma
{
public:
	static SlapKoma* Create(const Vector2& pos_);

	void Init(const Vector2& pos_);

	void Update();

	void Draw();

	const bool GetIsDead() const;

private:
	BoxTransform box;

	bool isDead = false;
};

