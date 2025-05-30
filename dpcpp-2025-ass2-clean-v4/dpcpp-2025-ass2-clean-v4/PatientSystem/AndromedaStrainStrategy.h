#pragma once
#include "IAlertStrategy.h"

class AndromedaStrainStrategy : public IAlertStrategy
{
    // Inherited via IAlertStrategy
    AlertLevel getAlertLevel(const Vitals& v) override;
};

