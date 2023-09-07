#include "Daruma.h"
#include<stdlib.h>
#include"Input.h"
#include"Util.h"


using namespace Util;

void Daruma::Init()
{
	KomaReset();

	//オーダーの頭
	Orderhead.height = 32;
	Orderhead.width = 40;
	Orderhead.pos = { 200.0f,400.0f };

	//実際の頭
	Head.pos = { 700.0f,400.0f };
	Head.height = 32;
	Head.width = 40;

	//オーダーのボデー
	Orderboxs.width = 32;
	Orderboxs.height = 16;
	Orderboxs.pos = Orderhead.pos;

	//実際のボデー
	Komaboxs.width = 32;
	Komaboxs.height = 16;
	Komaboxs.pos = Head.pos;


}

void Daruma::KomaReset()
{
	koma.clear();
	orderkoma.clear();

}

void Daruma::Update()
{
	if (Input::GetTriggerKey(KEY_INPUT_R) || Comparison())
	{
		Order();
	}

	// 吹っ飛ばす演出
	if (isSlap)
	{
		koma.pop_back();
		isSlap = false;
	}

}

void Daruma::Draw()
{
	int Orderfloar = 0;
	for (auto itr = orderkoma.rbegin(); itr != orderkoma.rend(); itr++)
	{
		Vector2 pos = Orderboxs.pos;

		pos.y -= (Orderboxs.height * 2) * Orderfloar;
		DrawBox(pos, Orderboxs.width, Orderboxs.height, GetKomaColor(*itr), true);
		DrawBox(pos, Orderboxs.width, Orderboxs.height, GetColor(0, 0, 0), false);

		Orderfloar++;

		Orderhead.pos.y = pos.y - (Orderhead.height + Orderboxs.height);
	}
	//DrawBox(Orderhead.pos, Orderhead.width, Orderhead.height, GetColor(0, 0, 0), true);

	int floar = 0;
	Head.pos.y = 400.0f;
	for (auto itr = koma.rbegin(); itr != koma.rend(); itr++)
	{
		Vector2 pos = Komaboxs.pos;

		pos.y -= (Komaboxs.height * 2) * floar;
		DrawBox(pos, Komaboxs.width, Komaboxs.height, GetKomaColor(*itr), true);
		DrawBox(pos, Komaboxs.width, Komaboxs.height, GetColor(0, 0, 0), false);

		floar++;
		Head.pos.y = pos.y - (Head.height + Komaboxs.height);
	}
	DrawBox(Head.pos, Head.width, Head.height, GetColor(0, 0, 0), true);

}

void Daruma::ClickAddKoma(Koma add)
{
	koma.push_back(add);
}

void Daruma::ClickRemoveKoma()
{
	isSlap = true;
}

BoxTransform Daruma::GetKomaTransform()
{
	return Komaboxs;
}

BoxTransform Daruma::GetHead()
{
	return Head;
}

bool Daruma::GetBeKoma()
{
	if (!koma.empty())
	{
		return true;
	}
	return false;
}

void Daruma::HeadReset()
{
	koma.clear();
}

void Daruma::Order()
{
	KomaReset();

	OrderRange = GetRand(3, 6);
	//OrderRange = 6;
	OrderNum = 0;

	while (OrderNum < OrderRange)
	{
		Koma AddKoma = static_cast<Koma>(GetRand(0, sizeof(Koma)));

		orderkoma.push_back(AddKoma);

		OrderNum++;

	}

	Ordered = true;

}

int Daruma::GetKomaColor(Koma a)
{
	switch (a)
	{
	case Koma::RED:
		return GetColor(255, 0, 0);
	case Koma::BLUE:
		return GetColor(0, 0, 255);
	case Koma::GREEN:
		return GetColor(0, 255, 0);
	case Koma::BLACK:
		return GetColor(255, 255, 255);
	}

	return GetColor(255, 255, 255);
}

bool Daruma::Comparison()
{

	if (koma.size() == orderkoma.size())
	{
		size_t clearNum = orderkoma.size();
		for (int i = 0; i < orderkoma.size(); i++)
		{
			if (koma[i] == orderkoma[i])
			{
				clearNum--;
			}
			if (clearNum <= 0)
			{
				return true;
			}
		}
	}
	return false;
}
