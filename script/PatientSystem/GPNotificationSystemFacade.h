#pragma once

#include "Patient.h"
#include "Listener.h"


class GPNotificationSystemFacade:public Listener
{
public:
	GPNotificationSystemFacade();
	virtual ~GPNotificationSystemFacade();

	void sendGPNotificationForPatient(Patient* p);
	
	void alertLevelHasChanged(Patient* patient) override;
};

