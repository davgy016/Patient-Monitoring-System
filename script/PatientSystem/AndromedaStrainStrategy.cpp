#include "AndromedaStrainStrategy.h"

AlertLevel AndromedaStrainStrategy::getAlertLevel(const Vitals& v)
{
    if (v.BP() > 140) {
        return AlertLevel::Red;
    }
    else if (v.BP() > 130) {
        return AlertLevel::Orange;
    }
    else if (v.BP() > 110) {
        return AlertLevel::Yellow;
    }
    else {
        return AlertLevel::Green;
    }
}
