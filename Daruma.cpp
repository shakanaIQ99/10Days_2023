#include "Daruma.h"
#include<stdlib.h>
#include"Input.h"


void Daruma::Init()
{
	KomaReset();



}

void Daruma::KomaReset()
{
	koma.clear();
	orderkoma.clear();

}

void Daruma::Update()
{
	if (Input::GetTriggerKey(KEY_INPUT_R))
	{
		Order();
	}



}

void Daruma::Draw()
{
	int floar = 0;
	for (auto itr = orderkoma.begin(); itr !=orderkoma.end(); itr++)
	{
		SetKomaColor(*itr);
		
		DrawBox(1280 / 2 - 32, 600 - 16 -(32* floar), 1280 / 2 + 32, 600 + 16 - (32 * floar), Color, false);

		floar++;
	}


}

void Daruma::Order()
{
	KomaReset();

	//OrderRange = rand() % 3 + 3;
	OrderRange = 6;
	OrderNum = 0;

	while (OrderNum<OrderRange)
	{
		Koma AddKoma = static_cast<Koma>(rand() % sizeof(Koma) );

		orderkoma.push_back(AddKoma);

		OrderNum++;

	}

	Ordered = true;

}

void Daruma::SetKomaColor(Koma a)
{
	switch (a)
	{
	case Koma::RED:
		Color= GetColor(255, 0, 0);
		break;
	case Koma::BLUE:
		Color = GetColor(0, 0, 255);
		break;
	case Koma::GREEN:
		Color = GetColor(0, 255, 0);
		break;
	case Koma::BLACK:
		Color = GetColor(255, 255, 255);
		break;
	}
}
