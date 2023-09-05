#pragma once
#include"DxLib.h"
#include"Vector2.h"
namespace Util
{

	/// <summary>
	/// 書きやすさのかまたりDrawBox君
	/// </summary>
	/// <param name="pos"></param>
	/// <param name="width"></param>
	/// <param name="height"></param>
	/// <param name="color"></param>
	/// <param name="fillflag"></param>
	void DrawBox(Vector2 pos, int width, int height, int color, bool fillflag);

	/// <summary>
	/// 左右上下別々DrawBox君(多分使わない)
	/// </summary>
	/// <param name="pos"></param>
	/// <param name="width=左"></param>
	/// <param name="width2=右"></param>
	/// <param name="height=上"></param>
	/// <param name="height2=下"></param>
	/// <param name="color"></param>
	/// <param name="fillflag"></param>
	void DrawBox(Vector2 pos, int width,int width2, int height,int height2, int color, bool fillflag);

};

