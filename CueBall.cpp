#include "CueBall.h"
CueBall::CueBall(float px, float py, float vx, float vy, float ax, float ay, float radius, int ID, bool debugMode, int mass) : Ball(px, py, vx, vy, ax, ay, radius, ID, debugMode, mass)
{

    setColor(Color{255, 255, 255, 255});
}

CueBall::~CueBall()
{
}