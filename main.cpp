#define _SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING

#include "DxLib.h"
#include "Input.h"
#include "main.h"
#include<memory>
#include <cpprest/filestream.h>
#include <cpprest/http_client.h>

using namespace utility;
using namespace web;
using namespace web::http;
using namespace web::http::client;
using namespace concurrency::streams;


template<class T> inline void SafeDelete(T*& p)
{
	delete p;
	p = nullptr;
}


template <class I>

pplx::task<I> Get(const std::wstring& url) {
	return pplx::create_task([=] {
		http_client client(url);

		return client.request(methods::GET);
		}).then([](http_response response) {
			if (response.status_code() == status_codes::OK) {
				return response.extract_json();
			}
			else {
				throw std::runtime_error("Recevived non-OK HTTP status code");
			}
			});
}

pplx::task<int> Post(const std::wstring& url,int Score)
{
	return pplx::create_task([=]
		{
			json::value postData;

			postData[L"score"] = Score;
			http_client client(url);

			return client.request(methods::POST, L"", postData.serialize(), L"application/json");
		})
		.then([](http_response response)
			{
				if (response.status_code() == status_codes::Created)
				{
					return response.extract_json();
				}
				else {
					throw std::runtime_error("Recevived non-OK HTTP status code");
				}
				})
		.then([](json::value json)
			{
				return json[L"status_code"].as_integer();
			});
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

	int score = 0;

	int ranking[5] = {};

	Concurrency::task_status severStatus;


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
			if (Input::GetTriggerKey(KEY_INPUT_SPACE))
			{
				gameScene = 2;
			}
			break;

		case 2:
			if (Input::GetTriggerKey(KEY_INPUT_SPACE))
			{
				gameScene = 1;
				countTime = 0.0f;
			}

			if (1)
			{
				try {
					auto severStatusCode = Post(L"http://localhost:3000/scores/", score).wait();
					if (severStatusCode == 1)
					{
						auto task = Get<json::value>(L"http://localhost:3000/scores/");
						const json::value j = task.get();
						auto array = j.as_array();
						for (int i = 0; i < array.size(); i++)
						{
							ranking[i] = array[i].at(U("score")).as_integer();
						}
					}
				}
				catch(const std::exception& e){
					DrawFormatString(100, 200, GetColor(255, 255, 255), L"Error exception:%s", e.what());
				}
			}
			break;

		}




	
		//描画処理
		switch (gameScene)
		{
		case 0:
			DrawFormatString(100, 200, GetColor(255, 255, 255), L"Count:%f", countTime / 60.0f);
			break;
		case 1:
			if (countTime / 60.0f < 5.0f)
			{
				DrawFormatString(100, 200, GetColor(255, 255, 255), L"Count:%f", countTime / 60.0f);
			}
			break;

		case 2:
			DrawFormatString(100, 200, GetColor(255, 255, 255), L"Count:%f", countTime / 60.0f);
			break;

		}
		


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