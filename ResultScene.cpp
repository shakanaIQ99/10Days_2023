#include "ResultScene.h"
#include"DxLib.h"
#include"Util.h"
#include"Easing.h"
#include"main.h"
#include"Input.h"
#include "Ease.h"

void ResultScene::SetTexture()
{
	HaikeiGHandle= LoadGraph(L"Resources/Scene/result.png");
}

void ResultScene::Init()
{
	sceneNum = 0;
	resultScore = 0;
	timer = 0;
}

void ResultScene::Update()
{
	if (sceneNum == 0)
	{
		timer++;

		resultScore = static_cast<int>(Ease::OutQuadFloat(0, (float)Score::GetScore(), (float)timer / 120));

		if (timer >= 120)
		{
			timer = 120;
			sceneNum = 1;
		}

		if (Input::GetMouseLeft())
		{
			timer = 120;
			sceneNum = 1;
		}
	}
	if (sceneNum == 1)
	{

	}

	
}

void ResultScene::Draw()
{

	DrawGraph(0, 0, HaikeiGHandle, true);

	int scrNum = resultScore;
	int i = 0;

	while (i < 6)
	{
		Vector2 pos = { WIN_WIDTH * 2 / 3, WIN_HEIGHT / 4 };
		pos.x = pos.x - (32 * (i - 3));
		int j = scrNum % 10;
		DrawGraph(pos.x, pos.y, Score::GetNumGHandle(j), true);
		scrNum /= 10.0f;
		i++;
	}
}
