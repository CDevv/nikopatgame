#ifndef _NIKOPAT_NIKO_H
#define _NIKOPAT_NIKO_H

#include <string>
#include <raylib.h>

class Niko {
private:
    Texture texture;
    Texture patTexture;
    bool deleted;
    bool playingAnim;
    Vector2 pos;
    Rectangle rect;
    int frameCounter = 0;
    int secondCounter = 0;
public:
    Niko(Vector2 pos, Texture texture, Texture patTexture);
    void update();
    void draw();
    bool isDeleted();
};

#endif
