#include "Ball.h"

class CueBall:public Ball
{
private:
    /* data */
public:
    CueBall(float px, float py, float vx, float vy, float ax, float ay, float radius, int ID, bool debugMode, int mass);
    ~CueBall();
};
