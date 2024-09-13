#pragma once
#include "BaseGame.h"
#include "Input.h"

class ZihannGame : public BaseGame
{
public:
	enum Phase {
		ZihannMae,
		ZihannSita
	};

public:
	ZihannGame(int layernum, const Vector2& pos);
	~ZihannGame();
	void Update() override;
	void Draw() override;

private:
	Input* input_ = nullptr;

	Phase phase_ = ZihannMae;

	BoxTransform zihannki_;
	Vector2 nowZihannki_;
};

