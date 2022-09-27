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
    std::vector<Player> Spelare;
    bool PlayerOneTurn;

public:
    Game();
    void Draw();
    void Update();
    std::vector<Player> *getPlayers() { return &Spelare; }
    ~Game();
};
#endif