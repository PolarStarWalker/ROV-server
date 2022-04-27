#include "Sensors.hpp"
#include <thread>
#include <chrono>
#include <wiringPiI2C.h>

bool BNO_055::Init(){
    this->SensorsDescriptor = wiringPiI2CSetup(this->SlaveAddress);

    if(this->SensorsDescriptor==-1){return false;}

    //set config mode
    wiringPiI2CWriteReg8(this->SensorsDescriptor,0x3D,0x00);
    this_thread::sleep_for(chrono::milliseconds(20));

    /* Reset */
    wiringPiI2CWriteReg8(this->SensorsDescriptor, 0x3F, 0x20);
    this_thread::sleep_for(chrono::milliseconds(20));

    while(wiringPiI2CReadReg8(this->SensorsDescriptor,0x00)!=0xA0){
        this_thread::sleep_for(chrono::milliseconds(10));
    }

    this_thread::sleep_for(chrono::milliseconds(50));

    //write8(BNO055_PWR_MODE_ADDR, POWER_MODE_NORMAL);
    wiringPiI2CWriteReg8(this->SensorsDescriptor, 0x3E, 0x00);
    this_thread::sleep_for(chrono::milliseconds(10));

    //write8(BNO055_PAGE_ID_ADDR, 0);
    //wiringPiI2CWriteReg8(this->SensorsDescriptor, 7, 0x00);

    //write8(BNO055_SYS_TRIGGER_ADDR, 0x0);
    wiringPiI2CWriteReg8(this->SensorsDescriptor, 0x3F, 0x00);
    this_thread::sleep_for(chrono::milliseconds(10));

    //set to ndof
    wiringPiI2CWriteReg8(this->SensorsDescriptor,0x3D,0b00001000);
    this_thread::sleep_for(chrono::milliseconds(20));

    return true;
}