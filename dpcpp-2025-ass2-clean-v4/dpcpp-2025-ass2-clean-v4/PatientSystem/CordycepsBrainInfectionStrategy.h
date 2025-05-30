#pragma once
#include "IAlertStrategy.h"


class CordycepsBrainInfectionStrategy : public IAlertStrategy
{
public:
    CordycepsBrainInfectionStrategy();
    
    AlertLevel getAlertLevel(const Vitals& v) override;    
};

