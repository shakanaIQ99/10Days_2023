#pragma once
#include "Vector2.h"

class SceneChangeEffect
{
public:
	static SceneChangeEffect* Create();

	void Init();

	void Update();

	void Draw();

	const bool GetIsChange() const;

	const bool GetIsEffect() const;

	void SetIsSceneChange(bool sceneChange_);

	void EffectStart(bool isBlack_ = false);

private:
	int texNum = 0;

	int alphaNum = 0;

	bool isEffect = false;

	bool sceneChange = false;

	bool isIn = false;

	bool isOut = false;

	bool isBlack = false;
};

