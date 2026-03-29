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
    }
    string text;
    float size;
    Color* color;
    FontDescriptor* font;

    void Draw() override {
        DrawTextPro(font->font, text.c_str(), Vector2 {0, 0}, Vector2 {parent->position->x*-1, parent->position->y}, parent->rotation, size, 2, *color);
    }
    Modifier* CreateClone() override {return new Text();}
};