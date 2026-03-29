#include <raylib.h>
#include "Modifier.h"
//#include "davengine.h"

class Sprite : public Modifier {
public:
    Sprite() {
        color = new Color {255, 255, 255, 255};
    }
    Color* color;
    void Draw() override;
    Modifier* CreateClone() override {
        return new Sprite();
    }
    Texture2D texture;
};