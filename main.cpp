#include "DxLib.h"
#include "Input.h"
#include "GameScene.h"
#include "main.h"
#include "TitleScene.h"
#include<memory>
#include"GameTime.h"
#include"Util.h"
#include "SceneChangeEffect.h"
#include"ResultScene.h"
#include"Score.h"

template<class T> inline void SafeDelete(T*& p)
{
	delete p;
	p = nullptr;
}

enum class SceneNum
{
	TitleScene,
	GameScene,
	ResultScene
};

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
	Daruma::TextureSet();
	Input::SetTexture();
	Score::SetTexture();

	int titleBGM = LoadSoundMem(L"Resources/Music/title.mp3");
	int gameBGM = LoadSoundMem(L"Resources/Music/game.mp3");
	int resultBGM = LoadSoundMem(L"Resources/Music/result.mp3");

	bool isTitleBGM = false;
	bool isGameBGM = false;
	bool isResultBGM = false;

	// ゲームループで使う変数の宣言
	SceneNum scene = SceneNum::TitleScene;

	GameTime::SetMaxTime(120);

	std::unique_ptr<GameScene> gameScene = std::make_unique<GameScene>();
	gameScene->SetTexture();
	gameScene->Init();


	std::unique_ptr<TitleScene> titleScene = std::make_unique<TitleScene>();
	titleScene->SetTexture();
	titleScene->Init();

	std::unique_ptr<ResultScene> resultScene = std::make_unique<ResultScene>();
	resultScene->Init();
	resultScene->SetTexture();

	std::unique_ptr<SceneChangeEffect> sceneChangeEffect;
	sceneChangeEffect.reset(SceneChangeEffect::Create());



	// ゲームループ
	while (true)
	{
		// 最新のキーボード情報だったものは1フレーム前のキーボード情報として保存
		// 最新のキーボード情報を取得
		Input::InputUpdate();

		// 画面クリア
		ClearDrawScreen();
		//---------  ここからプログラムを記述  ----------//

		if (Input::GetTriggerKey(KEY_INPUT_F5))
		{
			Util::debugBool = !Util::debugBool;
		}

		switch (scene)
		{
		case SceneNum::TitleScene:
			StopSoundMem(resultBGM);
			isResultBGM = false;

			if (isTitleBGM == false)
			{
				PlaySoundMem(titleBGM, DX_PLAYTYPE_LOOP);
				isTitleBGM = true;
			}

			if (Input::GetTriggerMouseLeft())
			{
				sceneChangeEffect->EffectStart();
			}

			if (sceneChangeEffect->GetIsChange())
			{
				scene = SceneNum::GameScene;
				gameScene->Init();
				sceneChangeEffect->SetIsSceneChange(false);
			}

			if (!sceneChangeEffect->GetIsEffect())
			{
				//更新処理
				titleScene->Update();
			}

			//描画処理
			titleScene->Draw();

			break;
		case SceneNum::GameScene:
			StopSoundMem(titleBGM);
			isTitleBGM = false;

			if (isGameBGM == false)
			{
				PlaySoundMem(gameBGM, DX_PLAYTYPE_LOOP);
				isGameBGM = true;
			}

			//アルファ値をリセット
			titleScene->Reset();

			if (GameTime::TimeUp())
			{
				sceneChangeEffect->EffectStart();
				StopSoundMem(gameBGM);
			}

			if (sceneChangeEffect->GetIsChange())
			{
				scene = SceneNum::ResultScene;
				resultScene->Init();
				sceneChangeEffect->SetIsSceneChange(false);
			}

			if (!sceneChangeEffect->GetIsEffect())
			{
				//更新処理
				gameScene->Update();
			}

			//描画処理
			gameScene->Draw();


			break;
		case SceneNum::ResultScene:
			isGameBGM = false;

			if (isResultBGM == false)
			{
				PlaySoundMem(resultBGM, DX_PLAYTYPE_LOOP);
				isResultBGM = true;
			}


			if (Input::Input::GetTriggerMouseLeft())
			{
				sceneChangeEffect->EffectStart(true);
			}

			if (sceneChangeEffect->GetIsChange())
			{
				scene = SceneNum::TitleScene;
				titleScene->Init();
				sceneChangeEffect->SetIsSceneChange(false);
			}

			if (!sceneChangeEffect->GetIsEffect())
			{
				//更新処理
				resultScene->Update();
			}

			//描画処理
			resultScene->Draw();


			break;
		}

		sceneChangeEffect->Update();

		sceneChangeEffect->Draw();

		Input::DrawCursor();

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
	}
	// Dxライブラリ終了処理
	InitGraph();
	DxLib_End();

	// 正常終了
	return 0;
}