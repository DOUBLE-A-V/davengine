#pragma once

#include <iostream>
#include "string.h"
#include "vector"
#include "Modifier.h"

using namespace std;

class Object {
public:
    const float radian = PI / 180;
    void UpdateModifiers();
    
    void RemoveChild(Object* child);
    void SetParent(Object* newParent);
    void AddChild(Object* newChild);

    Objprops* props;
    string name;
    Object* parent;
    vector<Object*> children;
    vector<Modifier*> modifiers;
    Modifier* RemoveModifier(Modifier* mod);
    int id;
};