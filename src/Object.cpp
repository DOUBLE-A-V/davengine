#include "Object.h"

void Object::UpdateModifiers() {
    if (parent != nullptr) {
        props->scale->x = parent->props->scale->x * props->localScale->x;
        props->scale->y = parent->props->scale->y * props->localScale->y;

        props->rotation = parent->props->rotation + props->localRotation;

        Vector2 tmpLocalPos;
        tmpLocalPos.x = props->localPosition->x * parent->props->scale->x;
        tmpLocalPos.y = props->localPosition->y * parent->props->scale->y;

        props->position->x = parent->props->position->x + (tmpLocalPos.x * sin(props->rotation * radian) + cos(props->rotation * radian) * tmpLocalPos.y);
        props->position->y = parent->props->position->y + (tmpLocalPos.y * sin(props->rotation * radian) + cos(props->rotation * radian) * tmpLocalPos.x);
    }
    for (Modifier* mod : this->modifiers) {
        mod->Update();
        mod->Draw();
    }
}

void Object::RemoveChild(Object* child) {
    vector<Object*> newChildren;
    for (Object* obj : this->children) {
        if (obj != child) newChildren.push_back(obj);
    }
    this->children = newChildren;
    child->parent = nullptr;
}

void Object::AddChild(Object* newChild) {
    if (newChild->parent != nullptr) {
        newChild->parent->RemoveChild(newChild);
    }
    newChild->parent = this;
    children.push_back(newChild);
}

void Object::SetParent(Object* newParent) {
    if (this->parent != nullptr) {
        this->parent->RemoveChild(this);
    }
    this->parent = newParent;
    newParent->children.push_back(this);
}

Modifier* Object::RemoveModifier(Modifier* mod) {
    vector<Modifier*> outList;
    for (Modifier* modifier : modifiers) {
        if (modifier != mod) outList.push_back(modifier);
    }
    modifiers = outList;
    mod->parent = 0;
    return mod;
}