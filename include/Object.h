#pragma once

#include <iostream>
#include "string.h"
#include "vector"
#include "Modifier.h"

using namespace std;

class Object {
public:
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

    template<typename T>
    T* GetCastModifier(string name)
    {
        for (Modifier* mod : modifiers) if (mod->name == name) return static_cast<T*>(mod);
        return nullptr;
    }

    Modifier* GetModifier(string name);

    Objprops* props;
    string name;
    Object* parent;
    vector<Object*> children;
    vector<Modifier*> modifiers;
    Modifier* RemoveModifier(Modifier* mod);
    int id;
};