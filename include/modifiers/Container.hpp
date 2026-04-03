#include "ContainerConstraintor.hpp"
#include "davengine.h"

using namespace Davengine;

class Container : public Modifier
{
public:
    const float radian = PI / 180;
    Object* parentObject;

    Container* CreateClone() override {return new Container();}

    void OnAdd() override {parentObject = GetObject(parent);}
    
    void Draw() override
    {
        bool hasConstraintor = false;
        for (Object* child : parentObject->children)
        {
            Modifier* tmp = child->GetModifier("ContainerConstraintor");
            ContainerConstraintor* constraintor;
            hasConstraintor = false;
            if (tmp != nullptr)
            {
                hasConstraintor = true;
                constraintor = static_cast<ContainerConstraintor*>(tmp);
            }

            float sinRot = sin((parent->rotation + 90) * radian);
            float cosRot = cos((parent->rotation + 90) * radian);

            if (!hasConstraintor)
            {
                child->props->scale = Vector2{
                        child->props->localScale.x * parent->scale.x,
                        child->props->localScale.y * parent->scale.y
                    };
                
                child->props->rotation = parent->rotation + child->props->localRotation;
                child->props->position.x = parent->position.x + 
                (child->props->localPosition.x * sinRot + 
                child->props->localPosition.y * cosRot) * parent->scale.x;

                child->props->position.y = parent->position.y + 
                (child->props->localPosition.y * sinRot +
                child->props->localPosition.x * cosRot) * parent->scale.y;
            } else {
                if (!constraintor->noContainScale)
                {
                    child->props->scale = Vector2{
                        child->props->localScale.x * parent->scale.x,
                        child->props->localScale.y * parent->scale.y
                    };
                } else child->props->scale = Vector2 {1, 1};
                if (!constraintor->noContainRotation)
                {
                    child->props->rotation = parent->rotation + child->props->localRotation;
                }
                if (constraintor->noOrbitalRotation)
                {
                    child->props->position =
                    Vector2 {parent->position.x + child->props->localPosition.x, 
                        parent->position.y + child->props->localPosition.y};
                } else
                {
                    child->props->position.x = parent->position.x + 
                    (child->props->localPosition.x * sinRot + 
                    child->props->localPosition.y * cosRot) * parent->scale.x;

                    child->props->position.y = parent->position.y + 
                    (child->props->localPosition.y * sinRot +
                    child->props->localPosition.x * cosRot) * parent->scale.y;
                }
            }
        }
    }
};