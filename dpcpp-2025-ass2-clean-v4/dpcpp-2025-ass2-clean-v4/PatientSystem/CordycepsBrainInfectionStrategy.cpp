#include "CordycepsBrainInfectionStrategy.h"

CordycepsBrainInfectionStrategy::CordycepsBrainInfectionStrategy()
   
{
}

AlertLevel CordycepsBrainInfectionStrategy::getAlertLevel(const Vitals& v)
{
    if(v.RR()>40)
        return AlertLevel::Red;
    else if(v.RR()>30)
        return AlertLevel::Orange;
    else if(v.RR()>20)
        return AlertLevel::Yellow;   
    else {
        return AlertLevel::Green;
    }
        
}



