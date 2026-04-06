//#define DAV_DLL

#ifdef DAV_EXPORTS
#define DAV_API __declspec(dllexport)
#else
#define DAV_API __declspec(dllimport)
#endif

#include <raylib.h>
#include "Modifier.h"
//#include "davengine.h"

class Sprite : public Modifier {
public:
    Color color;
    Texture2D texture;

    #if !defined(DAV_DLL) && !defined(DAVENGINE_GAME)
    Sprite()
    {
        color = Color {255, 255, 255, 255};
    }
    void Draw() override;
    Sprite* CreateClone() override;
    #else
    Sprite()
    {
        color = Color {255, 255, 255, 255};
    }
    DAV_API void Draw() override;
    DAV_API Sprite* CreateClone() override;
    #endif
};