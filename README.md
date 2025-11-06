# Patient Monitoring System

A C++ implementation of a patient monitoring system that tracks patient vitals, manages alert levels, and notifies relevant stakeholders based on patient conditions.

## Features

- **Patient Management**: Add and manage patient records with personal information and medical history.
- **Vital Signs Monitoring**: Track and record patient vitals over time.
- **Alert System**: Dynamic alert level calculation based on patient conditions and vital signs.
- **Disease-Specific Strategies**: Different alert strategies for various medical conditions.
- **Notification System**: Automatic notifications to hospitals and GPs when alert levels reach critical status.

## System Architecture

### Core Components

1. **Patient Management System**
   - Manages patient records and vitals
   - Handles user interactions
   - Coordinates between different system components

2. **Alert Strategies**
   - `IAlertStrategy`: Interface for alert level determination
   - `CordycepsBrainInfectionStrategy`: Strategy for brain infection cases
   - `KepralsSyndrome`: Strategy for Kepral's Syndrome cases
   - `AndromedaStrainStrategy`: Strategy for Andromeda Strain cases

3. **Notification System**
   - `HospitalAlertSystemFacade`: Interface for hospital notifications
   - `GPNotificationSystemFacade`: Interface for GP notifications
   - Implements Observer pattern for decoupled notifications

4. **Data Persistence**
   - `PatientFileLoader`: Loads patient data from files
   - `PatientDatabaseLoader`: Abstract interface for patient data loading
   - `CompositePatientsLoader`: Supports loading from multiple sources

### Design Patterns Used

- **Strategy Pattern**: For different alert level calculations
- **Observer Pattern**: For notification system
- **Facade Pattern**: For simplifying complex notification systems
- **Adapter Pattern**: For data loading compatibility

## Building and Running

### Prerequisites

- C++17 compatible compiler
- CMake (if building from source)
- Visual Studio (on Windows)

### Building

1. Clone the repository
2. Open the solution file `PatientSystem.vcxproj` in Visual Studio

### Running

1. Run the compiled executable
2. Use the menu to interact with the system

## Usage

1. **View Patients**: Display all patients in the system
2. **Add Vitals**: Record new vital signs for a patient
3. **Exit**: Quit the application

## Alert Levels

The system uses four alert levels:

- **Green**: Normal condition
- **Yellow**: Caution
- **Orange**: Warning
- **Red**: Critical - Triggers notifications to hospitals and GPs

## Data Format

Patient data is stored in `patients.txt` with the following format:
```
FirstName,LastName,YYYY-MM-DD,Diagnosis
```

