#pragma once
#include "IAlertStrategy.h"

class AndromedaStrainStrategy : public IAlertStrategy
{
public:
    // Inherited via IAlertStrategy
    AlertLevel getAlertLevel(const Vitals& v) override;
    ~AndromedaStrainStrategy() override = default;
};

