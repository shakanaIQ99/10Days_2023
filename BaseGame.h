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

	int GetLayer() {
		return layer_;
	}

	void SetLayer(int layer)
	{
		layer_ = layer;
	}

	bool GetEnd() {
		return end_;
	}

	void OnActive()
	{
		active_ = true;
	}

	void OffActive()
	{
		active_ = false;
	}

	BoxTransform GetTransform()
	{
		return window_;
	}

protected:

	BoxTransform window_;
	int layer_ = 50;
	bool end_ = false;
	bool active_ = false;
};