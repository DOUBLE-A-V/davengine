#include "davengine.h"
#include "MoveModifier.h"

using namespace Davengine;

int main() {
    RegisterModifier(new MoveModifier(), "MoveModifier");

    InitDavengine(1280, 720);

    DAVLoadFont("font.ttf", "font");

    Object* someObj = CreateObject("object");
    Object* someObj2 = CreateObject("object2");

    Sprite* someSprite = CreateSpriteModifier("icon.png");
    Sprite* someSprite2 = CreateSpriteModifier("icon.png");

    AddModifier(someSprite2, someObj2);
    someObj2->SetParent(someObj);
    someObj2->props->localPosition->x = 500;
    someObj2->props->localScale->x = 1;
    someObj2->props->localScale->y = 1;
    someObj->props->rotation = 45;

    AddModifier(someSprite, someObj);
    someObj->props->position->x = 500;
    someObj->props->position->y = 0;
    someObj->props->scale->x = 0.2f;
    someObj->props->scale->y = 1;
    AddModifier(CreateModifier("MoveModifier"), someObj);

    Mainloop();
    return 0;
};