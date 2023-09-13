#include "GameTime.h"

GameTime* GameTime::GetInstance()
{
	static GameTime instance;
	return &instance;
}

void GameTime::SetTexture()
{
}

void GameTime::Reset()
{
	GameTime* instance = GetInstance();

	instance->GameNowTime = instance->GameMaxTime;
}

void GameTime::SetMaxTime(int Second)
{
	GetInstance()->GameMaxTime = Second * 60;
}

void GameTime::AddTime(int Second)
{
	GetInstance()->GameNowTime += Second * 60;
}

void GameTime::DecreaseTime()
{
	GetInstance()->GameNowTime--;
}

void GameTime::LossTime(int Second)
{
	GetInstance()->GameNowTime -= Second * 60;
}

bool GameTime::TimeUp()
{
	if (GetInstance()->GameNowTime <= 0)
	{
		return true;
	}
	return false;
}

int GameTime::GetNowTime()
{
	return GetInstance()->GameNowTime / 60;
}
