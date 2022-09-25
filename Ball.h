#ifndef __Ball__
#define __Ball__
#include "raylib.h"
#include "raymath.h"
#include <vector>
class Ball
{
private:
    struct sBall
    {
        float px, py;
        float vx, vy;
        float ax, ay;
        float radius;
        int id;
        int mass;
    };

    float Angle;
    float endx;
    float endy;
    bool debugMode;
    sBall me;
    sBall start;
    Color color;

public:
    void Draw();
    void Update();
    Ball(float px, float py, float vx, float vy, float ax, float ay, float radius, int ID, bool debugMode, int mass);

    int getMass()
    {
        return me.mass;
    }

    int getID()
    {
        return me.id;
    }

    float getpx()
    {
        return me.px;
    }

    float getpy()
    {
        return me.px;
    }

    Vector2 getPos()
    {
        return {me.px, me.py};
    }

    Vector2 getAcceleration()
    {
        return {me.ax, me.ay};
    }
    float getax()
    {
        return me.ax;
    }

    float getay()
    {
        return me.ay;
    }
    Vector2 getVelocity()
    {
        return {me.vx, me.vy};
    }
    float getvx()
    {
        return me.vx;
    }

    float getvy()
    {
        return me.vy;
    }

    int getRadius()
    {
        return me.radius;
    }

    void setPos(Vector2 p)
    {
        me.px = p.x;
        me.py = p.y;
    }

    void setPx(float px)
    {
        me.px = px;
    }

    void setPy(float py)
    {
        me.py = py;
    }

    void setVelocity(Vector2 vel)
    {
        me.vx = vel.x;
        me.vy = vel.y;
    }

    void setVx(float vx)
    {
        me.vx = vx;
    }

    void setVy(float vy)
    {
        me.vy = vy;
    }

    void setAcceleration(Vector2 Acceleration)
    {
        me.ax = Acceleration.x;
        me.ay = Acceleration.y;
    }

    void setax(float ax)
    {
        me.ax = ax;
    }

    void setay(float ay)
    {
        me.ay = ay;
    }
    void setColor(Color color)
    {
        this->color = color;
    }
    ~Ball();
};
#endif
