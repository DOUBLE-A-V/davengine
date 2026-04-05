#include "Object.h"

void Object::UpdateModifiers() {
    for (Modifier* mod : this->modifiers) {
        if (!mod->enabled) continue;
        mod->Update();
    }
    for (Object* obj : this->children) {
        obj->UpdateModifiers();
    }
}

void Object::DrawModifiers() {
    for (Modifier* mod : this->modifiers) {
        if (!mod->enabled) continue;
        mod->Draw();
    }
    for (Object* obj : this->children) {
        obj->DrawModifiers();
    }
}
void Object::DrawInterfaceModifiers() {
    for (Modifier* mod : this->modifiers) {
        if (!mod->enabled) continue;
        mod->DrawInterface();
    }
    for (Object* obj : this->children) {
        obj->DrawInterfaceModifiers();
    }
}

Modifier* Object::GetModifier(string name) {
    for (Modifier* mod : modifiers) if (mod->name == name) return mod;
    return nullptr;
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
    if (newParent != nullptr) newParent->children.push_back(this);
}

Modifier* Object::RemoveModifier(Modifier* mod) {
    vector<Modifier*> outList;
    for (Modifier* modifier : modifiers) {
        if (modifier != mod) outList.push_back(modifier);
    }
    modifiers = outList;
    mod->props = 0;
    return mod;
}