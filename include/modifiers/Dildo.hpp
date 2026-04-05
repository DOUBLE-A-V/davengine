#include "davengine.h"
#include "CircleCollision.hpp"

using namespace Davengine;

class Dildo : public Modifier {
public:
    Text* text;
    RectCollision* col;
    CircleCollision* col2;
    Dildo* CreateClone() override {return new Dildo();}
    void OnAdd() override {
        text = GetObject(props)->GetCastModifier<Text>("Text");
        col = GetObject(props)->GetCastModifier<RectCollision>("RectCollision");
        col2 = FindObject("circle")->GetCastModifier<CircleCollision>("CircleCollision");
    }
    void Update() override
    {
        //text->text = col->ContainsPoint(GetMousePosition()) ? "true" : "false";
        cout << col2->TouchesCollision(col)<< "\n";
    }
};