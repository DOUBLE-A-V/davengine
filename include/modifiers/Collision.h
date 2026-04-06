#pragma once
#ifdef DAV_EXPORTS
#define DAV_API __declspec(dllexport)
#else
#define DAV_API __declspec(dllimport)
#endif
#include "Modifier.h"
#include "math.h"

class Collision : public Modifier {
public:
    #if !defined(DAV_DLL) && !defined(DAVENGINE_GAME)
    virtual ~Collision();
    virtual bool ContainsPoint(Vector2 point);
    #else
    DAV_API virtual ~Collision();
    DAV_API virtual bool ContainsPoint(Vector2 point);
    #endif
};