#include "davengine.h"
#include "MoveModifier.h"

using namespace Davengine;

int main() {
    RegisterModifier(new MoveModifier(), "MoveModifier");

    InitDavengine();

    DAVLoadFont("font.ttf", "font");

    Object* someObj = CreateObject("object");
    Sprite* someSprite = CreateSpriteModifier("icon.png");
    Text* someText = CreateTextModifier("font", "hello fucking world\ni hate niggers");
    AddModifier(someSprite, someObj);
    someObj->props->position->x = 0;
    someObj->props->position->y = 0;
    someObj->props->scale->x = 0.5f;
    someObj->props->scale->y = 0.5f;
    AddModifier(CreateModifier("MoveModifier"), someObj);
    AddModifier(someText, someObj);

    Mainloop();
    return 0;
};