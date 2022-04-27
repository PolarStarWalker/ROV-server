#pragma once
#include <mutex>
#include "DataStruct.hpp"
#include "Sensors.hpp"
using namespace std;



class TelemetryClass{
private:
    mutex SensorsMutex;
    TypeSensorsStruct SensorsStruct;

    BNO_055 NDOF;

    inline void SetSensorsData(TypeSensorsStruct* ExternalSensorsStruct){
        this->SensorsMutex.lock();
        this->SensorsStruct = *ExternalSensorsStruct;
        this->SensorsMutex.unlock();
    }

public:

    inline void GetSensorsData(TypeSensorsStruct* ExternalSensorsStruct){
        this->SensorsMutex.lock();
        *ExternalSensorsStruct = this->SensorsStruct;
        this->SensorsMutex.unlock();
    }

    void begin();
};
