#include "davengine.h"

class CircleDraw : public Modifier {
public:
    CircleDraw* CreateClone() override {return new CircleDraw();}
    float radius;
    float scale;
    Color color;
    CircleDraw() {
        color = {255, 255, 255, 255};
        scale = 1;
        radius = 100;
    }

    void Update() override {
        props->position = GetMouseWorldPosition();
    }
    void Draw() override {DrawCircle(props->position.x, -props->position.y, radius * scale, color);}
};