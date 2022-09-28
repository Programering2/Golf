#ifndef __LEVELS__
#define __LEVELS__
#include "raylib.h"
#include "Level.h"
#include "GolfHole.h"
#include <vector>
class Levels
{
private:
    int windowHeight;
    int windowWidth;
    std::vector<Level> Maps;
    std::vector<GolfHole> Holes;

    std::vector<Rectangle> rectanglesLevel1;
    std::vector<Vector3> BarrierTop1;
    std::vector<Vector3> BarrierLeft1;
    std::vector<Vector3> BarrierDown1;
    std::vector<Vector3> BarrierRight1;

    std::vector<Rectangle> rectanglesLevel2;
    std::vector<Vector3> BarrierTop2;
    std::vector<Vector3> BarrierLeft2;
    std::vector<Vector3> BarrierDown2;
    std::vector<Vector3> BarrierRight2;

    std::vector<Rectangle> rectanglesLevel3;
    std::vector<Vector3> BarrierTop3;
    std::vector<Vector3> BarrierLeft3;
    std::vector<Vector3> BarrierDown3;
    std::vector<Vector3> BarrierRight3;

    std::vector<Rectangle> rectanglesLevel4;
    std::vector<Vector3> BarrierTop4;
    std::vector<Vector3> BarrierLeft4;
    std::vector<Vector3> BarrierDown4;
    std::vector<Vector3> BarrierRight4;

    std::vector<Rectangle> rectanglesLevel5;
    std::vector<Vector3> BarrierTop5;
    std::vector<Vector3> BarrierLeft5;
    std::vector<Vector3> BarrierDown5;
    std::vector<Vector3> BarrierRight5;

    std::vector<Rectangle> rectanglesLevel6;
    std::vector<Vector3> BarrierTop6;
    std::vector<Vector3> BarrierLeft6;
    std::vector<Vector3> BarrierDown6;
    std::vector<Vector3> BarrierRight6;

    std::vector<Rectangle> rectanglesLevel7;
    std::vector<Vector3> BarrierTop7;
    std::vector<Vector3> BarrierLeft7;
    std::vector<Vector3> BarrierDown7;
    std::vector<Vector3> BarrierRight7;

    std::vector<Rectangle> rectanglesLevel8;
    std::vector<Vector3> BarrierTop8;
    std::vector<Vector3> BarrierLeft8;
    std::vector<Vector3> BarrierDown8;
    std::vector<Vector3> BarrierRight8;

public:
    Levels(int windowWidth, int windowHeight);
    ~Levels();

    // getters ---
    Level *GetLevel(int level);
    GolfHole *GetHolePointer(int level);

    // functions
    void setupLevels();
};
#endif