#ifdef DAV_EXPORTS
#define DAV_API __declspec(dllexport)
#else
#define DAV_API __declspec(dllimport)
#endif

#include "Collision.h"
#include "davengine.h"

const float radian = PI / 180;

class RectCollision : public Collision {
public:
    Vector2 size;

    #if !defined(DAV_DLL) && !defined(DAVENGINE_GAME)
    virtual ~RectCollision();
    RectCollision* CreateClone() override;

    bool ContainsPoint(Vector2 point) override;

    // i should improve this shit in future
    bool TouchesCollision(RectCollision* col);
    #else
    DAV_API virtual ~RectCollision();
    DAV_API RectCollision* CreateClone() override;

    DAV_API bool ContainsPoint(Vector2 point) override;

    // i should improve this shit in future
    DAV_API bool TouchesCollision(RectCollision* col);
    #endif
};