#include "PatientFileLoader.h"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include "Patient.h"
#include "Vitals.h"

using namespace std;


std::vector<Patient*> PatientFileLoader::loadPatientFile(const std::string& file)
{
    vector<Patient*> patients{};
    ifstream inFile(file);
    if (!inFile.is_open()) {
        cerr << "Could not open " << file << std::endl;
        return patients;
    }
    string line;
    while (getline(inFile, line)) {
        istringstream iss(line);
        string uid, name, birthdayStr, diagnosis, vitalsStr;
        if (!getline(iss, uid, '|')) continue;
        if (!getline(iss, name, '|')) continue;
        if (!getline(iss, birthdayStr, '|')) continue;
        if (!getline(iss, diagnosis, '|')) continue;
        getline(iss, vitalsStr, '|');

        // Get last name,first name
        size_t commaPos = name.find(',');
        string lastName = name.substr(0, commaPos);
        string firstName = name.substr(commaPos + 1);

        // Get birthday
        tm tm_birthday = {};
        istringstream ss(birthdayStr);
        ss >> get_time(&tm_birthday, "%d-%m-%Y");

        Patient* p = new Patient(firstName, lastName, tm_birthday);
        p->addDiagnosis(diagnosis);

        // Get vitals 
        if (!vitalsStr.empty()) {
            // Can be more than one vitals
            istringstream vitalsStream(vitalsStr);
            string vital;
            while (getline(vitalsStream, vital, ';')) {
                // Get per vitals fields
                istringstream vitalFields(vital);
                string bt, bp, hr, rr;
                getline(vitalFields, bt, ',');
                getline(vitalFields, bp, ',');
                getline(vitalFields, hr, ',');
                getline(vitalFields, rr, ',');
                if (!bt.empty() && !bp.empty() && !hr.empty() && !rr.empty()) {
                    Vitals* v = new Vitals(stof(bt), stoi(bp), stoi(hr), stoi(rr));
                    p->addVitals(v);
                }
            }
        }
        patients.push_back(p);
    }
    inFile.close();
    return patients;
}


