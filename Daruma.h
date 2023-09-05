#pragma once
#include"DxLib.h"
#include<queue>

enum struct Koma
{
	RED,
	BLUE,
	GREEN,
	BLACK
};


class Daruma
{
public:

	void Init();

	void KomaReset();

	void Update();

	void Draw();

private:

	void Order();

	std::queue<Koma> koma;
	std::queue<Koma> orderkoma;

	

};

