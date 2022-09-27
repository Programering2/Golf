#include "HeaderFiles/Game.h"

Game::Game()
{
    Spelare.push_back(Player(true));
    Spelare.push_back(Player(false));

    PlayerOneTurn = true;

    

}

void Game::Update() // once per frame ishh
{
    if(Spelare[0].getLevel() > Spelare[1].getLevel()) //om spelare ett är på nästa bana
    {   
        Spelare[1].Update();
        PlayerOneTurn = false;
    }
    else if(Spelare[0].getLevel() == Spelare[1].getLevel())
    {
        Spelare[0].Update();
        PlayerOneTurn = true;
    }
}

void Game::Draw()
{
    switch (PlayerOneTurn)
    {
    case true: Spelare[0].Draw();
        break;
    case false: Spelare[1].Draw();
        break;    
   }
}

Game::~Game()
{
}