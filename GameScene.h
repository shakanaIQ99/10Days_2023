#pragma once
#include"DxLib.h"
#include "BaseGame.h"
#include <memory>

class GameScene
{
public:

	void Init();

	void Update();

	void Reset();

	void Draw();

	void SetTexture();

	bool GetEnd()
	{
		return endFlag;
	}

private:
	/*std::unique_ptr<BaseGame> baseGame_ = nullptr;*/

	int BackGroundTexture;

	bool endFlag = false;
	
	int makeGameNum;
	
};

