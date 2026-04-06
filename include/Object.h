#pragma once

//#define DAV_DLL

#ifdef DAV_EXPORTS
#define DAV_API __declspec(dllexport)
#else
#define DAV_API __declspec(dllimport)
#endif

#include <iostream>
#include "string.h"
#include "vector"
#include "Modifier.h"

using namespace std;

class Object {
public:
    Objprops* props;
    string name;
    Object* parent;
    vector<Object*> children;
    vector<Modifier*> modifiers;
    Modifier* RemoveModifier(Modifier* mod);
    int id;

    #if !defined(DAV_DLL) && !defined(DAVENGINE_GAME)
    Object() {
        children = {};
        modifiers = {};
        parent = nullptr;
    }
    ~Object() {
        for (Modifier* mod : modifiers) {
            delete mod;
        }
        delete props;
    }
    void UpdateModifiers();
    void DrawModifiers();
    void DrawInterfaceModifiers();
    
    void RemoveChild(Object* child);
    void SetParent(Object* newParent);
    void AddChild(Object* newChild);

    template<class T>
    T* GetCastModifier(string name);

    Modifier* GetModifier(string name);
    #else
    Object() {
        children = {};
        modifiers = {};
        parent = nullptr;
    }
    ~Object() {
        for (Modifier* mod : modifiers) {
            delete mod;
        }
        delete props;
    }
    DAV_API void UpdateModifiers();
    DAV_API void DrawModifiers();
    DAV_API void DrawInterfaceModifiers();
    
    DAV_API void RemoveChild(Object* child);
    DAV_API void SetParent(Object* newParent);
    DAV_API void AddChild(Object* newChild);

    template<class T>
    DAV_API T* GetCastModifier(string name);

    Modifier* GetModifier(string name);
    #endif
};