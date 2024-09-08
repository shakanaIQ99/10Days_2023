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

bool Input::GetMouseLeftButton(BoxTransform box)
{
	if (GetMouseHitBox(box))
	{
		return GetMouseLeft();
	}
	return false;
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
	SetMouseDispFlag(TRUE);
}
