#pragma once
#include "BaseGame.h"
#include "Input.h"

class KusogakiGame : public BaseGame
{
public:
	KusogakiGame(const Vector2& pos = { WIN_WIDTH / 2,WIN_HEIGHT / 2 });
	~KusogakiGame();
	void Init() override;
	void Update() override;
	void Draw() override;

private:
	Input* input_ = nullptr;
};

