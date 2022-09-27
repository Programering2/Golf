#include "HeaderFiles/Levels.h"

void Levels::setupLevels()
{      

    //level 1
    Rectangle r0_1 =  {100, (windowHeight/2.f)-100, 700, 200};
    Vector3 c0_1 = {900, windowHeight/2.f, 200};
    rectanglesLevel1.push_back(r0_1);
    circleLevel1.push_back(c0_1);
    


    Holes.push_back(GolfHole(900,windowHeight/2));
    Maps.push_back(Level(130, windowHeight/2, Holes[0], rectanglesLevel1, circleLevel1));
    Holes.push_back(GolfHole(750,400));
    Maps.push_back(Level(200, 800/2, Holes[1], rectanglesLevel2, circleLevel2));
    Holes.push_back(GolfHole(750,400));
    Maps.push_back(Level(200, 800/2, Holes[2], rectanglesLevel3, circleLevel3));
    Holes.push_back(GolfHole(750,400));
    Maps.push_back(Level(200, 800/2, Holes[3], rectanglesLevel4, circleLevel4));
    Holes.push_back(GolfHole(750,400));
    Maps.push_back(Level(200, 800/2, Holes[4], rectanglesLevel5, circleLevel5));
    Holes.push_back(GolfHole(750,400));
    Maps.push_back(Level(200, 800/2, Holes[5], rectanglesLevel6, circleLevel6));
    Holes.push_back(GolfHole(750,400));
    Maps.push_back(Level(200, 800/2, Holes[6], rectanglesLevel7, circleLevel7));
    Holes.push_back(GolfHole(750,400));
    Maps.push_back(Level(200, 800/2, Holes[7], rectanglesLevel8, circleLevel8));
}

Level* Levels::GetLevel(int level)
{
    return &Maps[level];
}

 GolfHole* Levels::GetHolePointer(int level)
{
    return &Holes[level];
}

Levels::Levels(int windowWidth, int windowHeight)
{
    this->windowWidth = windowWidth;
    this->windowHeight = windowHeight;
}

Levels::~Levels()
{
}
