#ifdef DAV_EXPORTS
#define DAV_API __declspec(dllexport)
#elif !defined(DAV_LINUX)
#define DAV_API __declspec(dllimport)
#endif

#include "RectCollision.h"
#include <algorithm>

using namespace std;

class CircleCollision : public Collision {
private:
#if !defined(DAV_DLL) && !defined(DAVENGINE_GAME)
  float Distance(Vector2 vec1, Vector2 vec2);
#else
  DAV_API float Distance(Vector2 vec1, Vector2 vec2);
#endif
public:
  float scale = 1;
  float radius = 100;

#if !defined(DAV_DLL) && !defined(DAVENGINE_GAME)
  virtual ~CircleCollision();
  CircleCollision *CreateClone() override;
  bool ContainsPoint(Vector2 point) override;

  bool TouchesCollision(CircleCollision *col);

  bool TouchesCollision(RectCollision *col);
#else
  DAV_API virtual ~CircleCollision();
  DAV_API CircleCollision *CreateClone() override;
  DAV_API bool ContainsPoint(Vector2 point) override;

  DAV_API bool TouchesCollision(CircleCollision *col);

  DAV_API bool TouchesCollision(RectCollision *col);
#endif
};
