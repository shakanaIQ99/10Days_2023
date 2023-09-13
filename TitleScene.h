#pragma once
#include"DxLib.h"
#include "Vector2.h"

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

private:
	//タイトル画像用変数
	static int title;
	int color;
	int alphaNum = 255;

	Vector2 boxPos;
};

