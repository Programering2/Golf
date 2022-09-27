#include "HeaderFiles/Level.h"
Level::Level(float px, float py, float grassx, float grassy, float grasswidth, float grassheight, GolfHole hole)
{
    this->px = px;
    this->py = py;
    this->grassx = grassx;
    this->grassy = grassy;
    this->grasswidth = grasswidth;
    this->grassheight = grassheight;
    this->holex = hole.getx();
    this->holey = hole.gety();
    this->holeradius = hole.getRadius();
}

Level::~Level()
{
}
