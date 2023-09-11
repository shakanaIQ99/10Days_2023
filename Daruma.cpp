#include "Daruma.h"
#include<stdlib.h>
#include"Input.h"
#include"Util.h"


using namespace Util;

int Daruma::darumaFace;
int Daruma::KomaGraph[sizeof(Koma)];

void Daruma::TextureSet()
{
	darumaFace = LoadGraph(L"Resources/Daruma/daruma01.png");

	LoadDivGraph(L"Resources/Daruma/koma.png", sizeof(Koma), sizeof(Koma), 1, 64, 32,KomaGraph);


}
void Daruma::SetCatchOn(bool catchflag)
{
	CacthFlag = catchflag;
}
std::vector<Koma> Daruma::GetKomas()
{
	std::vector<Koma> prekoma = koma;

	return prekoma;
}

void Daruma::SlapEffect()
{
	int floar = 0;
	for (auto itr = koma.rbegin(); itr != koma.rend(); itr++)
	{
		Vector2 pos = Komaboxs.pos;

		pos.y -= (Komaboxs.height * 2) * floar;

		std::unique_ptr<SlapKoma> newSlapKoma;
		newSlapKoma.reset(SlapKoma::Create(pos, GetKomaColor(*itr), { (float)Util::GetRand(-16,16),20 }));
		slapKomas.push_back(std::move(newSlapKoma));

		floar++;
	}

	std::unique_ptr<SlapHead> newSlapHead;
	newSlapHead.reset(SlapHead::Create(Head.pos, darumaFace, { 20,20 }));
	slapHeads.push_back(std::move(newSlapHead));
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
	Orderboxs.height = 32;
	Orderboxs.pos = { Head.pos.x - 120.0f,pos.y };

	//実際のボデー
	Komaboxs.width = KomaWidth;
	Komaboxs.height = KomaHeight;
	Komaboxs.pos = Head.pos;

	DragAndDropArea.width = 64 * 2;
	DragAndDropArea.height = Head.height * 5;
	DragAndDropArea.pos = { pos.x,pos.y + KomaHeight - DragAndDropArea.height+40.0f };

	angryEffect.reset(AngryEffect::Create());

	comitEffect.reset(PileEffect::Create());
}

void Daruma::KomaReset()
{
	koma.clear();
	orderkoma.clear();
}

void Daruma::Reaction()
{
	CursorHead = 0.0;
	CursorKoma = 0.0;
	CursorCatch = 0.0f;

	if (CacthFlag)
	{
		if (Input::GetMouseHitBox(DragAndDropArea) && !MaxKoma())
		{
			CursorHead = 0.3;
			CursorKoma = 0.3;
			CursorCatch = 0.3f;
		}
	}
	else
	{
		if (Input::GetMouseHitBox(GetKomaTransform()))
		{
			CursorKoma = 0.3;
		}
		if (Input::GetMouseHitBox(GetHead()))
		{
			CursorHead = 0.3;
		}
	}
	


}

void Daruma::Update()
{
	if (Input::GetTriggerKey(KEY_INPUT_R) || Comparison())
	{
		comitEffect->FanfarleSet();
		Order();
	}

	Reaction();

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
	slapHeads.remove_if([](std::unique_ptr<SlapHead>& slapHead) {return slapHead->GetIsDead(); });

	for (std::unique_ptr<SlapKoma>& slapKoma : slapKomas)
	{
		slapKoma->Update();
	}

	for (std::unique_ptr<SlapHead>& slapHead : slapHeads)
	{
		slapHead->Update();
	}

	comitEffect->Update();

	angryEffect->Update();
}

void Daruma::Draw()
{
	int Orderfloar = 0;
	for (auto itr = orderkoma.rbegin(); itr != orderkoma.rend(); itr++)
	{
		Vector2 pos = Orderboxs.pos;

		pos.y -= (Orderboxs.height) * Orderfloar;
		DrawRotaGraph3(pos, Komasize-0.6, Komasize-0.6, 0, GetKomaColor(*itr));
		
		Orderfloar++;

	}
	
	int floar = 0;
	Head.pos.y = defY-KomaHeight;
	for (auto itr = koma.rbegin(); itr != koma.rend(); itr++)
	{
		Vector2 pos = Komaboxs.pos;

		pos.y -= (Komaboxs.height * 2) * floar;
		if (floar == 0)
		{
			DrawRotaGraph3(pos, Komasize + CursorKoma, Komasize + CursorKoma, 0, GetKomaColor(*itr));
		}
		else
		{
			DrawRotaGraph3(pos, Komasize+ CursorCatch, Komasize+ CursorCatch, 0, GetKomaColor(*itr));
		}

		floar++;
		Head.pos.y = pos.y - (Head.height + Komaboxs.height);
	}
	//DrawBox(Head.pos, Head.width, Head.height, GetColor(0, 0, 0), true);
	//DrawGraph(Head.pos.x - Head.width - 5, Head.pos.y - Head.height - 5, darumaFace, TRUE);
	DrawRotaGraph3(Head.pos, 1.0+CursorHead, 1.0 + CursorHead, 0, darumaFace);

	for (std::unique_ptr<SlapKoma>& slapKoma : slapKomas)
	{
		slapKoma->Draw();
	}

	for (std::unique_ptr<SlapHead>& slapHead : slapHeads)
	{
		slapHead->Draw();
	}

	DrawBox(DragAndDropArea.pos, DragAndDropArea.width, DragAndDropArea.height, GetColor(20, 120, 255), false);

	if(debugBool)DrawBox(DragAndDropArea.pos, DragAndDropArea.width, DragAndDropArea.height, GetColor(20, 120, 255), false);

	comitEffect->Draw();

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
	newSlapKoma.reset(SlapKoma::Create(GetKomaTransform().pos, GetKomaColor(koma.back()), { 8,20 }));
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
