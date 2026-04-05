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
        if (IsKeyDown(KEY_W)) props->position.y += speed * Davengine::deltaTime;
        if (IsKeyDown(KEY_A)) props->position.x -= speed * Davengine::deltaTime;
        if (IsKeyDown(KEY_S)) props->position.y -= speed * Davengine::deltaTime;
        if (IsKeyDown(KEY_D)) props->position.x += speed * Davengine::deltaTime;
        if (IsKeyDown(KEY_R)) props->rotation += speed * Davengine::deltaTime;

        if (IsKeyDown(KEY_T))
        {
            props->scale.x += 0.2f * Davengine::deltaTime;
            props->scale.y += 0.2f * Davengine::deltaTime;
        }
        if (IsKeyDown(KEY_G))
        {
            props->scale.x -= 0.2f * Davengine::deltaTime;
            props->scale.y -= 0.2f * Davengine::deltaTime;
        }
    };
};