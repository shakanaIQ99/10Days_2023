#include "Util.h"
#include"DxLib.h"
#include<random>

bool Util::debugBool = false;

void Util::DrawBox(Vector2 pos, int width, int height, int color, bool fillflag)
{
	DxLib::DrawBox((int)pos.x - width, (int)pos.y - height, (int)pos.x + width, (int)pos.y + height, color, fillflag);
}

void Util::DrawBox(Vector2 pos, int width, int width2, int height, int height2, int color, bool fillflag)
{
	DxLib::DrawBox((int)pos.x - width, (int)pos.y - height, (int)pos.x + width2, (int)pos.y + height2, color, fillflag);
}

void Util::DrawJpaneseString(int x, int y, int color, const wchar_t* string)
{

	DrawFormatString(x, y, color, string);
}

void Util::DrawRotaGraph3(Vector2 pos, double widthRateX, double heightRateX, float Angle, int Ghandle, int TransFlag, int TurnFlag)
{

	int sizex, sizey;
	DxLib::GetGraphSize(Ghandle, &sizex, &sizey);

	DxLib::DrawRotaGraph3((int)pos.x, (int)pos.y, sizex/2, sizey/2, widthRateX, heightRateX, Angle, Ghandle, TransFlag, TurnFlag, TurnFlag);

}

void Util::DrawRotaGraph3C(Vector2 pos, int cx, int cy, double widthRateX, double heightRateX, float Angle, int Ghandle, int TransFlag, int TurnFlag)
{
	DxLib::DrawRotaGraph3((int)pos.x, (int)pos.y, cx, cy, widthRateX, heightRateX, Angle, Ghandle, TransFlag, TurnFlag, TurnFlag);

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
	std::uniform_real_distribution<float> distr(min, max);
	return distr(eng);
}
