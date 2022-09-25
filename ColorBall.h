#include "Ball.h"
#include "raylib.h"

class ColorBall : public Ball
{
private:
    bool playerOnes;

public:
    ColorBall(float px, float py, float vx, float vy, float ax, float ay, float radius, int ID, bool debugMode, int mass, bool PlayerOnes);
    ~ColorBall();
};
