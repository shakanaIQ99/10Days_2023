#pragma once
#include"struct.h"
#include"Vector2.h"
class Input
{
public:
	Input();

	static Input* GetInstance();

	/// <summary>
	/// キー更新
	/// </summary>
	static void InputUpdate();

	/// <summary>
	/// 押し続けた時
	/// </summary>
	static bool GetKey(int key);
	/// <summary>
	/// 押した時
	/// </summary>
	static bool GetTriggerKey(int key);
	/// <summary>
	/// 離した時
	/// </summary>
	static bool GetReleaseKey(int key);

	static bool GetTriggerMouseLeft();

	static bool GetReleaseMouseLeft();

	static bool GetMouseLeft();

	/// <summary>
	/// BoxTransform構造体で作ったBoxを押してるかの判定
	/// </summary>
	/// <returns></returns>
	static bool GetTriggerMouseLeftButton(BoxTransform box);

	static bool GetMouseHitBox(BoxTransform box);

	static Vector2 GetMousePos();
	
private:
	// 最新のキーボード情報用
	char keys[256] = { 0 };
	// 1ループ(フレーム)前のキーボード情報
	char prev[256] = { 0 };

	bool preMouseLeft = false;
	bool MouseLeft = false;

	Vector2 Mousepos = { 0,0 };
	int mouseX, mouseY;

};
