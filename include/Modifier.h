#pragma once

#include <iostream>
#include "string.h"
#include "Objprops.h"

class Modifier {
public:
    bool enabled = true;
    virtual Modifier* CreateClone(){return 0;};
    virtual ~Modifier() {};
    virtual void OnAdd(){};
    virtual void Create(){};
    virtual void Update(){};
    virtual void Draw(){};
    virtual void DrawInterface(){};
    std::string name;
    Objprops* props;
};