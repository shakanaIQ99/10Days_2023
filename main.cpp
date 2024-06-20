#include "DxLib.h"
#include "Input.h"
#include "main.h"
#include<memory>


template<class T> inline void SafeDelete(T*& p)
{
	delete p;
	p = nullptr;
}


int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	//Log.txtを無効
	SetOutApplicationLogValidFlag(FALSE);

	// ウィンドウモードに設定
	ChangeWindowMode(TRUE);

	// ウィンドウサイズを手動では変更させず、
	// かつウィンドウサイズに合わせて拡大できないようにする
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	// タイトルを変更
	SetMainWindowText(TITLE);

	// 画面サイズの最大サイズ、カラービット数を設定(モニターの解像度に合わせる)
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);

	// 画面サイズを設定(解像度との比率で設定)
	SetWindowSizeExtendRate(1.0);

	// 画面の背景色を設定する
	SetBackgroundColor(0xaa, 0xaa, 0xaa);



	// DXlibの初期化
	if (DxLib_Init() == -1) { return -1; }

	// (ダブルバッファ)描画先グラフィック領域は裏面を指定
	SetDrawScreen(DX_SCREEN_BACK);

	// 画像などのリソースデータの変数宣言と読み込み
	

	// ゲームループで使う変数の宣言

	int gameScene = 0;

	float countTime = 0;


	// ゲームループ
	while (true)
	{
		// 最新のキーボード情報だったものは1フレーム前のキーボード情報として保存
		// 最新のキーボード情報を取得
		Input::InputUpdate();

		// 画面クリア
		ClearDrawScreen();
		//---------  ここからプログラムを記述  ----------//


		
		//更新処理

		switch (gameScene)
		{
		case 0:
			if (Input::GetTriggerKey(KEY_INPUT_SPACE))
			{
				gameScene = 1;
			}
			break;
		case 1:
			countTime += 1.0f;

			break;

		case 2:
			if (Input::GetTriggerKey(KEY_INPUT_SPACE))
			{
				gameScene = 1;
				countTime = 0.0f;
			}
			break;

		}




	
		//描画処理

		DrawString(100, 100, L"&f", countTime);


		//---------  ここまでにプログラムを記述  ---------//
		// (ダブルバッファ)裏面
		ScreenFlip();

		// 20ミリ秒待機(疑似60FPS)
		WaitTimer(20);

		// Windowsシステムからくる情報を処理する
		if (ProcessMessage() == -1)
		{
			break;
		}

		// ESCキーが押されたらループから抜ける
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			break;
		}
		/*if (Input::GetTriggerKey(KEY_INPUT_ESCAPE))
		{
			break;
		}*/
	}
	// Dxライブラリ終了処理

	DxLib_End();

	// 正常終了
	return 0;
}