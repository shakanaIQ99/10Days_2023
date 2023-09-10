#pragma once

class GameTime
{
public:

	static GameTime* GetInstance();

	static void Reset();

	/// <summary>
	/// ƒQ[ƒ€ŠÔ•b”w’è
	/// </summary>
	/// <param name="timer"></param>
	static void SetMaxTime(int timer);
	/// <summary>
	/// •b”w’è‰ÁZ
	/// </summary>
	/// <param name="timeNum"></param>
	static void AddTime(int timeNum);

	static void DecreaseTime();

	/// <summary>
	/// •b”w’èŒ¸Z
	/// </summary>
	/// <param name="timeNum"></param>
	static void LossTime(int timeNum);

	static bool TimeUp();

	static int GetNowTime();


private:

	int GameMaxTime = 0;

	int GameNowTime = 0;

};

