#include "Sprite.h"
void Sprite::Draw() {
    //DrawTexturePro(texture, Rectangle{parent->position.x, parent->position.y, (float)texture.width, (float)texture.height}, Rectangle{parent->position.x, parent->position.y, texture.width * parent->scale.x, texture.height * parent->scale.y}, Vector2{0, 0}, parent->rotation, *color);
    float realWidth = texture.width * parent->scale->x;
    float realHeight = texture.height * parent->scale->y;
    DrawTexturePro(texture, Rectangle{0, 0, (float)texture.width, (float)texture.height}, Rectangle{0, 0, realWidth, realHeight}, Vector2{(parent->position->x - realWidth/2)*-1, parent->position->y + realHeight/2}, parent->rotation, *color);
}