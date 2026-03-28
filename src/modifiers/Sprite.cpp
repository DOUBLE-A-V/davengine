#include "Sprite.h"
void Sprite::Draw() {
    //DrawTexturePro(texture, Rectangle{parent->position.x, parent->position.y, (float)texture.width, (float)texture.height}, Rectangle{parent->position.x, parent->position.y, texture.width * parent->scale.x, texture.height * parent->scale.y}, Vector2{0, 0}, parent->rotation, *color);
    DrawTexturePro(texture, Rectangle{parent->position.x, parent->position.y, (float)texture.width, (float)texture.height}, Rectangle{parent->position.x, parent->position.y, texture.width * parent->scale.x, texture.height * parent->scale.y}, Vector2{0, 0}, parent->rotation, *color);
}