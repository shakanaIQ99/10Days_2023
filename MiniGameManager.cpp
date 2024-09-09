#include "MiniGameManager.h"
#include "Input.h"
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

void MiniGameManager::CreateLightGame(Vector2 pos)
{
	GetInstance()->gameList.emplace_back(std::make_unique<LightGame>());
}

void MiniGameManager::CreateHydeGame(Vector2 pos)
{
	GetInstance()->gameList.emplace_back(std::make_unique<HydeGame>());
}

void MiniGameManager::ManageMiniGames()
{
	gameList.sort(comp);

	int Maxlayer = gameList.back().get()->GetLayer();

	for (list<unique_ptr<BaseGame>>::reverse_iterator itr = GetInstance()->gameList.rbegin(); itr != GetInstance()->gameList.rend();) {
		BaseGame* obj = (*itr).get();

		if (Input::GetTriggerMouseLeftButton(obj->GetTransform()))
		{
			if (obj->GetLayer() < Maxlayer)
			{
				obj->SetLayer(Maxlayer + 1);
			}

			break;
		}
	
	}

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
