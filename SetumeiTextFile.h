#pragma once
#pragma once
#include "BaseGame.h"
class SetumeiTextFile : public BaseGame
{
public:
	SetumeiTextFile(int layernum, const Vector2& pos);
	~SetumeiTextFile();
	void Update() override;
	void Draw() override;

private:

	Vector2 textpos;


};

