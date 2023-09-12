#pragma once
#include "Vector2.h"
#include <stdint.h>

class Cracker
{
public:
	enum struct CrackerColor : int
	{
		RED,
		BLUE,
		GREEN,
		YELLOW,
		WHITE
	};

	static Cracker* Create(const int& texNum_, const Vector2& pos_, const Vector2& velocity_, const double& rate);

	void Init(const int& texNum_, const Vector2& pos_, const Vector2& velocity_, const double& rate);

	void Update();

	void Draw();

	const bool GetIsDead() const;

	void GetCrackerColor();
private:
	int texNum = 0;

	Vector2 pos;

	Vector2 velocity;

	bool isDead = false;

	double angle = 0;

	int32_t red = 0;
	int32_t green = 0;
	int32_t blue = 0;

	double rate = 0;

	CrackerColor crackerColor;
};

