#include "CompositePatientsLoader.h"

void CompositePatientsLoader::addPatientLoader(AbstractPatientDatabaseLoader* loader)
{
    patientLoaders.push_back(loader);
}

void CompositePatientsLoader::loadPatients(std::vector<Patient*>& patientIn)
{
    for (auto& l : patientLoaders) {
        l->loadPatients(patientIn);
    }
}

void CompositePatientsLoader::initialiseConnection()
{    
}

void CompositePatientsLoader::closeConnection()
{    
}
