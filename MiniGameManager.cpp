#include "MiniGameManager.h"
std::list<std::unique_ptr<BaseGame>> MiniGameManager::gameList;

bool comp(const unique_ptr<BaseGame> lo, const unique_ptr<BaseGame> ro) {
	return lo->GetLayer() < ro->GetLayer();
}

MiniGameManager::MiniGameManager()
{
}

MiniGameManager* MiniGameManager::GetInstance()
{
	static MiniGameManager instance;
	return &instance;
}

void MiniGameManager::ManageMiniGames()
{
	gameList.sort(comp);

	for (list<unique_ptr<BaseGame>>::iterator itr = GetInstance()->gameList.begin(); itr != GetInstance()->gameList.end();) {
		BaseGame* obj = (*itr).get();
		if (obj->GetEnd()) {
			itr = GetInstance()->gameList.erase(itr);
			continue;
		}

		obj->Update();
		obj->Draw();

		itr++;
	}
}

void MiniGameManager::Clear()
{
	GetInstance()->gameList.clear();
}

void MiniGameManager::Initialize()
{
	GetInstance()->gameList.clear();
}
