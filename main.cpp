#include "Container.h"
#include "MoveModifier.h"
#include "davengine.h"

using namespace Davengine;
int main() {
  InitDavengine(0, 0, "davengine game");
  RegisterModifier(new Container(), "Container");
  RegisterModifier(new MoveModifier(), "MoveModifier");

  Object *obj = CreateObject("object");
  AddModifier(CreateSpriteModifier("icon.png"), obj);
  AddModifier(CreateModifier("Container"), obj);
  AddModifier(CreateModifier("MoveModifier"), obj);

  Object *obj2 = CreateObject("object 2");
  AddModifier(CreateSpriteModifier("icon.png"), obj2);
  obj2->SetParent(obj);
  obj2->props->localPosition.x = 500;
  Mainloop();
  ShutdownEngine();
  return 0;
};
