#pragma once
#include "BaseGame.h"
#include "Input.h"
#include <array>
#include "struct.h"

const size_t CLOUD_NUM = 5;

class HelpSunGame : public BaseGame
{
public:
	HelpSunGame(int layernum, const Vector2& pos);
	~HelpSunGame();
	void Update() override;
	void Draw() override;

private:
	Input* input_ = nullptr;
	BoxTransform sun_;
	Vector2 nowSun_;
	std::array<BoxTransform, CLOUD_NUM> clouds_;
	std::array<Vector2, CLOUD_NUM> nowClouds_;
	std::array<bool, CLOUD_NUM> isClouds_;
};

