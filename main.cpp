#include "davengine.h"
using namespace Davengine;

int main()
{
    InitDavengine(1280, 720, "davengine game");

    Object* obj = CreateObject("object");

    AddModifier(CreateSpriteModifier("icon.png"), obj);
    
    Mainloop();
    return 0;
};