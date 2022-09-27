#include "HeaderFiles/Levels.h"

void Levels::setupLevels()
{      
    Holes.push_back(GolfHole(750,400));
    Maps.push_back(Level(200, 800/2, 300, 300, 600, 200, Holes[0]));
    Holes.push_back(GolfHole(750,400));
    Maps.push_back(Level(200, 800/2, 300, 300, 600, 200, Holes[1]));
}

Level* Levels::GetLevel(int level)
{
    return &Maps[level];
}

 GolfHole* Levels::GetHolePointer(int level)
{
    return &Holes[level];
}

Levels::Levels(/* args */)
{
}

Levels::~Levels()
{
}
