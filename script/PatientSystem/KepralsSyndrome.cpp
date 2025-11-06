#include "KepralsSyndrome.h"


KepralsSyndrome::KepralsSyndrome(int age) :
    _age(age)
{
}

AlertLevel KepralsSyndrome::getAlertLevel(const Vitals& v)
{
    if (_age < 12 && v.HR() > 120) {
        return AlertLevel::Red;
    }
    else if (_age >= 12 && v.HR() > 100) {
        return AlertLevel::Red;
    }   
    else {
        return AlertLevel::Green;
    }
}
