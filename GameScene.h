#pragma once
#include"DxLib.h"
#include "BaseGame.h"
#include <memory>

class GameScene
{
public:

	void Init();

	void Update();

	void Draw();

	void SetTexture();

private:
	/*std::unique_ptr<BaseGame> baseGame_ = nullptr;*/

	int BackGroundTexture;
	
};

