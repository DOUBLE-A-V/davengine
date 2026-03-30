#pragma once
#include "raylib.h"
#include "Sprite.h"
#include "Text.hpp"
#include "Object.h"

using namespace std;

class ModifierSample {
public:
    Modifier* modifier;
    string name;
};

namespace Davengine {
    extern int modifierIdCounter;
    extern float deltaTime;
    extern vector<ModifierSample*> modifiersSamples;
    extern int idcounter;
    extern vector<Object*> allObjects;
    extern vector<FontDescriptor*> fonts;

    Object* CreateObject(string name);
    Modifier* CreateModifier(string name);
    int RegisterModifier(Modifier* modifierSample, string name);

    Object* GetObject(int id);
    Object* GetObject(Objprops* props);
    Object* FindObject(string name);
    
    void AddModifier(Modifier* mod, Object* obj);

    FontDescriptor* DAVLoadFont(string path, string name);
    void DAVUnloadFont(string name);

    Sprite* CreateSpriteModifier(string texturePath);
    Text* CreateTextModifier(string fontName, string text);

    void SetFont(Text* textModifier, string fontName);

    void InitDavengine(int windowWidth, int windowHeight);

    void Mainloop();
}