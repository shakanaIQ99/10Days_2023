#include "Daruma.h"
#include<stdlib.h>
#include"Input.h"
#include"Util.h"

using namespace Util;

void Daruma::Init()
{
	KomaReset();
	head.height = 32;
	head.width = 40;

	Orderboxs.width = 32;
	Orderboxs.height = 16;

	Orderboxs.pos = { 200.0f,600.0f };
	head.pos = { 200.0f,600.0f };

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
	int Orderfloar = 0;
	for (auto itr = orderkoma.begin(); itr !=orderkoma.end(); itr++)
	{
		SetKomaColor(*itr);
		Vector2 pos = Orderboxs.pos;
		
		pos.y -= 32 * Orderfloar;
		DrawBox(pos, Orderboxs.width, Orderboxs.height, Color, true);
		DrawBox(pos, Orderboxs.width, Orderboxs.height, GetColor(0, 0, 0), false);

		Orderfloar++;
		
		head.pos.y = pos.y - (head.height+Orderboxs.height);
	}
	DrawBox(head.pos, head.width, head.height, GetColor(0, 0, 0), true);

	/*int floar = 0;
	for (auto itr = koma.begin(); itr != koma.end(); itr++)
	{
		SetKomaColor(*itr);

		DrawBox(1280 / 2 - 32, 600 - 16 - (32 * floar), 1280 / 2 + 32, 600 + 16 - (32 * floar), Color, true);

		floar++;
	}*/


}

void Daruma::ClickAddKoma(Koma add)
{
	koma.push_back(add);
}

void Daruma::ClickRemoveKoma()
{
	koma.pop_back();
}

void Daruma::Order()
{
	KomaReset();

	OrderRange = rand() % 4 + 3;
	//OrderRange = 6;
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
