#pragma once
#include "DxLib.h"
#include "struct.h"
#include "main.h"

class BaseGame
{
public:
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

protected:
	int layer_ = 0;

	BoxTransform window_;
	BoxTransform topBar_;
};