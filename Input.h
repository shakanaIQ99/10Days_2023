#pragma once
#include"struct.h"
#include"Vector2.h"
class Input
{
public:

	static void SetTexture();

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

	static bool GetTriggerMouseLeft();

	static bool GetReleaseMouseLeft();

	static bool GetMouseLeft();

	/// <summary>
	/// BoxTransform�\���̂ō����Box�������Ă邩�̔���
	/// </summary>
	/// <returns></returns>
	static bool GetTriggerMouseLeftButton(BoxTransform box);

	static bool GetMouseHitBox(BoxTransform box);

	static Vector2 GetMousePos();

	static void DrawCursor();

	static void SetChengeCursor(bool isHanmmer_1);
	
private:
	// �ŐV�̃L�[�{�[�h���p
	char keys[256] = { 0 };
	// 1���[�v(�t���[��)�O�̃L�[�{�[�h���
	char prev[256] = { 0 };

	bool preMouseLeft = false;
	bool MouseLeft = false;

	Vector2 Mousepos = { 0,0 };
	int mouseX, mouseY;

	int GraphHandle[2];

	bool isHanmmer = false;

};
