#pragma once
#include "BaseGame.h"
#include "Input.h"
#include <array>

class KusogakiGame : public BaseGame
{
public:
	KusogakiGame(int layernum, const Vector2& pos);
	~KusogakiGame();
	void Init() override;
	void Update() override;
	void Draw() override;

private:
	Input* input_ = nullptr;

	std::array<BoxTransform, 3> panels_;
};

