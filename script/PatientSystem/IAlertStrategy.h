#pragma once
#include "PatientAlertLevels.h"

#include "Vitals.h"

class IAlertStrategy
{
public:
    virtual ~IAlertStrategy() = default;
    virtual AlertLevel getAlertLevel(const Vitals& v) = 0;
};

