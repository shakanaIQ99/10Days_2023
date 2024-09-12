#pragma once
#include "DxLib.h"
#include "struct.h"
#include "main.h"

class BaseGame
{
public:
	enum WindowMode {
		Game,
		Mode
	};

public:
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
	WindowMode windowMode_;
	BoxTransform window_;
	int layer_ = 0;
	bool end_ = false;
	bool active_ = false;
	bool isMove_ = false;
	BoxTransform topBar_;
};