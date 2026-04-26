#include "Container.h"
#include "MoveModifier.h"
#include "davengine.h"

using namespace Davengine;
int main() {
  InitDavengine(0, 0, "davengine game");
  RegisterModifier(new Container(), "Container");
  RegisterModifier(new MoveModifier(), "MoveModifier");

  Object *obj = CreateObject("object");
  // obj->props->position.x = 0;
  AddModifier(CreateSpriteModifier("res/icon.png"), obj);
  AddModifier(CreateModifier("Container"), obj);
  AddModifier(CreateModifier("MoveModifier"), obj);
  AddModifier(CreateModifier("RectangleDraw"), obj);
  CreateCastModifier<CircleDraw>("CircleDraw");

  ValuePhysics *valp = CreateValuePhysics(&(obj->props->position.x), 800);
  valp->changeSpeedRatio = 20;
  valp->outElasticRatio = 0.5f;
  // valp->overshooting = 0;
  Object *obj2 = CreateObject("object 2");
  AddModifier(CreateSpriteModifier("res/icon.png"), obj2);
  obj2->SetParent(obj);
  obj2->props->localPosition.x = 500;
  obj2->props->localScale.x = 0.5f;
  Mainloop();
  ShutdownEngine();
  return 0;
};
