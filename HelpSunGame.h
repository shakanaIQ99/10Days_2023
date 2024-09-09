#pragma once
#include "BaseGame.h"
#include "Input.h"
#include <array>
#include "struct.h"

const size_t CLOUD_NUM = 5;

class HelpSunGame : public BaseGame
{
public:
	HelpSunGame(const Vector2& pos = { WIN_WIDTH / 2,WIN_HEIGHT / 2 });
	~HelpSunGame();
	void Init() override;
	void Update() override;
	void Draw() override;

private:
	Input* input_ = nullptr;
	BoxTransform sun_;
	std::array<BoxTransform, CLOUD_NUM> clouds_;
	std::array<bool, CLOUD_NUM> isClouds_;
};

