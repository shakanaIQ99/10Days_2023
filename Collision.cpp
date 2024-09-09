#include "Collision.h"

bool Collision::BoxToBoxCollision(BoxTransform box1, BoxTransform box2, bool allFlag)
{
    if (allFlag) {
        if ((box1.pos.x - (float)box1.width / 2 >= box2.pos.x - (float)box2.width / 2 &&
            box1.pos.x + (float)box1.width / 2 <= box2.pos.x + (float)box2.width / 2) &&
            (box1.pos.y - (float)box1.height / 2 >= box2.pos.y - (float)box2.height / 2 &&
                box1.pos.y + (float)box1.height / 2 <= box2.pos.y + (float)box2.height / 2)) {
            return true;
        }
    }
    else {
        if ((box1.pos.x - (float)box1.width / 2 <= box2.pos.x + (float)box2.width / 2 &&
            box1.pos.x + (float)box1.width / 2 >= box2.pos.x - (float)box2.width / 2) &&
            (box1.pos.y - (float)box1.height / 2 <= box2.pos.y + (float)box2.height / 2 &&
                box1.pos.y + (float)box1.height / 2 >= box2.pos.y - (float)box2.height / 2)) {
            return true;
        }
    }

    return false;
}
