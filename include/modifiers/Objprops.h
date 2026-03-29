#pragma once
#include "raylib.h"

class Objprops {
public:
    Objprops() {
        position = new Vector2 {0, 0};
        localPosition = new Vector2 {0, 0};
        rotation = 0;
        localRotation = 0;
        scale = new Vector2 {1, 1};
        localScale = new Vector2 {1, 1};
    }
    Vector2* position;
    Vector2* localPosition;
    float rotation;
    float localRotation;
    Vector2* scale;
    Vector2* localScale;
};