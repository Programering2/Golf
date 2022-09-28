#include "HeaderFiles/Levels.h"

void Levels::setupLevels()
{      

    //level 1
    Rectangle r0_1 =  {200, (windowHeight/2.f)-50, 700, 100};
    Rectangle r0_2 = {900,(windowHeight/2.f)-75, 150,150 };
    rectanglesLevel1.push_back(r0_1);
    rectanglesLevel1.push_back(r0_2);

    //Barriers
    
    Vector3 BT0_1 = {200, (windowHeight/2.f)-50, 700};
    Vector3 BT0_2 = {900, (windowHeight/2.f)-75, 150};
    BarrierTop1.push_back(BT0_1);
    BarrierTop1.push_back(BT0_2);

    Vector3 BD0_1 = {200, (windowHeight/2.f)+50, 700};
    Vector3 BD0_2 = {900, (windowHeight/2.f)+75, 150};
    BarrierDown1.push_back(BD0_1);
    BarrierDown1.push_back(BD0_2);

    Vector3 BR0_1 = {1050, (windowHeight/2.f)-50, 150};
    BarrierRight1.push_back(BR0_1);

    Vector3 BL0_1 = {900, (windowHeight/2.f)-50, 25};
    Vector3 BL0_2 = {200, (windowHeight/2.f)-50, 100};
    Vector3 BL0_3 = {900, (windowHeight/2.f)+25, 25};
    BarrierLeft1.push_back(BL0_1);
    BarrierLeft1.push_back(BL0_2);
    BarrierLeft1.push_back(BL0_3);


    Holes.push_back(GolfHole(975,windowHeight/2));
    Maps.push_back(Level(250, windowHeight/2, Holes[0], rectanglesLevel1, BarrierTop1, BarrierLeft1, BarrierDown1, BarrierRight1));

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
