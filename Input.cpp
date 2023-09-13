#include "DxLib.h"
#include "Input.h"
#include"Util.h"

bool Input::GetKey(int key)
{
	//if (key >= 256)	return false;
	return GetInstance()->keys[key];
}
bool Input::GetTriggerKey(int key)
{
	return GetInstance()->keys[key] && !GetInstance()->prev[key];
}
bool Input::GetReleaseKey(int key)
{
	return !GetInstance()->keys[key] && GetInstance()->prev[key];
}

bool Input::GetTriggerMouseLeft()
{
	return GetInstance()->MouseLeft && !GetInstance()->preMouseLeft;
}

bool Input::GetReleaseMouseLeft()
{
	return !GetInstance()->MouseLeft && GetInstance()->preMouseLeft;
}

bool Input::GetMouseLeft()
{
	return (GetMouseInput() & MOUSE_INPUT_LEFT);
}

bool Input::GetTriggerMouseLeftButton(BoxTransform box)
{
	if (GetMouseHitBox(box))
	{
		return GetTriggerMouseLeft();
	}
	return false;
}

bool Input::GetMouseHitBox(BoxTransform box)
{
	if (box.pos.x - (float)box.width <= GetInstance()->Mousepos.x &&
		box.pos.x + (float)box.width >= GetInstance()->Mousepos.x &&
		box.pos.y - (float)box.height <= GetInstance()->Mousepos.y &&
		box.pos.y + (float)box.height >= GetInstance()->Mousepos.y)
	{
		return true;
	}
	return false;
}

Vector2 Input::GetMousePos()
{

	return GetInstance()->Mousepos;
}

void Input::DrawCursor()
{
	Input* instance = GetInstance();

	int sizex, sizey;
	GetGraphSize(instance->GraphHandle[0], &sizex, &sizey);

	//Util::DrawRotaGraph3(instance->Mousepos, sizex / 4, sizey / 4, 2.0, 2.0, 0, instance->GraphHandle[instance->isHanmmer]);
	Util::DrawRotaGraph3C(instance->Mousepos, sizex / 4, sizey / 4, 2.0, 2.0, 0, instance->GraphHandle[instance->isHanmmer]);
}

void Input::SetChengeCursor(bool isHanmmer_1)
{
	GetInstance()->isHanmmer = isHanmmer_1;
}

Input::Input()
{
	

}

void Input::SetTexture()
{
	Input* instance = GetInstance();

	instance->GraphHandle[0] = LoadGraph(L"Resources/cursor/hand.png");
	instance->GraphHandle[1] = LoadGraph(L"Resources/cursor/hammer.png");


}

Input* Input::GetInstance()
{
	static Input instance;
	return &instance;
}

void Input::InputUpdate()
{
	Input* instance = GetInstance();

	GetMousePoint(&instance->mouseX, &instance->mouseY);
	instance->Mousepos = { (float)instance->mouseX,(float)instance->mouseY };

	// 最新のキーボード情報だったものは1フレーム前のキーボード情報として保存
	for (int i = 0; i < 256; i++)
	{
		instance->prev[i] = instance->keys[i];
	}

	instance->preMouseLeft = instance->MouseLeft;

	instance->MouseLeft = (GetMouseInput() & MOUSE_INPUT_LEFT);
	// 最新のキーボード情報を取得
	GetHitKeyStateAll(instance->keys);

	// マウスを表示状態にする
	SetMouseDispFlag(FALSE);
}
