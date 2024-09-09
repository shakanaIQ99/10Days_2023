#include "MiniGameManager.h"
#include "Input.h"
std::list<std::unique_ptr<BaseGame>> MiniGameManager::gameList;

bool comp(const unique_ptr<BaseGame>& lo, const unique_ptr<BaseGame>& ro) {
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

void MiniGameManager::CreateLightGame(const Vector2& pos)
{
	GetInstance()->gameList.emplace_back(std::make_unique<LightGame>(pos));
}

void MiniGameManager::CreateHydeGame(const Vector2& pos)
{
	GetInstance()->gameList.emplace_back(std::make_unique<HydeGame>(pos));
}

void MiniGameManager::ManageMiniGames()
{
	
	GetInstance()->gameList.sort(comp);

	int Maxlayer = gameList.back().get()->GetLayer();

	for (list<unique_ptr<BaseGame>>::reverse_iterator itr = GetInstance()->gameList.rbegin(); itr != GetInstance()->gameList.rend();) {
		BaseGame* obj = (*itr).get();

		if (Input::GetTriggerMouseLeftButton(obj->GetTransform()))
		{
			if (obj->GetLayer() <= Maxlayer)
			{
				obj->SetLayer(Maxlayer + 1);
			}

			break;
		}
		itr++;
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


