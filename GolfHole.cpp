#include "HeaderFiles/GolfHole.h"


GolfHole::GolfHole(float x,float y)
{
    this->x = x;
    this->y = y;
    radius = 15;
    hasBall = false;
}

GolfHole::~GolfHole()
{
}
