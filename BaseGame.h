#pragma once
#include "DxLib.h"
#include "Vector2.h"
#include "main.h"

class BaseGame
{
public:
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

protected:
	int layer_ = 0;

	Vector2 windowPos_ = { 0.0f,0.0f };
	Vector2 windowSize_ = { 0.0f,0.0f };
};