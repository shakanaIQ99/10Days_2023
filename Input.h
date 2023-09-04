#pragma once
class Input
{
public:
	Input();

	static Input* GetInstance();

	/// <summary>
	/// �L�[�X�V
	/// </summary>
	static void InputUpdate();

	/// <summary>
	/// ������������
	/// </summary>
	static bool GetKey(int key);
	/// <summary>
	/// ��������
	/// </summary>
	static bool GetTriggerKey(int key);
	/// <summary>
	/// ��������
	/// </summary>
	static bool GetReleaseKey(int key);
	
private:
	// �ŐV�̃L�[�{�[�h���p
	char keys[256] = { 0 };
	// 1���[�v(�t���[��)�O�̃L�[�{�[�h���
	char prev[256] = { 0 };

};
