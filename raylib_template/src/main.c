#include <raylib.h>

int main()
{
    InitWindow(500, 500, "My Raylib Application");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

            ClearBackground(WHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}