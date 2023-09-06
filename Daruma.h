#pragma once
#include"DxLib.h"
#include <vector>
#include"struct.h"

enum struct Koma : int
{
	RED,
	BLUE,
	GREEN,
	YELLOW
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
	void Order();

	int GetKomaColor(Koma a);
private:

	void KomaReset();


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
	
	

};

