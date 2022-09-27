#include "HeaderFiles/Ball.h"

Ball::Ball(float px, float py, float vx, float vy, float ax, float ay, float radius, int ID, bool debugMode, int mass) // on create
{
    me.px = px;
    me.py = py;
    me.vx = vx;
    me.vy = vy;
    me.ax = ax;
    me.ay = ay;
    me.radius = radius;
    me.id = ID;
    me.mass = mass;
    Angle = atan2(vy, vx);
    endx = (radius * cos(Angle)) + px;
    endy = (radius * sin(Angle)) + py;
    this->debugMode = debugMode;
}

void Ball::Draw()
{
    DrawCircle(me.px, me.py, me.radius, WHITE);
    if (debugMode)
    {
        DrawLine(me.px, me.py, endx, endy, RED);
    }
}

void Ball::Update()
{
    Angle = atan2(me.vy, me.vx);
    endx = (me.radius * cos(Angle)) + me.px;
    endy = (me.radius * sin(Angle)) + me.py;
}

Ball::~Ball()
{
}