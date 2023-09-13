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

private:

	int gamescore = 0;

	int NumGhandle[10];


};

