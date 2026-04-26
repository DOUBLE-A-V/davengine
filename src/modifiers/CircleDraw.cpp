#include "CircleDraw.h"

CircleDraw::CircleDraw() {
  radius = 128;
  color = Color{255, 255, 255, 255};
}

void CircleDraw::Draw() {
  float realradius = radius * props->scale.x;
  Vector2 pos;

  pos.x = props->position.x;
  pos.y = -props->position.y;

  DrawCircleV(pos, realradius, color);
}

CircleDraw *CircleDraw::CreateClone() { return new CircleDraw(); }
