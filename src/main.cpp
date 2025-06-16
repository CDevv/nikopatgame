#include <vector>
#include <string>
#include <raylib.h>
#include "niko.hpp"

std::vector<Niko> nikos;

void addNiko(Vector2 pos, Texture texture, Texture patTexture) {
    nikos.push_back(Niko(pos, texture, patTexture));
}

int main()
{
    const int width = 640;
    const int height = 480;
    InitWindow(width, height, "nikopatgame");

    const int timeout = 120;
    int frameCounter = 0;
    Texture niko = LoadTexture("resources/niko.png");
    Texture ney = LoadTexture("resources/ney.png");

    Texture nikopat = LoadTexture("resources/nikopat.png");
    Texture neypat = LoadTexture("resources/neypat.png");

    int maxX = GetScreenWidth() - niko.width;
    int maxY = GetScreenHeight() - niko.height;

    SetTargetFPS(60);

    Vector2 centerOfScreen = Vector2
    {
        static_cast<float>((GetScreenWidth()/2) - (niko.width/2)),
        static_cast<float>((GetScreenHeight()/2) - (niko.height/2))
    };
    addNiko(centerOfScreen, niko, nikopat);

    while(!WindowShouldClose()) {
        frameCounter++;

        if (frameCounter == timeout) {
            if (nikos.size() <= 10) {
                int chosenX = GetRandomValue(0, maxX);
                int chosenY = GetRandomValue(0, maxY);
                Vector2 pos = Vector2 { static_cast<float>(chosenX), static_cast<float>(chosenY) };

                int chosenNiko = GetRandomValue(0, 1);
                if (chosenNiko == 0) {
                    addNiko(pos, niko, nikopat);
                } else {
                    addNiko(pos, ney, neypat);
                }
            }

            frameCounter = 0;
        }

        for (int i = 0; i < nikos.size(); i++) {
            if (nikos.at(i).isDeleted()) {
                nikos.erase(nikos.begin() + i);
            } else {
                nikos.at(i).update();
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("nikopat", 20, 20, 16, BLACK);

        for (Niko niko : nikos) {
            niko.draw();
        }

        EndDrawing();
    }

    UnloadTexture(niko);
    UnloadTexture(nikopat);

    UnloadTexture(ney);
    UnloadTexture(neypat);

    CloseWindow();

    return 0;
}
