//#include "Modifier.h"
#include "davengine.h"

class MoveModifier : public Modifier {
public:
    float speed = 100;
    MoveModifier* CreateClone() override {
        return new MoveModifier();
    }
    void OnAdd() override {

    }
    void Update() override {
        if (IsKeyDown(KEY_W)) parent->position.y += speed * Davengine::deltaTime;
        if (IsKeyDown(KEY_A)) parent->position.x -= speed * Davengine::deltaTime;
        if (IsKeyDown(KEY_S)) parent->position.y -= speed * Davengine::deltaTime;
        if (IsKeyDown(KEY_D)) parent->position.x += speed * Davengine::deltaTime;
        if (IsKeyDown(KEY_R)) parent->rotation += speed * Davengine::deltaTime;

        if (IsKeyDown(KEY_T))
        {
            parent->scale.x += 0.2f * Davengine::deltaTime;
            parent->scale.y += 0.2f * Davengine::deltaTime;
        }
        if (IsKeyDown(KEY_G))
        {
            parent->scale.x -= 0.2f * Davengine::deltaTime;
            parent->scale.y -= 0.2f * Davengine::deltaTime;
        }
    };
};