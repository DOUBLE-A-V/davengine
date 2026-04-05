#include "davengine.h"
#define _DEBUG
#ifndef _DEBUG
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#endif
#include "Objprops.h"
#include "Container.hpp"
#include "CircleCollision.hpp"

float Davengine::deltaTime = 0;
int Davengine::idcounter = 0;
vector<ModifierSample*> Davengine::modifiersSamples = {};
vector<Object*> Davengine::allObjects = {};
vector<FontDescriptor*> Davengine::fonts = {};
vector<TextureAsset*> Davengine::textureAssets = {};
Color Davengine::bgColor = Color{255, 255, 255, 255};

float Davengine::windowWidth = 0;
float Davengine::windowHeight = 0;

Camera2D* Davengine::camera = new Camera2D{{0, 0}, {0, 0}, 0, 1};
Camera2D* Davengine::realCamera = new Camera2D{{0, 0}, {0, 0}, 0, 1};


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
            modifier->props = 0;
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
    if (mod->props != 0) {
        GetObject(mod->props)->RemoveModifier(mod);
    }
    mod->props = obj->props;
    obj->modifiers.push_back(mod);
    mod->OnAdd();
}

TextureAsset* Davengine::GetTextureAsset(string name) {
    for (TextureAsset* asset : textureAssets) {
        if (asset->name == name) {
            return asset;
        }
    }
    return nullptr;
}

Vector2 Davengine::GetMouseWorldPosition(){
    Vector2 mousepos = GetMousePosition();
    return Vector2 {mousepos.x - realCamera->offset.x, -mousepos.y + realCamera->offset.y};
}

Sprite* Davengine::CreateSpriteModifier(string texturePath, bool useAsset) {
    Sprite* sprite = static_cast<Sprite*>(CreateModifier("Sprite"));
    if (!useAsset) sprite->texture = LoadTexture(texturePath.c_str());
    else {
        sprite->texture = GetTextureAsset(texturePath)->texture;
    }
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

TextureAsset* Davengine::LoadTextureAsset(string path, string assetName)
{
    Texture2D texture = LoadTexture(path.c_str());
    TextureAsset* textureAsset = new TextureAsset {assetName, path, texture};
    textureAssets.push_back(textureAsset);
    return textureAsset;
}

void Davengine::UnloadTextureAsset(string name)
{
    vector<TextureAsset*> newTextureAssets;
    for (TextureAsset* asset : textureAssets)
    {
        if (asset->name != name) {
            newTextureAssets.push_back(asset);
        } else {
            UnloadTexture(asset->texture);
            delete asset;
        }
    }
    textureAssets = newTextureAssets;
}

void Davengine::InitDavengine(int newWindowWidth, int newWindowHeight, string title)
{
    RegisterModifier(new Sprite(), "Sprite");
    RegisterModifier(new Text(), "Text");
    RegisterModifier(new Container(), "Container");
    RegisterModifier(new ContainerConstraintor(), "ContainerConstraintor");
    RegisterModifier(new CircleCollision(), "CircleCollision");
    RegisterModifier(new RectCollision(), "RectCollision");
    //RegisterModifier(new CircleDraw(), "CircleDraw");
    

    windowWidth = newWindowWidth;
    windowHeight = newWindowHeight;

    InitWindow(windowWidth, windowHeight, title.c_str());

    camera->offset = Vector2{0, 0};

    SetTargetFPS(60);
}

void Davengine::Mainloop() {
    while (!WindowShouldClose())
    {
        deltaTime = GetFrameTime();
        BeginDrawing();
        ClearBackground(bgColor);
        realCamera->offset = Vector2 {-camera->offset.x + windowWidth/2, -camera->offset.y + windowHeight/2};
        realCamera->zoom = camera->zoom;
        realCamera->rotation = camera->rotation;
        BeginMode2D(*realCamera);
            for (Object* obj : allObjects) {
                if (obj->parent == nullptr) obj->UpdateModifiers();
            }
            for (Object* obj : allObjects) {
                if (obj->parent == nullptr) obj->DrawModifiers();
            }
        EndMode2D();
        for (Object* obj : allObjects) {
            if (obj->parent == nullptr) obj->DrawInterfaceModifiers();
        }
        EndDrawing();
    }

    CloseWindow();
}

void Davengine::ShutdownEngine() {
    for (FontDescriptor* font : fonts) {
        delete font;
    }
    for (Object* obj : allObjects) {
        delete obj;
    }
    for (ModifierSample* modSample : modifiersSamples) {
        delete modSample;
    }
    for (TextureAsset* asset : textureAssets) {
        delete asset;
    }
}