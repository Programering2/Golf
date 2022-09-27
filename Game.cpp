#include "HeaderFiles/Game.h"

Game::Game()
{
    Spelare.push_back(Player(true));
    PlayerOneTurn = true;
}

void Game::Update() // once per frame ishh
{
    Spelare[0].Update();
}

void Game::Draw()
{
    Spelare[0].Draw();
}

Game::~Game()
{
}