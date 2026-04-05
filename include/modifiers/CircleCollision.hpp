#include "RectCollision.hpp"
//#include "Collision.hpp"
#include <algorithm>

using namespace std;

class CircleCollision : public Collision {
private:
float Distance(Vector2 vec1, Vector2 vec2) {
    return sqrt(pow(vec2.x - vec1.x, 2) + pow(vec2.y - vec1.y, 2));
}
public:
    CircleCollision* CreateClone() override {return new CircleCollision();}

    float scale = 1;
    float radius = 100;
    bool ContainsPoint(Vector2 point) override {
        return CheckCollisionPointCircle(point, props->position, radius*scale);
    }

    bool TouchesCollision(CircleCollision* col) {
        return CheckCollisionCircles(props->position, radius * scale, col->props->position, col->radius * col->scale);
    }

    
    bool TouchesCollision(RectCollision* col) {
        float sinRot = sin((col->props->rotation + 90) * radian);
        float cosRot = cos((col->props->rotation + 90) * radian);
        Vector2 tmpSize = Vector2 {col->size.x * col->props->scale.x, col->size.y * col->props->scale.y};
        Vector2 delta = Vector2 {col->props->position.x - props->position.x, col->props->position.y - props->position.y};
        Vector2 tmpPos = Vector2 {
            col->props->position.x + delta.x * sinRot + delta.y * cosRot,
            col->props->position.x + delta.y * sinRot - delta.x * cosRot
        };
        Vector2 point = Vector2 {
            clamp(tmpPos.x, col->props->position.x - tmpSize.x, col->props->position.x + tmpSize.x),
            clamp(tmpPos.y, col->props->position.y - tmpSize.y, col->props->position.y + tmpSize.y)
        };
        return Distance(tmpPos, point) <= radius * scale;
    }
};