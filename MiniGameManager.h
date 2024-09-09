#pragma once
#include "DxLib.h"
#include <list>
#include <memory>
#include "BaseGame.h"

//É~ÉjÉQÅ[ÉÄÇ«Ç‡



//

using namespace std;


class MiniGameManager
{
public:


	MiniGameManager();

	static MiniGameManager* GetInstance();

	/*static void CreateHomingBullet(ObjModel* Model, Vector3 Position, Vector3 Velocity, Vector3* Target, float Size, float BulletSpeed, const Tag& Tag);
	static void CreateNormalBullet(ObjModel* Model, Vector3 Position, Vector3 Velocity, float Size, float BulletSpeed, const Tag& Tag);*/


	static void ManageMiniGames();
	static void Clear();

	static const std::list<std::unique_ptr<BaseGame>>& GetGameList() { return GetInstance()->gameList; };

private:
	void Initialize();
	static list<unique_ptr<BaseGame>> gameList;


};