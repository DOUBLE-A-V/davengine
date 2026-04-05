#pragma once
#include "Modifier.h"
#include "math.h"

class Collision : public Modifier {
public:
    virtual bool ContainsPoint(Vector2 point);
};