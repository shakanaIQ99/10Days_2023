#pragma once
#include "BaseGame.h"
#include "Input.h"
#include <array>

class KusogakiGame : public BaseGame
{
public:
	KusogakiGame(int layernum, const Vector2& pos);
	~KusogakiGame();
	void Update() override;
	void Draw() override;

private:
	Input* input_ = nullptr;

	std::array<BoxTransform, 3> panels_;
	std::array<Vector2, 3> nowPanels_;
	std::array<bool, 3> isPanels_;

	std::array<BoxTransform, 6> buttons_;
	std::array<Vector2, 6> nowButtons_;
	std::array<int, 6> buttonColors_;
};

