#include "davengine.h"
#define _DEBUG
#ifndef _DEBUG
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#endif
#include "Objprops.h"
/*
int Davengine::modifierIdCounter = 0;
float Davengine::deltaTime = 0;
int Davengine::idcounter = 0;
Object* Davengine::mainTree = 0;
*/

int Davengine::RegisterModifier(Modifier* modifierSample, string name) {
    ModifierSample* modSample = new ModifierSample();
    modSample->modifier = modifierSample;
    modSample->name = name;
    modifiersSamples.push_back(modSample);
    return modifiersSamples.size();
}

Modifier* Davengine::CreateModifier(string name) {
    for (ModifierSample* modSample : modifiersSamples) {
        if (modSample->name == name) {
            modifierIdCounter++;
            
            Modifier* modifier = modSample->modifier->CreateClone();
            modifier->parent = 0;
            modifier->id = modifierIdCounter;
            return modifier;
        }
    }
    printf("It looks like you made a typo or forgot to register the modifier\n");
    cout << name << "\n";
    return 0;
}

Object* Davengine::CreateObject(string name) {
    idcounter++;
    Object* obj = new Object();
    obj->name = name;
    obj->id = idcounter;
    obj->props = new Objprops();
    allObjects.push_back(obj);
    return obj;
}

Object* Davengine::GetObject(int id) {
    for (Object* obj : allObjects) {
        if (obj->id == id) return obj;
    }
    return 0;
}

Object* Davengine::GetObject(Objprops* props) {
    for (Object* obj : allObjects) {
        if (obj->props == props) return obj;
    }
    return 0;
}

void Davengine::AddModifier(Modifier* mod, Object* obj) {
    if (mod->parent != 0) {
        GetObject(mod->parent)->RemoveModifier(mod);
    }
    mod->parent = obj->props;
    obj->modifiers.push_back(mod);
}

Sprite* Davengine::CreateSpriteModifier(string texturePath) {
    Sprite* sprite = static_cast<Sprite*>(CreateModifier("sprite"));
    sprite->texture = LoadTexture(texturePath.c_str());
    return sprite;
}

void Davengine::InitDavengine()
{
    RegisterModifier(new Sprite(), "sprite");

    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "davengine");

    SetTargetFPS(60);
}

void Davengine::Mainloop() {
    while (!WindowShouldClose())
    {
        deltaTime = GetFrameTime();

        BeginDrawing();
            ClearBackground(RAYWHITE);
            for (Object* obj : allObjects) {
                obj->UpdateModifiers();
            }
        EndDrawing();
    }

    CloseWindow();
}