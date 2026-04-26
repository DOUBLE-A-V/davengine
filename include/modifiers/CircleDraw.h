#ifdef DAV_EXPORTS
#define DAV_API __declspec(dllexport)
#elif !defined(DAV_LINUX)
#define DAV_API __declspec(dllimport)
#endif

#include "Modifier.h"
#include <raylib.h>
// #include "davengine.h"

class CircleDraw : public Modifier {
public:
  Color color;
  float radius;
  CircleDraw();

#if !defined(DAV_DLL) && !defined(DAVENGINE_GAME)
  void Draw() override;
  CircleDraw *CreateClone() override;
#else
  DAV_API void Draw() override;
  DAV_API CircleDraw *CreateClone() override;
#endif
};
