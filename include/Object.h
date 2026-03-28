#pragma once

#include <iostream>
#include "string.h"
#include "vector"
#include "Modifier.h"

using namespace std;

class Object {
public:
    void UpdateModifiers();

    Objprops* props;
    string name;
    Object* parent;
    vector<Object*> children;
    vector<Modifier*> modifiers;
    Modifier* RemoveModifier(Modifier* mod);
    int id;
};