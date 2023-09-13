#pragma once
#include"DxLib.h"
#include <vector>
#include"struct.h"
#include "SlapKoma.h"
#include <list>
#include <memory>
#include "AngryEffect.h"
#include "SlapHead.h"
#include "PileEffect.h"

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

struct DressKoma
{
	std::vector<Koma> koma;
	std::vector<Dress> huku;
};


class Daruma
{
	//静的関数勢
public:
	static int GetKomaColor(Koma a);

	static int GetDress(Dress a);

	static void TextureSet();

	

private:

	static int KomaGraph[sizeof(Koma)];

	static int DressGraph[sizeof(Dress)];

	static int darumaFace;

public:

	/// <summary>
	/// modeをtrueにするとわがままモード
	/// </summary>
	/// <param name="pos"></param>
	/// <param name="mode"></param>
	void Init(Vector2 pos, bool mode = false);


	void Update();

	void Draw();

	void ClickAddKoma(Koma add);
	void ClickAddDress(Dress add);
	void ClickRemoveKoma();

	BoxTransform GetKomaTransform();
	BoxTransform GetHead();
	BoxTransform GetDragAndDropArea();

	bool GetBeKoma();
	bool MaxKoma();

	bool GetMode()
	{
		return DressMode;
	}

	void HeadReset();
	void Order();
	void DressOrder();

	void SetCatchOn(bool catchflag);



	std::vector<Koma> GetKomas();

	void SlapEffect();

	// 成功判定
	bool Comparison();
	
private:

	void KomaReset();

	void DressReset();

	void Reaction();

	bool DressComparison();
	bool KomaComparison();

	bool DressMode = false;

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
	//要求する駒の高さ
	int OrderRange = 0;
	//今駒が何段目か
	int OrderNum = 0;

	//要求する駒の高さ
	int OrderHukuRange = 0;
	//今駒が何段目か
	int OrderHukuNum = 0;

	bool Ordered = false;
	bool DressOrdered = false;
	
	bool isSlap = false;

	std::list<std::unique_ptr<SlapKoma>> slapKomas;

	std::list<std::unique_ptr<SlapHead>> slapHeads;

	std::unique_ptr<AngryEffect> angryEffect;

	double CursorHead = 0.0;
	double CursorKoma = 0.0;
	double CursorCatch = 0.0f;

	bool CacthFlag = false;

	std::unique_ptr<PileEffect> comitEffect = nullptr;

	int colorCount[sizeof(Koma)];
};

