#pragma once
class Score
{
public:

	static Score* GetInstance();

	static void SetTexture();

	static void Reset();

	static void AddScore(int AddScoreNum);

	static void Draw();

	static int GetScore();

	static int GetNumGHandle(int num);

private:

	int gamescore = 0;

	int DrawScore = 0;

	int NumGhandle[10];


};

