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
    }
    void UpdateModifiers();
    void DrawModifiers();
    
    void RemoveChild(Object* child);
    void SetParent(Object* newParent);
    void AddChild(Object* newChild);

    template<typename T>
    T* GetCastModifier(T, string name);

    Modifier* GetModifier(string name);

    Objprops* props;
    string name;
    Object* parent;
    vector<Object*> children;
    vector<Modifier*> modifiers;
    Modifier* RemoveModifier(Modifier* mod);
    int id;
};