#include "davengine.h"
#define _DEBUG
#ifndef _DEBUG
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#endif
#include "Objprops.h"
#include "Container.hpp"

float Davengine::deltaTime = 0;
int Davengine::idcounter = 0;
vector<ModifierSample*> Davengine::modifiersSamples = {};
vector<Object*> Davengine::allObjects = {};
vector<FontDescriptor*> Davengine::fonts = {};
Color Davengine::bgColor = Color{255, 255, 255, 255};

float Davengine::windowWidth = 0;
float Davengine::windowHeight = 0;


int Davengine::RegisterModifier(Modifier* modifierSample, string name) {
    ModifierSample* modSample = new ModifierSample();
    modSample->modifier = modifierSample;
    modSample->name = name;
    modifiersSamples.push_back(modSample);
    return modifiersSamples.size();
}

FontDescriptor* Davengine::DAVLoadFont(string path, string name) {
    FontDescriptor* fontDescriptor = new FontDescriptor();
    fontDescriptor->name = name;
    fontDescriptor->font = LoadFont(path.c_str());
    fonts.push_back(fontDescriptor);
    return fontDescriptor;
}
void Davengine::DAVUnloadFont(string name) {
    vector<FontDescriptor*> formatted = {};
    for (FontDescriptor* fontDescriptor : fonts) {
        if (fontDescriptor->name != name) {
            formatted.push_back(fontDescriptor);
        } else {
            delete fontDescriptor;
        }
    }
    fonts = formatted;
}

Modifier* Davengine::CreateModifier(string name) {
    for (ModifierSample* modSample : modifiersSamples) {
        if (modSample->name == name) 
        {
            Modifier* modifier = modSample->modifier->CreateClone();
            modifier->name = name;
            modifier->parent = 0;
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
    for (Object* obj : allObjects)
    {
        if (obj->props == props) return obj;
    }
    return 0;
}

Object* Davengine::FindObject(string name) {
    for (Object* obj : allObjects) {
        if (obj->name == name) return obj;
    }
    return 0;
}

void Davengine::AddModifier(Modifier* mod, Object* obj) {
    if (mod->parent != 0) {
        GetObject(mod->parent)->RemoveModifier(mod);
    }
    mod->parent = obj->props;
    obj->modifiers.push_back(mod);
    mod->OnAdd();
}

Sprite* Davengine::CreateSpriteModifier(string texturePath) {
    Sprite* sprite = static_cast<Sprite*>(CreateModifier("Sprite"));
    sprite->texture = LoadTexture(texturePath.c_str());
    return sprite;
}

void Davengine::SetFont(Text* textModifier, string fontName) {
    for (FontDescriptor* fontDescriptor : fonts) {
        if (fontDescriptor->name == fontName) {
            textModifier->font = fontDescriptor;
            textModifier->font->font = fontDescriptor->font;
            textModifier->font->name = fontDescriptor->name;
        }
    }
}

Text* Davengine::CreateTextModifier(string fontName, string text) {
    Text* textMod = static_cast<Text*>(CreateModifier("Text"));
    SetFont(textMod, fontName);
    textMod->text = text;
    return textMod;
}

void Davengine::InitDavengine(int newWindowWidth, int newWindowHeight)
{
    RegisterModifier(new Sprite(), "Sprite");
    RegisterModifier(new Text(), "Text");
    RegisterModifier(new Container(), "Container");
    RegisterModifier(new ContainerConstraintor(), "ContainerConstraintor");

    windowWidth = newWindowWidth;
    windowHeight = newWindowHeight;

    InitWindow(windowWidth, windowHeight, "davengine");

    SetTargetFPS(60);
}

void Davengine::Mainloop() {
    while (!WindowShouldClose())
    {
        deltaTime = GetFrameTime();

        BeginDrawing();
            ClearBackground(bgColor);
            for (Object* obj : allObjects) {
                if (obj->parent == nullptr) obj->UpdateModifiers();
            }
            for (Object* obj : allObjects) {
                if (obj->parent == nullptr) obj->DrawModifiers();
            }
        EndDrawing();
    }

    CloseWindow();
}