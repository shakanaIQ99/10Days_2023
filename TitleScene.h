#pragma once
#include"DxLib.h"
#include "Vector2.h"

/// <summary>
/// タイトルシーン
/// </summary>
class TitleScene
{
public:
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

private:
	//タイトル画像用変数
	int title;
	
	Vector2 boxPos;
	int width = 100;
	int height = 100;
};

