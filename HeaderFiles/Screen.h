#include "Game.h"
#include "Player.h"
#include <vector>
#include <string>

class Screen
{
private:
    Game *pgame;
    Player *playerOneP;
    Player *playerTwoP;

    int playerOneCurrentSwings;
    int playerTwoCurrentSwings;
    int playerOneTotalSwings;
    int playerTwoTotalSwings;
    std::vector<int> playerOneSwings;
    std::vector<int> playerTwoSwings;
    std::string p1text;
    std::string p2text;
    std::string ptext;
    bool playerOneTurn;

public:
    void Draw();
    void Update();

    Screen(Game *game);
    ~Screen();

    const char *toConstChar(std::string text) { return text.c_str(); }
};
