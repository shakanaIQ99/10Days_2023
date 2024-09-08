#pragma once
#include "DxLib.h"
#include <list>
#include <memory>
#include "BaseGame.h"

using namespace std;

extern list<shared_ptr<BaseGame>> layerList;


void ManageDraw();