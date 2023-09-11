#include "Daruma.h"
#include<stdlib.h>
#include"Input.h"
#include"Util.h"


using namespace Util;

int Daruma::darumaFace;
int Daruma::KomaGraph[sizeof(Koma)];

void Daruma::TextureSet()
{
	darumaFace = LoadGraph(L"Resources/Daruma/daruma03.png");

	LoadDivGraph(L"Resources/Daruma/koma.png", sizeof(Koma), sizeof(Koma), 1, 64, 32,KomaGraph);


}
void Daruma::Init(Vector2 pos)
{
	KomaReset();

	defY = pos.y;

	//実際の頭
	Head.pos = pos;
	Head.height = HeadHeight;
	Head.width = HeadWidth;

	//オーダーのボデ
	Orderboxs.width = KomaWidth;
	Orderboxs.height = KomaHeight;
	Orderboxs.pos = { Head.pos.x - 120.0f,pos.y };

	//実際のボデー
	Komaboxs.width = KomaWidth;
	Komaboxs.height = KomaHeight;
	Komaboxs.pos = Head.pos;

	DragAndDropArea.width = Head.width * 2;
	DragAndDropArea.height = Head.height * 5;
	DragAndDropArea.pos = { pos.x,pos.y + KomaHeight - DragAndDropArea.height };


	angryEffect.reset(AngryEffect::Create());

	

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

	if (Input::GetTriggerKey(KEY_INPUT_1))
	{
		angryEffect->Set(Head.pos, { (float)Head.width,(float)Head.height });
	}

	slapKomas.remove_if([](std::unique_ptr<SlapKoma>& slapKoma) {return slapKoma->GetIsDead(); });

	for (std::unique_ptr<SlapKoma>& slapKoma : slapKomas)
	{
		slapKoma->Update();
	}

	angryEffect->Update();
}

void Daruma::Draw()
{
	int Orderfloar = 0;
	for (auto itr = orderkoma.rbegin(); itr != orderkoma.rend(); itr++)
	{
		Vector2 pos = Orderboxs.pos;

		pos.y -= (Orderboxs.height * 2) * Orderfloar;
		//DrawBox(pos, Orderboxs.width, Orderboxs.height, GetKomaColor(*itr), true);
		DrawRotaGraph3(pos, 1.6, 1.6, 0, GetKomaColor(*itr));
		//DrawBox(pos, Orderboxs.width, Orderboxs.height, GetColor(0, 0, 0), false);

		Orderfloar++;

	}
	
	int floar = 0;
	Head.pos.y = defY-KomaHeight;
	for (auto itr = koma.rbegin(); itr != koma.rend(); itr++)
	{
		Vector2 pos = Komaboxs.pos;

		pos.y -= (Komaboxs.height * 2) * floar;
		//DrawBox(pos, Komaboxs.width, Komaboxs.height, GetKomaColor(*itr), true);
		DrawRotaGraph3(pos, 1.6, 1.6, 0, GetKomaColor(*itr));
		//DrawBox(pos, Komaboxs.width, Komaboxs.height, GetColor(0, 0, 0), false);

		floar++;
		Head.pos.y = pos.y - (Head.height + Komaboxs.height);
	}
	//DrawBox(Head.pos, Head.width, Head.height, GetColor(0, 0, 0), true);
	DrawGraph(Head.pos.x - Head.width - 5, Head.pos.y - Head.height - 5, darumaFace, TRUE);

	for (std::unique_ptr<SlapKoma>& slapKoma : slapKomas)
	{
		slapKoma->Draw();
	}
	DrawBox(DragAndDropArea.pos, DragAndDropArea.width, DragAndDropArea.height, GetColor(20, 120, 255), false);

	angryEffect->Draw();
}

void Daruma::ClickAddKoma(Koma add)
{
	koma.push_back(add);
}

void Daruma::ClickRemoveKoma()
{
	isSlap = true;

	std::unique_ptr<SlapKoma> newSlapKoma;
	newSlapKoma.reset(SlapKoma::Create(GetKomaTransform().pos,GetKomaColor(koma.back())));
	slapKomas.push_back(std::move(newSlapKoma));
}

BoxTransform Daruma::GetKomaTransform()
{
	return Komaboxs;
}

BoxTransform Daruma::GetHead()
{
	return Head;
}

BoxTransform Daruma::GetDragAndDropArea()
{
	return DragAndDropArea;
}

bool Daruma::GetBeKoma()
{
	if (!koma.empty())
	{
		return true;
	}
	return false;
}

bool Daruma::MaxKoma()
{
	if (koma.size() < 8)
	{
		return false;
	}
	return true;
}

void Daruma::HeadReset()
{
	koma.clear();
}

void Daruma::Order()
{
	KomaReset();

	OrderRange = 4;
	OrderNum = 0;

	while (OrderNum < OrderRange)
	{
		Koma AddKoma = static_cast<Koma>(GetRand(0, sizeof(Koma)-1));

		orderkoma.push_back(AddKoma);

		OrderNum++;

	}

	Ordered = true;

}

int Daruma::GetKomaColor(Koma a)
{
	return KomaGraph[(int)a];
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
