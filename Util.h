#pragma once
#include"DxLib.h"
#include"Vector2.h"
namespace Util
{

	/// <summary>
	/// �����₷���̂��܂���DrawBox�N
	/// </summary>
	void DrawBox(Vector2 pos, int width, int height, int color, bool fillflag);

	/// <summary>
	/// ���E�㉺�ʁXDrawBox�N(�����g��Ȃ�)
	/// </summary>
	/// <param name="width=��"></param>
	/// <param name="width2=�E"></param>
	/// <param name="height=��"></param>
	/// <param name="height2=��"></param>
	void DrawBox(Vector2 pos, int width,int width2, int height,int height2, int color, bool fillflag);

	/// <summary>
	/// �����₷���̂����܂�RotaGraph
	/// </summary>
	void DrawRotaGraph3(Vector2 pos, double widthRateX, double heightRateX, float Angle, int Ghandle, int TransFlag = 1, int TurnFlag = 0);

	//void DrawExtendGraph(Vector2 pos, Vector2 pos, int width, int height, int color, bool fillflag)

	//��������(��l���z)
	int GetRand(int min, int max);
	float GetRand(float min, float max);
};

