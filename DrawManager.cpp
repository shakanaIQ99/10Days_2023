#include "DrawManager.h"


bool comp(const shared_ptr<BaseGame> lo, const shared_ptr<BaseGame> ro) {
	return lo->GetLayer() < ro->GetLayer();
}

void ManageDraw() 
{
	layerList.sort(comp);

	int i = layerList.size();

	for (auto itr = layerList.begin(); itr != layerList.end();) {
		BaseGame* order = (*itr).get();


		SetDrawBright(255, 255, 255);

		order->Draw();

		if (order->GetEnd()) {
			itr = layerList.erase(itr);
		}
		else {
			itr++;
		}
	}
}