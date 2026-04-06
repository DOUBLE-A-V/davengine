#pragma once

#ifdef DAV_EXPORTS
#define DAV_API __declspec(dllexport)
#else
#define DAV_API __declspec(dllimport)
#endif

#include <iostream>
#include "string.h"
#include "Objprops.h"

class Modifier {
public:
    bool enabled = true;
    std::string name;
    Objprops* props;
    #if !defined(DAV_DLL) && !defined(DAVENGINE_GAME)
    virtual Modifier* CreateClone();
    virtual ~Modifier();
    virtual void OnAdd();
    virtual void Create();
    virtual void Update();
    virtual void Draw();
    virtual void DrawInterface();
    #else
    DAV_API virtual Modifier* CreateClone();
    DAV_API virtual ~Modifier();
    DAV_API virtual void OnAdd();
    DAV_API virtual void Create();
    DAV_API virtual void Update();
    DAV_API virtual void Draw();
    DAV_API virtual void DrawInterface();
    #endif
};