#pragma once
#include "Vector2.h"
#include <list>
#include <memory>
#include "Angry.h"

class AngryEffect
{
public:
	static AngryEffect* Create();

	void Init();

	void Update();

	void Draw();

	void Set(const Vector2& pos, const Vector2& range);
private:
	std::list<std::unique_ptr<Angry>> objects;

	int texNum = 0;
};

