#pragma once

class GameTime
{
public:

	static GameTime* GetInstance();

	static void SetTexture();

	static void Reset();

	/// <summary>
	/// ゲーム時間秒数指定
	/// </summary>
	/// <param name="timer"></param>
	static void SetMaxTime(int timer);
	/// <summary>
	/// 秒数指定加算
	/// </summary>
	/// <param name="timeNum"></param>
	static void AddTime(int timeNum);

	static void DecreaseTime();

	/// <summary>
	/// 秒数指定減算
	/// </summary>
	/// <param name="timeNum"></param>
	static void LossTime(int timeNum);

	static bool TimeUp();

	static int GetNowTime();


private:

	int GameMaxTime = 0;

	int GameNowTime = 0;

};

