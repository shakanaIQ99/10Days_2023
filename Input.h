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
	// �ŐV�̃L�[�{�[�h���p
	char keys[256] = { 0 };
	// 1���[�v(�t���[��)�O�̃L�[�{�[�h���
	char prev[256] = { 0 };

};
