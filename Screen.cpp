#include "HeaderFiles/Screen.h"

Screen::Screen(Game *game)
{
    pgame = game;
    playerOneP = game->getPlayerOne();
    playerTwoP = game->getPlayerTwo();
    playerOneTurn = game->getPlayerOneTurn();
}

Screen::~Screen()
{
}

void Screen::Update()
{
    playerOneTurn = pgame->getPlayerOneTurn();
    // player one
    playerOneCurrentSwings = playerOneP->getswingsThisRound();
    playerOneSwings = playerOneP->getAllSwings();
    playerOneTotalSwings = playerOneP->gettotalSwings();

    // player two
    playerTwoCurrentSwings = playerTwoP->getswingsThisRound();
    playerTwoSwings = playerTwoP->getAllSwings();
    playerTwoTotalSwings = playerTwoP->gettotalSwings();
}

void Screen::Draw()
{
    // player One
    p1text = "playerOne (" + std::to_string(playerOneTotalSwings) + ") ";
    for (int i = 1; i < static_cast<int>(playerOneSwings.size()); i++)
    {
        p1text += std::to_string(playerOneSwings[i]) + ", ";
    }
    DrawText(toConstChar(p1text), 20, 20, 20, BLACK);

    // player Two
    p2text = "playerTwo (" + std::to_string(playerTwoTotalSwings) + ") ";
    for (int i = 0; i < static_cast<int>(playerTwoSwings.size()); i++)
    {
        p2text += std::to_string(playerTwoSwings[i]) + ", ";
    }
    DrawText(toConstChar(p2text), 820, 20, 20, BLACK);

    // draw current turn
    switch (playerOneTurn)
    {
    case true:
        ptext = "Player Ones Turn (" + std::to_string(playerOneCurrentSwings) + ")";
        break;
    case false:
        ptext = "Player Twos Turn (" + std::to_string(playerTwoCurrentSwings) + ")";
        break;
    }
    DrawText(toConstChar(ptext), 420, 80, 20, BLACK);
}
