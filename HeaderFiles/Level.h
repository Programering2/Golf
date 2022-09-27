#ifndef __LEVEL__
#define __LEVEL__
#include "GolfHole.h"
class Level
{
private:
    float grassx, grassy;
    float grasswidth, grassheight;
    float holex, holey, holeradius;
    float px, py;

public:
    Level(float px, float py, float grassx, float grassy, float grasswidth, float grassheight, GolfHole hole);
    ~Level();

    // getters
    float getgrassx() { return grassx; }
    float getgrassy() { return grassy; }
    float getgrasswidth() { return grasswidth; }
    float getgrassheight() { return grassheight; }
    float getHolex() { return holex; }
    float getHoley() { return holey; }
    float getHoleRadius() { return holeradius; }
    float getpx() { return px; }
    float getpy() { return py; }
};
#endif
