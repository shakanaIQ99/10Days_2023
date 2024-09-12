#include "SetumeiTextFile.h"
#include "Input.h"
#include "Util.h"

SetumeiTextFile::SetumeiTextFile(int layernum, const Vector2& pos)
{
	fullwindow_.width = 320;
	fullwindow_.height = 540;

	topBar_.width = fullwindow_.width;
	topBar_.height = 48;
	topBar_.pos = pos;

	window_.width = fullwindow_.width;
	window_.height = fullwindow_.height - 48;
	window_.pos = { topBar_.pos.x, topBar_.pos.y + (topBar_.height / 2 + window_.height / 2) };
	fullwindow_.pos = { topBar_.pos.x,topBar_.pos.y + (window_.height / 2) };


	layer_ = layernum;

	textpos = { window_.pos.x-window_.width/2,window_.pos.y - fullwindow_.height/2+32 };
}

SetumeiTextFile::~SetumeiTextFile()
{
}

void SetumeiTextFile::Update()
{

	if (Input::GetTriggerMouseLeftButton(topBar_) && active_) {

		isMove_ = true;
	}
	else if (Input::GetReleaseMouseLeft())
	{
		isMove_ = false;
	}

	if (isMove_)
	{
		topBar_.pos = Input::GetMousePos();
	}
	window_.pos = { topBar_.pos.x, topBar_.pos.y + (topBar_.height / 2 + window_.height / 2) };

	
	fullwindow_.pos = { topBar_.pos.x,topBar_.pos.y + (window_.height / 2) };
	textpos = { window_.pos.x - window_.width / 2,window_.pos.y - fullwindow_.height / 2+32 };
}

void SetumeiTextFile::Draw()
{

	// ウィンドウ
	Util::DrawBox(window_.pos, window_.width / 2, window_.height / 2, GetColor(255, 255, 255), true);
	Util::DrawBox(topBar_.pos, topBar_.width / 2, topBar_.height / 2, GetColor(120, 120, 120), true);

	Util::DrawJpaneseString(textpos.x, textpos.y, GetColor(0, 0, 0), L"asasaああああ");


}
