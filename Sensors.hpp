#pragma once
#include <stdint.h>


using namespace std;

typedef enum {
    offline = 0,
    online = 1,
    calibrate = 2
} Status;

class BNO_055{
private:
    int SensorsDescriptor=-1;
    uint8_t SlaveAddress = 0x29;
    uint8_t BNO_ID = 0xA0;

public:

    Status status = offline;

    bool Init();
    double* GetEuler(double* vector);
    double* GetQuaternion(double* vector);

};