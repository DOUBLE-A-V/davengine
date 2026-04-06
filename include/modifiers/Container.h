//#define DAV_DLL

#ifdef DAV_EXPORTS
#define DAV_API __declspec(dllexport)
#else
#define DAV_API __declspec(dllimport)
#endif

#include "ContainerConstraintor.h"
#include "davengine.h"
#include "math.h"

using namespace Davengine;

class Container : public Modifier
{
public:
    Object* parentObject;
    bool drawInterface;


    #if !defined(DAV_DLL) && !defined(DAVENGINE_GAME)
    virtual ~Container();
    Container() {
        drawInterface = false;
        parentObject = nullptr;
    }

    Container* CreateClone() override;

    void OnAdd() override;
    
    void DrawInterface() override;
    void Draw() override;
    #else
    DAV_API virtual ~Container();
    Container() {
        drawInterface = false;
        parentObject = nullptr;
    }

    DAV_API Container* CreateClone() override;

    DAV_API void OnAdd() override;
    
    DAV_API void DrawInterface() override;
    DAV_API void Draw() override;
    #endif
};