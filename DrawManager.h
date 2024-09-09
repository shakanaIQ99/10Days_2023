#pragma once
#include "DxLib.h"
#include <list>
#include <memory>
#include "BaseGame.h"
#include "Agame.h"
#include "Bgame.h"

using namespace std;

extern list<shared_ptr<BaseGame>> layerList;

void PushListAGame();


void ManageDraw();