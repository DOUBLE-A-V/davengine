#include "raylib.h"
#include "Sprite.h"
#include "Object.h"

using namespace std;

class ModifierSample {
public:
    Modifier* modifier;
    string name;
};

namespace Davengine {
    static int modifierIdCounter = 0;
    static float deltaTime = 0;
    static vector<ModifierSample*> modifiersSamples;
    static int idcounter = 0;
    static vector<Object*> allObjects;

    Object* CreateObject(string name);
    Modifier* CreateModifier(string name);
    int RegisterModifier(Modifier* modifierSample, string name);

    Object* GetObject(int id);
    Object* GetObject(Objprops* props);
    void AddModifier(Modifier* mod, Object* obj);

    Sprite* CreateSpriteModifier(string texturePath);

    void InitDavengine();

    void Mainloop();
}