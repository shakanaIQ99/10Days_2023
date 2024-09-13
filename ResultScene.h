#pragma once
#include"Score.h"

class ResultScene
{
public:

	void SetTexture();

	void Init();

	void Update();

	void Draw();

	void Reset();

	bool GetchangeScene()
	{
		return changeScene;
	}

	void SetGameover()
	{
		gameover_flag = true;
	}

private:
	int GameOverTexture[4];
	int GameClearTexture;

	int loserTexture;

	bool gameover_flag = false;

	int gameovercounttimer = 0;
	const int frame = 10;
	int gameovercount = 0;
	bool changeScene = false;

	float angle = 0;

};

