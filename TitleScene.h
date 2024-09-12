#pragma once
#include"DxLib.h"
#include "Vector2.h"
#include"struct.h"

/// <summary>
/// タイトルシーン
/// </summary>
class TitleScene
{
private:
	int width = 1280;
	int height = 720;



public:

	void SetTexture();
	/// <summary>
	/// 初期化
	/// </summary>
	void Init();

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	/// <summary>
	/// リセット関数
	/// </summary>
	void Reset();

	bool GetOpenExe()
	{
		return openExe;
	}


private:

	int fileIconTexturep;

	bool openExe = false;

	bool doubleClick = false;
	int doubleClickTimer = 0;

	bool next = false;

	BoxTransform startExe;

	int BackGroundTexture;

	int exeTexture;

};