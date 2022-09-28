#ifndef __LEVEL__
#define __LEVEL__
#include "raylib.h"
#include "GolfHole.h"
#include "Ball.h"
#include <vector>
class Level
{
private:
    float grassx, grassy;
    float grasswidth, grassheight;
    float holex, holey, holeradius;
    float px, py;
    std::vector<Ball> GolfBall;
    std::vector<Rectangle> Rectangles;

    std::vector<Vector3> BarrierTop;
    std::vector<Vector3> BarrierLeft;
    std::vector<Vector3> BarrierDown;
    std::vector<Vector3> BarrierRight;

public:
    void Draw();

    Level(float px, float py, GolfHole hole, std::vector<Rectangle> Rectangles, std::vector<Vector3> BarrierTop, std::vector<Vector3> BarrierLeft, std::vector<Vector3> BarrierDown, std::vector<Vector3> BarrierRight);
    ~Level();

    // getters
    float getHolex() { return holex; }
    float getHoley() { return holey; }
    float getHoleRadius() { return holeradius; }
    float getpx() { return px; }
    float getpy() { return py; }

    Ball *getBall()
    {
        return &GolfBall[0];
    }

    void CheckCollision();
};
#endif
