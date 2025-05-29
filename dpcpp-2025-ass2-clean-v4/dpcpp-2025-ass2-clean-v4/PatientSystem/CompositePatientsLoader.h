#pragma once
#include "AbstractPatientDatabaseLoader.h"
#include <vector>

class CompositePatientsLoader : public AbstractPatientDatabaseLoader
{
public:
    // Add patients' data loaders
    void addPatientLoader(AbstractPatientDatabaseLoader* loader );

    // Load patients' data from multiple sources and store in patientIn
    void loadPatients(std::vector<Patient*>& patientIn) override;
    void initialiseConnection() override;
    void closeConnection() override;

protected:
    std::vector<AbstractPatientDatabaseLoader*> patientLoaders;
};

