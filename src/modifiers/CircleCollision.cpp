#include "CircleCollision.h"

CircleCollision::~CircleCollision() {}

float CircleCollision::Distance(Vector2 vec1, Vector2 vec2) {
    return sqrt(pow(vec2.x - vec1.x, 2) + pow(vec2.y - vec1.y, 2));
}

bool CircleCollision::ContainsPoint(Vector2 point) {
    return CheckCollisionPointCircle(point, props->position, radius*scale);
}

bool CircleCollision::TouchesCollision(CircleCollision* col) {
    return CheckCollisionCircles(props->position, radius * scale, col->props->position, col->radius * col->scale);
}

bool CircleCollision::TouchesCollision(RectCollision* col) {
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

CircleCollision* CircleCollision::CreateClone() {return new CircleCollision();}
