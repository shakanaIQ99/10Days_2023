#pragma once
class Input
{
public:
	Input();

	static Input* GetInstance();

	static void InputUpdate();

	static bool GetKey(int key);
	static bool GetTriggerKey(int key);
	static bool GetReleaseKey(int key);
	
private:
	// 最新のキーボード情報用
	char keys[256] = { 0 };
	// 1ループ(フレーム)前のキーボード情報
	char prev[256] = { 0 };

};
