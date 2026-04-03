#include "Modifier.h"

class ContainerConstraintor : public Modifier
{
public:
    ContainerConstraintor* CreateClone() {return new ContainerConstraintor();}
    bool noOrbitalRotation;
    bool noContainRotation;
    bool noContainScale;

    ContainerConstraintor()
    {
        noOrbitalRotation = false;
        noContainRotation = false;
        noContainScale = false;
    }
};