#pragma once
#include"DxLib.h"
#include "Vector2.h"

/// <summary>
/// �^�C�g���V�[��
/// </summary>
class TitleScene
{
public:
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

private:
	//�^�C�g���摜�p�ϐ�
	int title;
	
	Vector2 boxPos;
};

