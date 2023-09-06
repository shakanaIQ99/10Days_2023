#include "Util.h"
#include"DxLib.h"
#include<random>
void Util::DrawBox(Vector2 pos, int width, int height, int color, bool fillflag)
{
	DxLib::DrawBox((int)pos.x - width, (int)pos.y - height, (int)pos.x + width, (int)pos.y + height, color, fillflag);
}

void Util::DrawBox(Vector2 pos, int width, int width2, int height, int height2, int color, bool fillflag)
{
	DxLib::DrawBox((int)pos.x - width, (int)pos.y - height, (int)pos.x + width2, (int)pos.y + height2, color, fillflag);
}

int Util::GetRand(int min, int max)
{
	std::random_device rd;
	std::default_random_engine eng(rd());
	std::uniform_int_distribution<> distr(min, max);
	return distr(eng);
}

float Util::GetRand(float min, float max)
{
	std::random_device rd;
	std::default_random_engine eng(rd());
	std::uniform_int_distribution<> distr(min, max);
	return distr(eng);
}
