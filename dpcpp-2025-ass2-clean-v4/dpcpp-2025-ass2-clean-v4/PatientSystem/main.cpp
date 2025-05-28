// PatientSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
#include <string>

#include "PatientManagementSystem.h"
#include "PatientFileLoader.h"
#include <vector>
#include "Patient.h"

int main()
{
	/*auto pms = std::make_unique<PatientManagementSystem>();

	pms->init();
	pms->run();*/

	auto fileLoader = std::make_unique<PatientFileLoader>();
	fileLoader->initialiseConnection();
	std::vector<Patient*> patientIn;
	fileLoader->loadPatients(patientIn);
	
	for (Patient* p : patientIn) {
		std::cout << *p << std::endl;
	}
	fileLoader->closeConnection();	
	
	return 0;
}
