#include "niko.hpp"
#include <cstdio>

Niko::Niko(Vector2 pos,  Texture texture, Texture patTexture)
{
    this->pos = pos;
    this->deleted = false;
    this->playingAnim = false;

    this->texture = texture;
    this->patTexture = patTexture;

    this->rect = Rectangle {
        pos.x, pos.y,
        static_cast<float>(texture.width), static_cast<float>(texture.height)
    };
}

void Niko::update()
{
    if (playingAnim) {
        if ((secondCounter + 1) % 2 == 0) {
            frameCounter++;
        }
        secondCounter++;

        if (frameCounter == 4) {
            deleted = true;
        }
    }

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        if (!playingAnim) {
            if (CheckCollisionPointRec(GetMousePosition(), rect)) {
                printf("niko clicked\n");
                playingAnim = true;
            }
        }
    }
}

void Niko::draw()
{
    if (playingAnim) {
        const int frameImageSize = 112;

        Rectangle sourceRect = Rectangle {
            static_cast<float>(frameImageSize * frameCounter), 0,
            static_cast<float>(frameImageSize), static_cast<float>(frameImageSize)
        };

        DrawTexturePro(patTexture, sourceRect, rect, Vector2 { 0, 0 }, 0, WHITE);
    } else {
        DrawTexture(texture, pos.x, pos.y, WHITE);
    }
}

bool Niko::isDeleted()
{
    return deleted;
}

