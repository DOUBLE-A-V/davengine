#include "Sprite.h"
void Sprite::Draw() {
    float realWidth = texture.width * parent->scale->x;
    float realHeight = texture.height * parent->scale->y;
    Vector2 pos;
    pos.x = parent->position->x - realWidth/2;
    pos.y = -(parent->position->y + realHeight/2);
    DrawTexturePro(texture, Rectangle{0, 0, (float)texture.width, (float)texture.height}, Rectangle{pos.x, pos.y, realWidth, realHeight}, Vector2{realWidth/2, realHeight/2}, parent->rotation, *color);
}