#include "Daruma.h"
#include<stdlib.h>
#include"Input.h"
#include"Util.h"
#include"Score.h"
#include"GameTime.h"
#include "Audience.h"

#include "Light.h"

using namespace Util;

int Daruma::darumaFace;
int Daruma::KomaGraph[sizeof(Koma)];
int Daruma::DressGraph[sizeof(Dress)];

void Daruma::TextureSet()
{
	darumaFace = LoadGraph(L"Resources/Daruma/daruma01.png");

	LoadDivGraph(L"Resources/Daruma/komaColor.png", sizeof(Koma), sizeof(Koma), 1, 64, 32,KomaGraph);

	LoadDivGraph(L"Resources/Daruma/costume.png", sizeof(Dress), sizeof(Dress), 1, 64, 32, DressGraph);


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

void Daruma::Init(Vector2 pos, bool mode)
{
	KomaReset();
	DressReset();

	for (size_t i = 0; i < sizeof(Koma); i++)
	{
		colorCount[i] = 0;
	}

	DressMode = mode;

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

void Daruma::DressReset()
{

	huku.clear();
	orderhuku.clear();
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
		if (Input::GetMouseHitBox(GetHead())&&!DressMode)
		{
			CursorHead = 0.3;
		}
	}
	


}

void Daruma::Update()
{

	if (DressMode)
	{
		if (DressComparison() && KomaComparison())
		{
			comitEffect->FanfarleSet();
			Order();
			Score::AddScore(5000);
			GameTime::AddTime(15);
			Audience::SetIsCheers(true);
		}
		else if (DressComparison())
		{
			float hogePosX = 60;
			float hogePosY = 20;
			for (size_t i = 0; i < 2; i++)
			{
				comitEffect->SmallCracker({ Head.pos.x + hogePosX,530.0f + hogePosY });
				comitEffect->SmallCracker({ Head.pos.x - hogePosX,530.0f + hogePosY });
				hogePosX *= 2;
				hogePosY -= hogePosY;
			}
			comitEffect->FanfarleSet();
			Score::AddScore(500 * WagamamaMacthColor());
			GameTime::AddTime(3 * WagamamaMacthColor());
			Order();
			Score::AddScore(300);
			GameTime::AddTime(5);
			Audience::SetIsCheers();
		}
	}
	else
	{
		if (KomaComparison())
		{
			float hogePosX = 60;
			float hogePosY = 20;
			for (size_t i = 0; i < 2; i++)
			{
				comitEffect->SmallCracker({ Head.pos.x + hogePosX,530.0f + hogePosY });
				comitEffect->SmallCracker({ Head.pos.x - hogePosX,530.0f + hogePosY });
				hogePosX *= 2;
				hogePosY -= hogePosY;
			}
			Order();
			Score::AddScore(300);
			GameTime::AddTime(5);
			Audience::SetIsCheers();
			Light::SetRot();
		}
	}
	

	Reaction();

	// 吹っ飛ばす演出
	if (isSlap)
	{
		koma.pop_back();
		if (DressMode)
		{
			huku.pop_back();
		}
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
	if (DressMode)
	{
		int OrderDressfloar = 0;
		for (auto itr = orderhuku.rbegin(); itr != orderhuku.rend(); itr++)
		{
			Vector2 pos = Orderboxs.pos;

			pos.y -= (Orderboxs.height) * OrderDressfloar;
			DrawRotaGraph3(pos, Komasize - 0.6, Komasize - 0.6, 0, GetDress(*itr));


			OrderDressfloar++;

		}
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
	
	int Dressfloar = 0;
	for (auto itr = huku.rbegin(); itr != huku.rend(); itr++)
	{
		Vector2 pos = Komaboxs.pos;

		pos.y -= (Komaboxs.height * 2) * Dressfloar;
		if (Dressfloar == 0)
		{
			DrawRotaGraph3(pos, Komasize + CursorKoma, Komasize + CursorKoma, 0, GetDress(*itr));
		}
		else
		{
			DrawRotaGraph3(pos, Komasize + CursorCatch, Komasize + CursorCatch, 0, GetDress(*itr));
		}

		Dressfloar++;
	}
	
	DrawRotaGraph3(Head.pos, 1.0+CursorHead, 1.0 + CursorHead, 0, darumaFace);

	for (std::unique_ptr<SlapKoma>& slapKoma : slapKomas)
	{
		slapKoma->Draw();
	}

	for (std::unique_ptr<SlapHead>& slapHead : slapHeads)
	{
		slapHead->Draw();
	}

	

	if (debugBool)
	{
		DrawBox(DragAndDropArea.pos, DragAndDropArea.width, DragAndDropArea.height, GetColor(20, 120, 255), false);
	}

	comitEffect->Draw();

	angryEffect->Draw();
}

void Daruma::ClickAddKoma(Koma add)
{
	koma.push_back(add);
}

void Daruma::ClickAddDress(Dress add)
{
	if(DressMode)huku.push_back(add);
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

	if (DressMode)
	{
		DressOrder();
	}
	

	OrderRange = 4;
	OrderNum = 0;

	for (size_t i = 0; i < sizeof(Koma); i++)
	{
		colorCount[i] = 0;
	}

	while (OrderNum < OrderRange)
	{
		Koma AddKoma = static_cast<Koma>(GetRand(0, sizeof(Koma)-1));

		switch (AddKoma)
		{
		case Koma::RED:
			colorCount[0]++;
			break;
		case Koma::BLUE:
			colorCount[1]++;
			break;
		case Koma::GREEN:
			colorCount[2]++;
			break;
		case Koma::YELLOW:
			colorCount[3]++;
			break;
		}

		for (size_t i = 0; i < sizeof(Koma); i++)
		{
			if (i == (int)AddKoma)
			{
				if (colorCount[i] < 3)
				{
					orderkoma.push_back(AddKoma);
					OrderNum++;
					break;
				}
			}
		}
		
			
	}

	Ordered = true;

}

void Daruma::DressOrder()
{
	DressReset();

	for (int i = 0; i < sizeof(Dress); i++)
	{
		orderhuku.push_back(static_cast<Dress>(i));
	}

	DressOrdered = true;
}

int Daruma::GetKomaColor(Koma a)
{
	return KomaGraph[(int)a];
}

int Daruma::GetDress(Dress a)
{
	return DressGraph[(int)a];
}



bool Daruma::DressComparison()
{
	if (huku.size() == orderhuku.size())
	{
		size_t clearNum = orderhuku.size();
		for (int i = 0; i < orderhuku.size(); i++)
		{
			if (huku[i] == orderhuku[i])
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

bool Daruma::KomaComparison()
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

int Daruma::WagamamaMacthColor()
{
	int clearNum = 0;
	if (koma.size() == orderkoma.size())
	{
		
		for (int i = 0; i < orderkoma.size(); i++)
		{
			if (koma[i] == orderkoma[i])
			{
				clearNum++;
			}
			
		}
	}

	return clearNum;
}
