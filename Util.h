#pragma once
#include"DxLib.h"
#include"Vector2.h"
namespace Util
{

	/// <summary>
	/// �����₷���̂��܂���DrawBox�N
	/// </summary>
	/// <param name="pos"></param>
	/// <param name="width"></param>
	/// <param name="height"></param>
	/// <param name="color"></param>
	/// <param name="fillflag"></param>
	void DrawBox(Vector2 pos, int width, int height, int color, bool fillflag);

	/// <summary>
	/// ���E�㉺�ʁXDrawBox�N(�����g��Ȃ�)
	/// </summary>
	/// <param name="pos"></param>
	/// <param name="width=��"></param>
	/// <param name="width2=�E"></param>
	/// <param name="height=��"></param>
	/// <param name="height2=��"></param>
	/// <param name="color"></param>
	/// <param name="fillflag"></param>
	void DrawBox(Vector2 pos, int width,int width2, int height,int height2, int color, bool fillflag);

};

