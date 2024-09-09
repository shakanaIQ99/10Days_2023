#pragma once
#include "BaseGame.h"
#include "Input.h"

class KusogakiGame : public BaseGame
{
public:
	void Init() override;
	void Update() override;
	void Draw() override;

private:
	Input* input_ = nullptr;

	BoxTransform testBox;
};

