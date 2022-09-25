#include "raylib.h"
#include "Game.h"

enum class ApplicationStates
{
    Startup,
    Menu,
    Running,
    Quiting
};
ApplicationStates ApplicationState = ApplicationStates::Startup;

int main()
{   

    Game game(1280, 800);
    InitWindow(1280, 800, "RoyalPool");
    SetTargetFPS(60);
    ApplicationState = ApplicationStates::Running;
    while (!WindowShouldClose() && ApplicationState != ApplicationStates::Quiting)
    {
        switch (ApplicationState)
        {
        case ApplicationStates::Startup:

            break;
        case ApplicationStates::Menu:
            // Menu
            break;
        case ApplicationStates::Running:
            game.Update();
            break;
        case ApplicationStates::Quiting:
            // Quitting
            break;
        }
        BeginDrawing();
        ClearBackground(WHITE);

        game.Draw();

        EndDrawing();
    }
    CloseWindow();

    return 0;
}
