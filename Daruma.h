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

	void Init(Vector2 pos);


	void Update();

	void Draw();

	void ClickAddKoma(Koma add);
	void ClickRemoveKoma();

	BoxTransform GetKomaTransform();
	BoxTransform GetHead();
	BoxTransform GetDragAndDropArea();

	bool GetBeKoma();
	bool MaxKoma();

	void HeadReset();
	void Order();

	int GetKomaColor(Koma a);
private:

	void KomaReset();


	bool Comparison();

	BoxTransform Orderboxs;
	BoxTransform Head;
	BoxTransform Komaboxs;

	BoxTransform DragAndDropArea;

	const int HeadWidth = 50;
	const int HeadHeight = 50;

	const int KomaWidth = 50;
	const int KomaHeight = 25;

	float defY = 0;

	std::vector<Koma> koma;
	std::vector<Koma> orderkoma;
	//óvãÅÇ∑ÇÈãÓÇÃçÇÇ≥
	int OrderRange = 0;
	//ç°ãÓÇ™âΩíiñ⁄Ç©
	int OrderNum = 0;

	bool Ordered = false;
	
	

};

