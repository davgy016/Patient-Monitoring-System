#pragma once

class PatientFileLoader;

#include "AbstractPatientDatabaseLoader.h"
class PatientFileLoaderAdapter : public AbstractPatientDatabaseLoader
{
public:
    PatientFileLoaderAdapter(PatientFileLoader* patientFileLoader);

    // Inherited via AbstractPatientDatabaseLoader
    void initialiseConnection() override;

    void loadPatients(std::vector<Patient*>& patientIn) override;

    void closeConnection() override;

protected:
    PatientFileLoader* _patientFileLoader;


};

