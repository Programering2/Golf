#ifndef __GOLFHOLE__
#define __GOLFHOLE__

class GolfHole
{
private:
    float x, y, radius;
    bool hasBall;

public:
    GolfHole(float x, float y);
    ~GolfHole();

    float getx() { return x; }
    float gety() { return y; }
    float getRadius() { return radius; }
    bool getHasBall() { return hasBall; }

    void setHasBall(bool hasBall) { this->hasBall = hasBall; }
};
#endif