#include "davengine.h"
#include "MoveModifier.h"
#include "Container.hpp"

using namespace Davengine;


template<typename T>
T* dildoPrig(T, string ebatSobak) {
    return new T();
}

int main() {
    RegisterModifier(new MoveModifier(), "MoveModifier");

    InitDavengine(1280, 720);

    vector<int> i = {};

    const float centerX = windowWidth/2;
    const float centerY = windowHeight/2;

    DAVLoadFont("font.ttf", "font");

    Object* someObj = CreateObject("object");
    Object* someObj2 = CreateObject("object2");

    Sprite* someSprite = CreateSpriteModifier("icon.png");
    Sprite* someSprite2 = CreateSpriteModifier("icon.png");

    ContainerConstraintor* containerConstraintor = CreateCastModifier<ContainerConstraintor>("ContainerConstraintor");
    AddModifier(containerConstraintor, someObj2);
    containerConstraintor->noContainRotation = true;

    AddModifier(someSprite2, someObj2);

    AddModifier(CreateModifier("Container"), someObj);
    AddModifier(someSprite, someObj);
    someObj->props->position.x = centerX;
    someObj->props->position.y = -centerY;
    someObj->props->scale.x = 1;
    someObj->props->scale.y = 1;
    someObj->props->rotation = 45;
    AddModifier(CreateModifier("MoveModifier"), someObj);

    someObj2->SetParent(someObj);
    someObj2->props->localPosition.x = 500;

    Mainloop();
    return 0;
};