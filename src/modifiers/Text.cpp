#include "Text.h"

void Text::Draw() {
    if (!drawOnInterface) DrawTextPro(font->font, text.c_str(), Vector2 {props->position.x*1, -props->position.y}, Vector2 {0, 0}, props->rotation, size, 2, *color);
}

void Text::DrawInterface() {
    if (drawOnInterface) DrawTextPro(font->font, text.c_str(), Vector2 {props->position.x*1, -props->position.y}, Vector2 {0, 0}, props->rotation, size, 2, *color);
}

Modifier* Text::CreateClone() {return new Text();}