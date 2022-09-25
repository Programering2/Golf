#include "Ball.h"
#include "raylib.h"
#include "ColorBall.h"
#include "CueBall.h"
#include "EightBall.h"

#include <algorithm>
#include <random>
#include <vector>
class Game
{
private:
    std::vector<Ball> balls;
    std::vector<std::pair<Ball *, Ball *>> collidingPairs;
    float defaultRadius;
    float WindowWidth;
    float WindowHeight;
    Ball *pselectedBall = nullptr;
    float friction;
    float CueMultiplier;
    bool debugmode;
    int mass;
    int NmbrOfBalls;
    float rackDistanceY;
    float rackDistanceX;

    float Boardx;
    float Boardy;
    float BoardWidth;
    float BoardHeight;

    struct addBall
    {
        float x;
        float y;
        float radius;
        bool cueball;
        bool eightBall;
        bool playerOne;
    };

    std::vector<addBall> Preballs;

public:
    Game(int WindowWidth, int WindowHeight);
    void AddBall(std::vector<addBall> _PreBalls);
    void Update();
    void Draw();
    ~Game();
};
