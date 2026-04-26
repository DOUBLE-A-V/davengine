#ifdef DAV_EXPORTS
#define DAV_API __declspec(dllexport)
#elif !defined(DAV_LINUX)
#define DAV_API __declspec(dllimport)
#endif

#include "Modifier.h"
#include <raylib.h>
// #include "davengine.h"

class RectangleDraw : public Modifier {
public:
  Color color;
  float width;
  float height;
  RectangleDraw();

#if !defined(DAV_DLL) && !defined(DAVENGINE_GAME)
  void Draw() override;
  RectangleDraw *CreateClone() override;
#else
  DAV_API void Draw() override;
  DAV_API RectangleDraw *CreateClone() override;
#endif
};
