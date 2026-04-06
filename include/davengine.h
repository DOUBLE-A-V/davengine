#pragma once

//#define DAV_DLL
//#define DAVENGINE_GAME

#ifdef DAV_EXPORTS
#define DAV_API __declspec(dllexport)
#else
#define DAV_API __declspec(dllimport)
#endif

#include "raylib.h"
#include "Sprite.h"
#include "Text.h"
#include "Object.h"

using namespace std;

class ModifierSample {
public:
    Modifier* modifier;
    string name;
    ~ModifierSample() {
        delete modifier;
    }
};

struct TextureAsset
{
    string name;
    string path;
    Texture2D texture;
};

namespace Davengine {
    #ifdef DAV_DLL
    extern DAV_API float deltaTime;
    extern DAV_API vector<ModifierSample*> modifiersSamples;
    extern DAV_API int idcounter;
    extern DAV_API vector<Object*> allObjects;
    extern DAV_API vector<FontDescriptor*> fonts;

    extern DAV_API vector<TextureAsset*> textureAssets;

    extern DAV_API float windowWidth;
    extern DAV_API float windowHeight;

    extern DAV_API Color bgColor;
    extern DAV_API Camera2D* camera;
    
    extern Camera2D* realCamera;

    Vector2 GetMouseWorldPosition();

    DAV_API Object* CreateObject(string name);
    DAV_API Modifier* CreateModifier(string name);
    template<class T>
    DAV_API T* CreateCastModifier(string name)
    {
        return static_cast<T*>(CreateModifier(name));
    }
    DAV_API int RegisterModifier(Modifier* modifierSample, string name);

    DAV_API Object* GetObject(int id);
    DAV_API Object* GetObject(Objprops* props);
    DAV_API Object* FindObject(string name);
    
    DAV_API void AddModifier(Modifier* mod, Object* obj);

    DAV_API TextureAsset* LoadTextureAsset(string path, string assetName);
    DAV_API void UnloadTextureAsset(string assetName);

    DAV_API TextureAsset* GetTextureAsset(string name);

    DAV_API FontDescriptor* DAVLoadFont(string path, string name);
    DAV_API void DAVUnloadFont(string name);

    DAV_API Sprite* CreateSpriteModifier(string texturePath, bool useAsset = false);
    DAV_API Text* CreateTextModifier(string fontName, string text);

    DAV_API void SetFont(Text* textModifier, string fontName);

    DAV_API void InitDavengine(int windowWidth, int windowHeight, string title);

    DAV_API void Mainloop();

    DAV_API void ShutdownEngine();
    #else
    extern float deltaTime;
    extern vector<ModifierSample*> modifiersSamples;
    extern int idcounter;
    extern vector<Object*> allObjects;
    extern vector<FontDescriptor*> fonts;

    extern vector<TextureAsset*> textureAssets;

    extern float windowWidth;
    extern float windowHeight;

    extern Color bgColor;

    extern Camera2D* camera;

    extern Camera2D* realCamera;

    Vector2 GetMouseWorldPosition();

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

    TextureAsset* LoadTextureAsset(string path, string assetName);
    void UnloadTextureAsset(string assetName);

    TextureAsset* GetTextureAsset(string name);

    Sprite* CreateSpriteModifier(string texturePath, bool useAsset = false);
    Text* CreateTextModifier(string fontName, string text);

    void SetFont(Text* textModifier, string fontName);

    void InitDavengine(int windowWidth, int windowHeight, string title);

    void Mainloop();

    void ShutdownEngine();
    #endif
}