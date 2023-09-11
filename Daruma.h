#pragma once
#include"DxLib.h"
#include <vector>
#include"struct.h"
#include "SlapKoma.h"
#include <list>
#include <memory>
#include "AngryEffect.h"

enum struct Koma : int
{
	RED,
	BLUE,
	GREEN,
	YELLOW
};

enum struct Dress :int
{
	ACCESSORY,
	TOP,
	BOTTOM,
	BOOTS
};


class Daruma
{
	//ê√ìIä÷êîê®
public:
	static int GetKomaColor(Koma a);

	static void TextureSet();

	

private:

	static int KomaGraph[sizeof(Koma)];

	static int darumaFace;

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

	void SetCatchOn(bool catchflag);

	std::vector<Koma> GetKomas();
	
private:

	void KomaReset();

	void Reaction();

	bool Comparison();

	BoxTransform Orderboxs;
	BoxTransform Head;
	BoxTransform Komaboxs;

	double Komasize = 1.6;

	BoxTransform DragAndDropArea;

	const int HeadWidth = 50;
	const int HeadHeight = 50;

	const int KomaWidth = 50;
	const int KomaHeight = 25;

	float defY = 0;

	std::vector<Koma> koma;
	std::vector<Koma> orderkoma;

	std::vector<Dress> huku;
	std::vector<Dress> orderhuku;
	//óvãÅÇ∑ÇÈãÓÇÃçÇÇ≥
	int OrderRange = 0;
	//ç°ãÓÇ™âΩíiñ⁄Ç©
	int OrderNum = 0;

	bool Ordered = false;
	
	bool isSlap = false;

	std::list<std::unique_ptr<SlapKoma>> slapKomas;


	std::unique_ptr<AngryEffect> angryEffect;

	double CursorHead = 0.0;
	double CursorKoma = 0.0;
	double CursorCatch = 0.0f;

	bool CacthFlag = false;
};

