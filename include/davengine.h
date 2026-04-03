#pragma once

//#define DAV_DLL

#ifdef DAV_EXPORTS
#define DAV_API __declspec(dllexport)
#else
#define DAV_API __declspec(dllimport)
#endif

#include "raylib.h"
#include "Sprite.h"
#include "Text.hpp"
//#include "ContainerConstraintor.hpp"
#include "Object.h"

using namespace std;

class ModifierSample {
public:
    Modifier* modifier;
    string name;
};

namespace Davengine {
    #ifdef DAV_DLL
    extern DAV_API float deltaTime;
    extern DAV_API vector<ModifierSample*> modifiersSamples;
    extern DAV_API int idcounter;
    extern DAV_API vector<Object*> allObjects;
    extern DAV_API vector<FontDescriptor*> fonts;

    extern DAV_API float windowWidth;
    extern DAV_API float windowHeight;

    extern Color bgColor;

    DAV_API Object* CreateObject(string name);
    DAV_API Modifier* CreateModifier(string name);
    template<typename T>
    DAV_API T* CreateCastModifier(T, string name);
    DAV_API int RegisterModifier(Modifier* modifierSample, string name);

    DAV_API Object* GetObject(int id);
    DAV_API Object* GetObject(Objprops* props);
    DAV_API Object* FindObject(string name);
    
    DAV_API void AddModifier(Modifier* mod, Object* obj);

    DAV_API FontDescriptor* DAVLoadFont(string path, string name);
    DAV_API void DAVUnloadFont(string name);

    DAV_API Sprite* CreateSpriteModifier(string texturePath);
    DAV_API Text* CreateTextModifier(string fontName, string text);

    DAV_API void SetFont(Text* textModifier, string fontName);

    DAV_API void InitDavengine(int windowWidth, int windowHeight);

    DAV_API void Mainloop();
    #else
    extern float deltaTime;
    extern vector<ModifierSample*> modifiersSamples;
    extern int idcounter;
    extern vector<Object*> allObjects;
    extern vector<FontDescriptor*> fonts;

    extern float windowWidth;
    extern float windowHeight;

    extern Color bgColor;

    Object* CreateObject(string name);
    Modifier* CreateModifier(string name);

    template<class T>
    T* CreateCastModifier(string name)
    {
        return static_cast<T*>(CreateModifier(name));
    }
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
    #endif
}