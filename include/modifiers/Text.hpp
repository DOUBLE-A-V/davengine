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
    Text() {
        color = new Color {0, 0, 0, 255};
        size = 32;
        drawOnInterface = false;
    }
    string text;
    float size;
    Color* color;
    FontDescriptor* font;
    bool drawOnInterface;

    void Draw() override {
        if (!drawOnInterface) DrawTextPro(font->font, text.c_str(), Vector2 {props->position.x*1, -props->position.y}, Vector2 {0, 0}, props->rotation, size, 2, *color);
    }
    void DrawInterface() override {
        if (drawOnInterface) DrawTextPro(font->font, text.c_str(), Vector2 {props->position.x*1, -props->position.y}, Vector2 {0, 0}, props->rotation, size, 2, *color);
    }
    Modifier* CreateClone() override {return new Text();}
};