//#define DAV_DLL

#ifdef DAV_EXPORTS
#define DAV_API __declspec(dllexport)
#else
#define DAV_API __declspec(dllimport)
#endif

#include "raylib.h"
#include "string"
#include "Modifier.h"

using namespace std;

class FontDescriptor {
public:
    string name;
    Font font;
    ~FontDescriptor() {
        UnloadFont(font);
    }
};

class Text : public Modifier {
public:
    string text;
    float size;
    Color* color;
    FontDescriptor* font;
    bool drawOnInterface;

    #if !defined(DAV_DLL) && !defined(DAVENGINE_GAME)
    Text() {
        color = new Color {0, 0, 0, 255};
        size = 32;
        drawOnInterface = false;
    }

    void Draw() override;
    void DrawInterface() override;
    Modifier* CreateClone() override;
    #else
    Text() {
        color = new Color {0, 0, 0, 255};
        size = 32;
        drawOnInterface = false;
    }
    
    DAV_API void Draw() override;
    DAV_API void DrawInterface() override;
    DAV_API Modifier* CreateClone() override;
    #endif
};