#pragma once

class GameTime
{
public:

	static GameTime* GetInstance();

	static void Reset();

	/// <summary>
	/// �Q�[�����ԕb���w��
	/// </summary>
	/// <param name="timer"></param>
	static void SetMaxTime(int timer);
	/// <summary>
	/// �b���w����Z
	/// </summary>
	/// <param name="timeNum"></param>
	static void AddTime(int timeNum);

	static void DecreaseTime();

	/// <summary>
	/// �b���w�茸�Z
	/// </summary>
	/// <param name="timeNum"></param>
	static void LossTime(int timeNum);

	static bool TimeUp();

	static int GetNowTime();


private:

	int GameMaxTime = 0;

	int GameNowTime = 0;

};

