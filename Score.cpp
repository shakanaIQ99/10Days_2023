#include "Score.h"
#include"DxLib.h"
#include"main.h"

Score* Score::GetInstance()
{
    static Score instance;

    return &instance;
}

void Score::SetTexture()
{


}

void Score::Reset()
{
    GetInstance()->gamescore = 0;
}

void Score::AddScore(int AddScoreNum)
{
    GetInstance()->gamescore += AddScoreNum;
}

void Score::Draw()
{
    DrawFormatString(WIN_WIDTH / 2, WIN_HEIGHT / 4, GetColor(255, 255, 255), L"score:%d", GetInstance()->gamescore);
    


}

int Score::GetScore()
{
    return GetInstance()->gamescore;
}
