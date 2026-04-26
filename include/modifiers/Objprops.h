#pragma once
#ifdef DAV_EXPORTS
#define DAV_API __declspec(dllexport)
#elif !defined(DAV_LINUX)
#define DAV_API __declspec(dllimport)
#endif
#include "raylib.h"

class Objprops {
public:
  Vector2 position;
  Vector2 localPosition;
  float rotation;
  float localRotation;
  Vector2 scale;
  Vector2 localScale;
#if !defined(DAV_DLL) && !defined(DAVENGINE_GAME)
  Objprops() {
    rotation = 0;
    localRotation = 0;
    position = Vector2{0, 0};
    localPosition = Vector2{0, 0};

    scale = Vector2{1, 1};
    localScale = Vector2{1, 1};
  }
#else
  Objprops() {
    rotation = 0;
    localRotation = 0;
    position = Vector2{0, 0};
    localPosition = Vector2{0, 0};

    scale = Vector2{1, 1};
    localScale = Vector2{1, 1};
  }
#endif
};
