#pragma once
#include "PatientAlertLevels.h"

#include "Vitals.h"

class IAlertStrategy
{
public:
    virtual AlertLevel getAlertLevel(const Vitals& v) = 0;
};

