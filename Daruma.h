#pragma once
#include"DxLib.h"
#include <vector>
#include"struct.h"

enum struct Koma : int
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


	void Update();

	void Draw();

	void ClickAddKoma(Koma add);
	void ClickRemoveKoma();

	BoxTransform GetKomaTransform();
	BoxTransform GetHead();

	bool GetBeKoma();

	void HeadReset();

private:

	void KomaReset();
	void Order();

	void SetKomaColor(Koma a);

	bool Comparison();

	BoxTransform Orderboxs;
	BoxTransform Orderhead;
	BoxTransform Head;
	BoxTransform Komaboxs;

	std::vector<Koma> koma;
	std::vector<Koma> orderkoma;
	//óvãÅÇ∑ÇÈãÓÇÃçÇÇ≥
	int OrderRange = 0;
	//ç°ãÓÇ™âΩíiñ⁄Ç©
	int OrderNum = 0;

	bool Ordered = false;
	
	int Color = GetColor(0, 0, 0);

};

