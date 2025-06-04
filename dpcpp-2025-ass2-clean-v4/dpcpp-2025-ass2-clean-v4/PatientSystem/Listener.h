#pragma once
class Patient;

class Listener {
public:
    virtual void alertLevelHasChanged(Patient* patient) = 0;
};