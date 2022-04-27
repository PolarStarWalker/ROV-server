#pragma once
#include <bcm2835.h>
#include <iostream>

#include <thread>
#include <chrono>
#include <cstring>
#include <cstdio>
#include <iomanip>


using namespace std;

inline int InitSPI(){
    bcm2835_init();

    bcm2835_spi_begin();
    bcm2835_spi_setBitOrder(BCM2835_SPI_BIT_ORDER_MSBFIRST);
    bcm2835_spi_setDataMode(BCM2835_SPI_MODE0);
    bcm2835_spi_setClockDivider(BCM2835_SPI_CLOCK_DIVIDER_256);
    bcm2835_spi_chipSelect(BCM2835_SPI_CS1);
    bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS1, LOW);

    return 0;
}
/*
inline void BNO_055_Init(){
    int16_t accel[3] = {};

    int8_t buf[6]={};



    while(wiringPiI2CReadReg8(fd,0x35)!=255){
        cout<<wiringPiI2CReadReg8(fd,0x35)<<"\n";
        this_thread::sleep_for(chrono::milliseconds(10));
    }


    while(1) {
        buf[4] = wiringPiI2CReadReg8(fd, 0x1A);
        buf[5] = wiringPiI2CReadReg8(fd, 0x1B);

        buf[2] = wiringPiI2CReadReg8(fd, 0x1C);
        buf[3] = wiringPiI2CReadReg8(fd, 0x1D);

        buf[0] = wiringPiI2CReadReg8(fd, 0x1E);
        buf[1] = wiringPiI2CReadReg8(fd, 0x1F);

        accel[0]= (int16_t) buf[0] | ((int16_t) buf[1]<<8);
        accel[1]= (int16_t) buf[2] | ((int16_t) buf[3]<<8);
        accel[2]= (int16_t) buf[4] | ((int16_t) buf[5]<<8);


        //memcpy(accel, buf, 6);
        //cout<<setprecision(3)<<accel[0]/100.0d<<" "<<accel[1]/100.0d<<" "<<accel[2]/100.0d<<"\n";
        printf("%.2f %.2f %.2f \n",accel[0]/16.0d, accel[1]/16.0d,accel[2]/16.0d);
        this_thread::sleep_for(chrono::milliseconds(10));
    }
}
*/