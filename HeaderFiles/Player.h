#ifndef __PLAYER__
#define __PLAYER__
#include "Ball.h"
#include "Levels.h"
#include <vector>

class Player
{
private:
    Levels levels;
    Ball *GolfBall; // pointers
    Ball *pselectedBall = nullptr;
    float CueMultiplier; // floats
    float defaultRadius;
    float friction;
    float WindowWidth;
    float WindowHeight;
    int level; // ints
    int mass;
    int SwingsThisRound;
    int totalSwings;
    int maxLevel = 8;
    bool canSwing = true; // bools
    bool debugmode;
    bool golfHoleSetToPntr = false;
    bool playerOne;
    bool setupDone = false;
    std::vector<Ball> GolfBalls; // vectors
    std::vector<int> allSwings;

    struct Level // structs
    {
        float px, py;
        float grassx, grassy;
        float grassWidth, grassHeight;
        float holex, holey, holeRadius;
        GolfHole *holePointer;
    };
    Level currentLevel; 

public:
    void Update();
    void Draw();

    Player(bool playerOne);
    ~Player();

    // getters-----
    int gettotalSwings() { return totalSwings; }
    int getswingsThisRound() { return SwingsThisRound; }
    int getLevel() { return level; }
    std::vector<int> getAllSwings()
    {
        return allSwings;
    }

    // functions----
    void SetupLevel(int level);
    void DrawAim();
};
#endif