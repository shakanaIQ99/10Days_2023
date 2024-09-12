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

void MiniGameManager::CreateLightGame(int LayerNum, const Vector2& pos)
{
	GetInstance()->gameList.emplace_back(std::make_unique<LightGame>(LayerNum,pos));
}

void MiniGameManager::CreateHydeGame(int LayerNum, const Vector2& pos)
{
	GetInstance()->gameList.emplace_back(std::make_unique<HydeGame>(LayerNum, pos));
}

void MiniGameManager::CreateHelpSunGame(int LayerNum, const Vector2& pos)
{
	GetInstance()->gameList.emplace_back(std::make_unique<HelpSunGame>(LayerNum, pos));
}

void MiniGameManager::CreateKusogakiGame(int LayerNum, const Vector2& pos)
{
	GetInstance()->gameList.emplace_back(std::make_unique<KusogakiGame>(LayerNum, pos));
}

void MiniGameManager::CreateHackerGauge(int LayerNum, const Vector2& pos)
{
	GetInstance()->gameList.emplace_back(std::make_unique<HakcerGauge>(LayerNum, pos));
}

void MiniGameManager::CreateSetumei(int LayerNum, const Vector2& pos)
{
	GetInstance()->gameList.emplace_back(std::make_unique<SetumeiTextFile>(LayerNum, pos));
}

void MiniGameManager::ManageMiniGames()
{
	
	GetInstance()->gameList.sort(comp);//レイヤー順でソート

	GetInstance()->Maxlayer = gameList.back().get()->GetLayer();//最大レイヤー値を取得

	bool firstCheck = false;

	for (list<unique_ptr<BaseGame>>::reverse_iterator itr = GetInstance()->gameList.rbegin(); itr != GetInstance()->gameList.rend();) {
		BaseGame* obj = (*itr).get();

		if (!firstCheck)
		{
			firstCheck = true;
			obj->OnActive();//最前面だけオンにしているBool関数
		}
		else
		{
			obj->OffActive();//それ以外off
		}

		if (Input::GetTriggerMouseLeftButton(obj->GetTransform()))//クリックしたウィンドウを最前面にする関数
		{
			if (obj->GetLayer() <= GetInstance()->Maxlayer)
			{
				obj->SetLayer(GetInstance()->Maxlayer + 1);
				obj->OnActive();
			}

			break;
		}
		itr++;
	}

	for (list<unique_ptr<BaseGame>>::iterator itr = GetInstance()->gameList.begin(); itr != GetInstance()->gameList.end();) {
		BaseGame* obj = (*itr).get();


		if (obj->GetEnd()) {//終わったウィンドウをListから消す
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
	GetInstance()->Maxlayer = 0;
}

void MiniGameManager::Initialize()
{
	GetInstance()->gameList.clear();
	GetInstance()->Maxlayer = 0;
}


