#include "Object.h"

void Object::UpdateModifiers() {
    for (Modifier* mod : this->modifiers) {
        mod->Update();
        mod->Draw();
    }
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