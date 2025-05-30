#pragma once
#include "IAlertStrategy.h"

class AndromedaStrainStrategy : public IAlertStrategy
{
public:
    AndromedaStrainStrategy() {};
    // Inherited via IAlertStrategy
    AlertLevel getAlertLevel(const Vitals& v) override;
    ~AndromedaStrainStrategy() override = default;
};

