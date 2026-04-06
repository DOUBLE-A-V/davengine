//#define DAV_DLL

#ifdef DAV_EXPORTS
#define DAV_API __declspec(dllexport)
#else
#define DAV_API __declspec(dllimport)
#endif

#include "Modifier.h"

class ContainerConstraintor : public Modifier
{
public:
    bool noOrbitalRotation;
    bool noContainRotation;
    bool noContainScale;

    #if !defined(DAV_DLL) && !defined(DAVENGINE_GAME)
    virtual ~ContainerConstraintor();
    ContainerConstraintor* CreateClone();

    ContainerConstraintor()
    {
        noOrbitalRotation = false;
        noContainRotation = false;
        noContainScale = false;
        enabled = false;
    }
    #else
    DAV_API virtual ~ContainerConstraintor();
    DAV_API ContainerConstraintor* CreateClone();

    ContainerConstraintor()
    {
        noOrbitalRotation = false;
        noContainRotation = false;
        noContainScale = false;
        enabled = false;
    }
    #endif
};