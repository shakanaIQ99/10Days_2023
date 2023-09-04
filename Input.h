#pragma once
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
	
private:
	// 最新のキーボード情報用
	char keys[256] = { 0 };
	// 1ループ(フレーム)前のキーボード情報
	char prev[256] = { 0 };

};
