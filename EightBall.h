#include "Ball.h"
class EightBall : public Ball
{
private:
    /* data */
public:
    EightBall(float px, float py, float vx, float vy, float ax, float ay, float radius, int ID, bool debugMode, int mass);
    ~EightBall();
};
