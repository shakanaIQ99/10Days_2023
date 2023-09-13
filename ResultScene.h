#pragma once
#include"Score.h"

class ResultScene
{
public:

	void SetTexture();

	void Init();

	void Update();

	void Draw();

private:

	int HaikeiGHandle = 0;

	int sceneNum = 0;

	int resultScore = 0;

	float timer = 0;
};

