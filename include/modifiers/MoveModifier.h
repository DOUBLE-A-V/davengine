//#include "Modifier.h"
#include "davengine.h"

class MoveModifier : public Modifier {
public:
    float speed = 100;
    MoveModifier* CreateClone() override {
        return new MoveModifier();
    }
    void Update() override{
        if (IsKeyDown(KEY_W)) parent->position->y += speed * Davengine::deltaTime;
        if (IsKeyDown(KEY_A)) parent->position->x -= speed * Davengine::deltaTime;
        if (IsKeyDown(KEY_S)) parent->position->y -= speed * Davengine::deltaTime;
        if (IsKeyDown(KEY_D)) parent->position->x += speed * Davengine::deltaTime;
    };
};