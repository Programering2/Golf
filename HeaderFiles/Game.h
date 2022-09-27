#ifndef __GAME__
#define __GAME__

#include "raylib.h"
#include "Ball.h"
#include "Levels.h"
#include "Level.h"
#include "GolfHole.h"
#include "Player.h"

#include <algorithm>
#include <random>
#include <vector>

class Game
{
private:
    bool PlayerOneTurn;
    
    std::vector<Player> Spelare;

public:
    void Draw();
    void Update();
    Game();
    ~Game();

    //getters
    bool getPlayerOneTurn(){ return PlayerOneTurn;};
    Player* getPlayerOne(){ return & Spelare[0];};
    Player* getPlayerTwo(){ return & Spelare[1];};

};
#endif