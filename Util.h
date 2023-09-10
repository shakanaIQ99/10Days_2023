#pragma once
#include"DxLib.h"
#include"Vector2.h"
namespace Util
{

	/// <summary>
	/// 書きやすさのかまたりDrawBox君
	/// </summary>
	void DrawBox(Vector2 pos, int width, int height, int color, bool fillflag);

	/// <summary>
	/// 左右上下別々DrawBox君(多分使わない)
	/// </summary>
	/// <param name="width=左"></param>
	/// <param name="width2=右"></param>
	/// <param name="height=上"></param>
	/// <param name="height2=下"></param>
	void DrawBox(Vector2 pos, int width,int width2, int height,int height2, int color, bool fillflag);

	/// <summary>
	/// 書きやすさのかたまりRotaGraph
	/// </summary>
	void DrawRoTaGraph3(Vector2 pos, double widthRateX, double heightRateX, float Angle, int Ghandle, int TransFlag = 0, int TurnFlag = 0);


	//乱数生成(一様分布)
	int GetRand(int min, int max);
	float GetRand(float min, float max);
};

