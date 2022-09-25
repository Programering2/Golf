#include "EightBall.h"

EightBall::EightBall(float px, float py, float vx, float vy, float ax, float ay, float radius, int ID, bool debugMode, int mass) : Ball(px, py, vx, vy, ax, ay, radius, ID, debugMode, mass)
{

    setColor(Color{0, 0, 0, 255});
}

EightBall::~EightBall()
{
}