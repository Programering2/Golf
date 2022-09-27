#include "Game.h"

class Screen
{
private:
    Game *pgame;

public:
    void Draw();

    Screen(Game *game);
    ~Screen();
};
