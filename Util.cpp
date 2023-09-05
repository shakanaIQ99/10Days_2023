#include "Util.h"
#include"DxLib.h"
void Util::DrawBox(Vector2 pos, int width, int height, int color, bool fillflag)
{
	DxLib::DrawBox((int)pos.x - width, (int)pos.y - height, (int)pos.x + width, (int)pos.y + height, color, fillflag);
}

void Util::DrawBox(Vector2 pos, int width, int width2, int height, int height2, int color, bool fillflag)
{
	DxLib::DrawBox((int)pos.x - width, (int)pos.y - height, (int)pos.x + width2, (int)pos.y + height2, color, fillflag);
}
