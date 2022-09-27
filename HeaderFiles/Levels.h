#ifndef __LEVELS__
#define __LEVELS__
#include <vector>
#include "Level.h"
#include "GolfHole.h"
class Levels
{
private:
    std::vector<Level> Maps;
    std::vector<GolfHole> Holes;

public:
    Levels(/* args */);
    ~Levels();

    // getters ---
    Level *GetLevel(int level);
    GolfHole *GetHolePointer(int level);

    // functions
    void setupLevels();
};
#endif