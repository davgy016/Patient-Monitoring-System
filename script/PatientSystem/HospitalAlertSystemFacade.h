#pragma once

#include "Patient.h"
#include "Listener.h"


class HospitalAlertSystemFacade:public Listener
{
public:
	HospitalAlertSystemFacade();
	virtual ~HospitalAlertSystemFacade();

	void sendAlertForPatient(Patient* p);

	void alertLevelHasChanged(Patient* patient) override;

};

