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
        Vector2 pos = { 955.0f, 230.0f };
        pos.x = pos.x - (60 * (i - 3));
        int j = scrNum % 10;
        DrawExtendGraph((int)pos.x - 30, (int)pos.y - 64, (int)pos.x + 30, (int)pos.y + 64,GetInstance()->NumGhandle[j], true);
        scrNum /= 10;
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
