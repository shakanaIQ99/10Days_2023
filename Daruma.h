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

private:

	void KomaReset();
	void Order();

	void SetKomaColor(Koma a);

	BoxTransform Orderboxs;
	BoxTransform head;
	BoxTransform Komaboxs;

	std::vector<Koma> koma;
	std::vector<Koma> orderkoma;
	//要求する駒の高さ
	int OrderRange = 0;
	//今駒が何段目か
	int OrderNum = 0;

	bool Ordered = false;
	
	int Color = GetColor(0, 0, 0);

};

