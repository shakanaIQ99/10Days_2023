#pragma once
#include"DxLib.h"
#include "Vector2.h"

/// <summary>
/// �^�C�g���V�[��
/// </summary>
class TitleScene
{
private:
	int width = 1280;
	int height = 720;

public:

	static void SetTexture();
	/// <summary>
	/// ������
	/// </summary>
	void Init();

	/// <summary>
	/// �X�V
	/// </summary>
	void Update();

	/// <summary>
	/// �`��
	/// </summary>
	void Draw();

	/// <summary>
	/// ���Z�b�g�֐�
	/// </summary>
	void Reset();

private:
	//�^�C�g���摜�p�ϐ�
	static int title;
	static int click;

	int color;
	int alphaNum = 255;

	Vector2 boxPos;
};

