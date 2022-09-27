#include "raylib.h"
#include "HeaderFiles/Game.h"
#include "HeaderFiles/Screen.h"

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

    Game game;//init instance
    Screen screen(&game);
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

        game.Draw(); //game draw
        screen.Draw(); //draw hud sköter scores samt, animeringar!!

        EndDrawing();
    }
    CloseWindow();

    return 0;
}
