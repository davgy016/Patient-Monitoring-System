#include "Patient.h"

#include <iomanip>
#include <iostream>
#include <sstream>

#include "Vitals.h"
#include "CordycepsBrainInfectionStrategy.h"
#include "KepralsSyndrome.h"
#include "AndromedaStrainStrategy.h"


using namespace std;

const std::string Diagnosis::CORDYCEPS_BRAIN_INFECTION = "Cordyceps Brain Infection";
const std::string Diagnosis::KEPRALS_SYNDROME = "Kepral’s Syndrome";
const std::string Diagnosis::ANDROMEDA_STRAIN = "Andromeda Strain";


Patient::Patient(const std::string& firstName, const std::string& lastName, std::tm birthday) :
    Person(firstName, lastName, birthday),
    _alertLevel(AlertLevel::Green),
    _alertStrategy(nullptr)
{
}

int Patient::age() const
{
    // an inaccurate age estimate but fine for assignment purposes
    return 2022 - (1900 + _birthday.tm_year);
}

std::string Patient::uid() const
{
    std::stringstream ss;
    ss << (char)std::tolower(_lastName.at(0))
        << (char)std::tolower(_firstName.at(0))
        << std::setfill('0') << std::setw(2) << (_birthday.tm_mon + 1)
        << _birthday.tm_year;
    return ss.str();
}

std::string Patient::humanReadableID() const
{
    return "" + _lastName + ", " + _firstName + " (" + uid() + ")";
}

std::ostream& operator<<(std::ostream& os, const Patient& p)
{
    os << p.uid() << "|" << p._lastName << "," << p._firstName << "|" << std::put_time(&p._birthday, "%d-%m-%Y") << "|" << p.primaryDiagnosis();

    os << "|";
    for (int i = 0; i < p.vitals().size(); ++i) {
        auto v = p.vitals()[i];
        os << *v;
        if (i != p.vitals().size() - 1) {
            os << ";";
        }
    }
    return os;
}

void Patient::addDiagnosis(const std::string& diagnosis)
{
    _diagnosis.push_back(diagnosis);
}

const std::string& Patient::primaryDiagnosis() const
{
    return _diagnosis.front();
}

// set alert strategy
void Patient::setAlertStrategy(std::unique_ptr<IAlertStrategy> alertStrategy)
{
    _alertStrategy = std::move(alertStrategy);
}

void Patient::addListener(Listener* listener)
{
    _listeners.push_back(listener);
}

void Patient::removeListener(Listener* listener)
{
    _listeners.remove(listener);
}

void Patient::addVitals(const Vitals* v)
{
    _vitals.push_back(v);

    // Calculate alert levels
    if (primaryDiagnosis() == Diagnosis::CORDYCEPS_BRAIN_INFECTION) {
        setAlertStrategy(std::make_unique<CordycepsBrainInfectionStrategy>());
    }
    else if (primaryDiagnosis() == Diagnosis::KEPRALS_SYNDROME) {
        int ag = age();
        setAlertStrategy(std::make_unique<KepralsSyndrome>(ag));
    }
    else if (primaryDiagnosis() == Diagnosis::ANDROMEDA_STRAIN) {
        setAlertStrategy(std::make_unique<AndromedaStrainStrategy>());
    }
    else {
        _alertStrategy.reset();
        std::cerr << "Unknown diagnosis: " << humanReadableID() << std::endl;
    }

    if (_alertStrategy) {
        setAlertLevel(_alertStrategy->getAlertLevel(*v));
    }
}

const std::vector<const Vitals*> Patient::vitals() const
{
    return _vitals;
}

void Patient::setAlertLevel(AlertLevel level)
{
    _alertLevel = level;

    if (_alertLevel > AlertLevel::Green) {
        cout << "Patient: " << humanReadableID() << "has an alert level: ";
        switch (_alertLevel) {
        case AlertLevel::Yellow:
            cout << "Yellow";
            break;
        case AlertLevel::Orange:
            cout << "Orange";
            break;
        case AlertLevel::Red:
            cout << "Red";
            break;
        }
        cout << endl;
    }

    if (level == AlertLevel::Red) {
        for (auto l : _listeners) {
            l->alertLevelHasChanged(this);
        }
    }
}
