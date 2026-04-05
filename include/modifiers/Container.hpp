#include "ContainerConstraintor.hpp"
#include "davengine.h"
#include "math.h"

using namespace Davengine;

class Container : public Modifier
{
public:
    const float radian = PI / 180;
    Object* parentObject;

    bool drawInterface = false;

    Container* CreateClone() override {return new Container();}

    void OnAdd() override {parentObject = GetObject(props);}
    
    void DrawInterface() override {
        if (!drawInterface) return;
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

            float sinRot = sin((props->rotation + 90) * radian);
            float cosRot = cos((props->rotation + 90) * radian);

            if (!hasConstraintor)
            {
                child->props->scale = Vector2{
                        child->props->localScale.x * props->scale.x,
                        child->props->localScale.y * props->scale.y
                    };
                
                child->props->rotation = props->rotation + child->props->localRotation;
                child->props->position.x = props->position.x + 
                (child->props->localPosition.x * sinRot + 
                child->props->localPosition.y * cosRot) * props->scale.x;

                child->props->position.y = props->position.y + 
                (-child->props->localPosition.y * sinRot +
                child->props->localPosition.x * cosRot) * props->scale.y;
            } else {
                if (!constraintor->noContainScale)
                {
                    child->props->scale = Vector2{
                        child->props->localScale.x * props->scale.x,
                        child->props->localScale.y * props->scale.y
                    };
                } else child->props->scale = Vector2 {1, 1};
                if (!constraintor->noContainRotation)
                {
                    child->props->rotation = props->rotation + child->props->localRotation;
                }
                if (constraintor->noOrbitalRotation)
                {
                    child->props->position =
                    Vector2 {props->position.x + child->props->localPosition.x, 
                        props->position.y + child->props->localPosition.y};
                } else
                {
                    child->props->position.x = props->position.x + 
                    (child->props->localPosition.x * sinRot + 
                    child->props->localPosition.y * cosRot) * props->scale.x;

                    child->props->position.y = props->position.y + 
                    (child->props->localPosition.y * sinRot +
                    child->props->localPosition.x * cosRot) * props->scale.y;
                }
            }
        }
    }
    void Draw() override {
        if (drawInterface) return;
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

            float sinRot = sin((props->rotation + 90) * radian);
            float cosRot = cos((props->rotation + 90) * radian);

            if (!hasConstraintor)
            {
                child->props->scale = Vector2{
                        child->props->localScale.x * props->scale.x,
                        child->props->localScale.y * props->scale.y
                    };
                
                child->props->rotation = props->rotation + child->props->localRotation;
                child->props->position.x = props->position.x + 
                (child->props->localPosition.x * sinRot + 
                child->props->localPosition.y * cosRot) * props->scale.x;

                child->props->position.y = props->position.y + 
                (-child->props->localPosition.y * sinRot +
                child->props->localPosition.x * cosRot) * props->scale.y;
            } else {
                if (!constraintor->noContainScale)
                {
                    child->props->scale = Vector2{
                        child->props->localScale.x * props->scale.x,
                        child->props->localScale.y * props->scale.y
                    };
                } else child->props->scale = Vector2 {1, 1};
                if (!constraintor->noContainRotation)
                {
                    child->props->rotation = props->rotation + child->props->localRotation;
                }
                if (constraintor->noOrbitalRotation)
                {
                    child->props->position =
                    Vector2 {props->position.x + child->props->localPosition.x, 
                        props->position.y + child->props->localPosition.y};
                } else
                {
                    child->props->position.x = props->position.x + 
                    (child->props->localPosition.x * sinRot + 
                    child->props->localPosition.y * cosRot) * props->scale.x;

                    child->props->position.y = props->position.y + 
                    (child->props->localPosition.y * sinRot +
                    child->props->localPosition.x * cosRot) * props->scale.y;
                }
            }
        }
    }
};