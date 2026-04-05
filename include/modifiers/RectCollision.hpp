#pragma once
#include "Collision.hpp"
#include "davengine.h"

const float radian = PI / 180;

class RectCollision : public Collision {
public:
    RectCollision* CreateClone() override {return new RectCollision();}
    Vector2 size;

    bool ContainsPoint(Vector2 point) override {
        float sum = 0;
        Vector2 pointDelta = Vector2 {point.x - props->position.x, point.y - props->position.y};

        float sinRot = sin((props->rotation + 90) * radian);
        float cosRot = cos((props->rotation + 90) * radian);

        point.x = props->position.x + pointDelta.x * sinRot + pointDelta.y * cosRot;
        point.y = props->position.y + pointDelta.y * sinRot - pointDelta.x * cosRot;

        sum += abs(point.x - (props->position.x + size.x));
        sum += abs(point.x - (props->position.x - size.x));
        sum += abs(point.y - (props->position.y + size.y));
        sum += abs(point.y - (props->position.y - size.y));
        cout << sum << "\n";
        return sum/2 <= size.x + size.y;
    }

    // i should improve this shit in future
    bool TouchesCollision(RectCollision* col) {
        if (ContainsPoint(Vector2 {col->props->position.x + col->size.x, col->props->position.y + col->size.y})) return true;
        if (ContainsPoint(Vector2 {col->props->position.x + col->size.x, col->props->position.y - col->size.y})) return true;
        if (ContainsPoint(Vector2 {col->props->position.x - col->size.x, col->props->position.y - col->size.y})) return true;
        if (ContainsPoint(Vector2 {col->props->position.x - col->size.x, col->props->position.y + col->size.y})) return true;

        if (col->ContainsPoint(Vector2 {props->position.x + size.x, props->position.y + size.y})) return true;
        if (col->ContainsPoint(Vector2 {props->position.x + size.x, props->position.y - size.y})) return true;
        if (col->ContainsPoint(Vector2 {props->position.x - size.x, props->position.y - size.y})) return true;
        if (col->ContainsPoint(Vector2 {props->position.x - size.x, props->position.y + size.y})) return true;

        return false;
    }
};