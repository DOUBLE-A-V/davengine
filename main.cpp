#include "davengine.h"
#include "Container.hpp"
#include "MoveModifier.h"
#include "Dildo.hpp"
#include "CircleDraw.hpp"

using namespace Davengine;

int main()
{
    InitDavengine(1280, 720, "davengine game");

    DAVLoadFont("font.ttf", "font");

    RegisterModifier(new MoveModifier(), "MoveModifier");
    RegisterModifier(new CircleDraw(), "CircleDraw");
    RegisterModifier(new Dildo(), "Dildo");

    LoadTextureAsset("icon.png", "icon");

    Object* circle = CreateObject("circle");
    CircleDraw* circleDraw = CreateCastModifier<CircleDraw>("CircleDraw");
    circleDraw->radius = 100;
    circleDraw->color = Color {0, 0, 0, 255};
    AddModifier(circleDraw, circle);
    AddModifier(CreateModifier("CircleCollision"), circle);

    Object* obj = CreateObject("object");
    AddModifier(CreateTextModifier("font", "hello world"), obj);
    AddModifier(CreateModifier("MoveModifier"), obj);
    AddModifier(CreateModifier("RectCollision"), obj);
    obj->GetCastModifier<RectCollision>("RectCollision")->size = Vector2 {275, 250};
    AddModifier(CreateModifier("Dildo"), obj);
    AddModifier(CreateSpriteModifier("icon", true), obj);
    
    Mainloop();

    ShutdownEngine();
    return 0;
};