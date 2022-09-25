#include "ColorBall.h"
ColorBall::ColorBall(float px, float py, float vx, float vy, float ax, float ay, float radius, int ID, bool debugMode, int mass, bool PlayerOnes) : Ball(px, py, vx, vy, ax, ay, radius, ID, debugMode, mass)
{

    this->playerOnes = PlayerOnes;

    if (PlayerOnes)
    {
        setColor(Color{0,153,0,255});
    }
    else
    {
        setColor(Color{251,51,153,255});
    }
}

ColorBall::~ColorBall()
{
}
