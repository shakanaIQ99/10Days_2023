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
	void DragAct();
	void ClickAct();

private:
	Input* input_ = nullptr;

	Phase phase_ = ZihannMae;

	BoxTransform zihannki_;
	Vector2 nowZihannki_;
	BoxTransform zihannkiBottom_;

	BoxTransform coin_;
	Vector2 nowCoin_;

	int ZihannTexture_;
	int ZihannRightTexture_;
	int ZihannLeftTexture_;
	int CoinTexture_;
	int ZihannBottom_;
};

