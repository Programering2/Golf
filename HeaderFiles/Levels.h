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
    std::vector<Vector3> circleLevel1;

    std::vector<Rectangle> rectanglesLevel2;
    std::vector<Vector3> circleLevel2;

    std::vector<Rectangle> rectanglesLevel3;
    std::vector<Vector3> circleLevel3;

    std::vector<Rectangle> rectanglesLevel4;
    std::vector<Vector3> circleLevel4;

    std::vector<Rectangle> rectanglesLevel5;
    std::vector<Vector3> circleLevel5;

    std::vector<Rectangle> rectanglesLevel6;
    std::vector<Vector3> circleLevel6;

    std::vector<Rectangle> rectanglesLevel7;
    std::vector<Vector3> circleLevel7;

    std::vector<Rectangle> rectanglesLevel8;
    std::vector<Vector3> circleLevel8;

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