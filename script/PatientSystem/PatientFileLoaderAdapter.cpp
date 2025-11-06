#include "PatientFileLoaderAdapter.h"
#include "PatientFileLoader.h"

using namespace std;

PatientFileLoaderAdapter::PatientFileLoaderAdapter(PatientFileLoader* patientFileLoader) :
    _patientFileLoader(patientFileLoader)
{
}

void PatientFileLoaderAdapter::initialiseConnection()
{

}

void PatientFileLoaderAdapter::loadPatients(vector<Patient*>& patientIn)
{
    vector<Patient*> loadedPatients = _patientFileLoader->loadPatientFile("patients.txt");
    for (Patient* p : loadedPatients) {
        patientIn.push_back(p);
    }
}

void PatientFileLoaderAdapter::closeConnection()
{

}
