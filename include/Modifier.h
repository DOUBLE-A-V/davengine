#pragma once

#include "iostream"
#include "string.h"
#include "Objprops.h"

class Modifier {
public:
    virtual Modifier* CreateClone(){return 0;};
    virtual void Create(){};
    virtual void Update(){};
    virtual void Draw(){};
    std::string name;
    Objprops* parent;
    int id;
};