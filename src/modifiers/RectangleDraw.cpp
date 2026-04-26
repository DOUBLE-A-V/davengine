#include "RectangleDraw.h"

RectangleDraw::RectangleDraw() {
  width = 128;
  height = 128;
  color = Color{255, 255, 255, 255};
}

void RectangleDraw::Draw() {
  float realWidth = width * props->scale.x;
  float realHeight = height * props->scale.y;
  Vector2 pos;

  pos.x = props->position.x;
  pos.y = -props->position.y;

  DrawRectanglePro(Rectangle{pos.x, pos.y, realWidth, realHeight},
                   Vector2{realWidth / 2, realHeight / 2}, props->rotation,
                   color);
}

RectangleDraw *RectangleDraw::CreateClone() { return new RectangleDraw(); }
