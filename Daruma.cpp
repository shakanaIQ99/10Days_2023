#include "Daruma.h"
#include<stdlib.h>
#include"Input.h"
#include"Util.h"

using namespace Util;

void Daruma::Init()
{
	KomaReset();

	//�I�[�_�[�̓�
	Orderhead.height = 32;
	Orderhead.width = 40;
	Orderhead.pos = { 200.0f,400.0f };

	//���ۂ̓�
	Head.pos = { 700.0f,400.0f };
	Head.height = 32;
	Head.width = 40;

	//�I�[�_�[�̃{�f�[
	Orderboxs.width = 32;
	Orderboxs.height = 16;
	Orderboxs.pos = Orderhead.pos;

	//���ۂ̃{�f�[
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
		
		pos.y -= (Orderboxs.height*2) * Orderfloar;
		DrawBox(pos, Orderboxs.width, Orderboxs.height, Color, true);
		DrawBox(pos, Orderboxs.width, Orderboxs.height, GetColor(0, 0, 0), false);

		Orderfloar++;
		
		Orderhead.pos.y = pos.y - (Orderhead.height+Orderboxs.height);
	}
	//DrawBox(Orderhead.pos, Orderhead.width, Orderhead.height, GetColor(0, 0, 0), true);

	int floar = 0;
	Head.pos.y = 400.0f;
	for (auto itr = koma.begin(); itr != koma.end(); itr++)
	{
		SetKomaColor(*itr);

		Vector2 pos = Komaboxs.pos;

		pos.y -= (Komaboxs.height*2) * floar;
		DrawBox(pos, Komaboxs.width, Komaboxs.height, Color, true);
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
	koma.pop_back();
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
