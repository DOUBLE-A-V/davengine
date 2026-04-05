#include "Sprite.h"
void Sprite::Draw() {
    float realWidth = texture.width * props->scale.x;
    float realHeight = texture.height * props->scale.y;
    Vector2 pos;

    pos.x = props->position.x;
    pos.y = -props->position.y;

    DrawTexturePro(texture, Rectangle{0, 0, (float)texture.width, (float)texture.height}, Rectangle{pos.x, pos.y, realWidth, realHeight}, Vector2{realWidth/2, realHeight/2}, props->rotation, color);
}