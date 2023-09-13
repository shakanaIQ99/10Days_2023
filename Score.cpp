#include "Score.h"
#include"DxLib.h"
#include"main.h"
#include"Util.h"
Score* Score::GetInstance()
{
    static Score instance;

    return &instance;
}

void Score::SetTexture()
{
    Score* instance = GetInstance();

    LoadDivGraph(L"Resources/Number/number.png", 10, 10, 1, 32, 64, instance->NumGhandle);

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

    int scrNum = GetScore();
    int i = 0;
    
    while (i < 6)
    {
        Vector2 pos = { 985.0f, 250.0f };
        pos.x = pos.x - (32 * (i - 3));
        int j = scrNum % 10;
        DrawGraph(pos.x, pos.y,GetInstance()->NumGhandle[j], true);
        scrNum /= 10.0f;
        i++;
    }
}

int Score::GetScore()
{
    return GetInstance()->gamescore;
}

int Score::GetNumGHandle(int num)
{
    return GetInstance()->NumGhandle[num];
}
