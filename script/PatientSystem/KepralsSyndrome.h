#pragma once
#include "IAlertStrategy.h"



class KepralsSyndrome : public IAlertStrategy
{
public:
    KepralsSyndrome(int age);

    // Inherited via IAlertStrategy
    AlertLevel getAlertLevel(const Vitals& v) override;
    ~KepralsSyndrome() override = default;

protected:
    int _age;
};

