#pragma once

#include <iostream>
#include <bcm2835.h>
#include <cstring>
#include "DataStruct.hpp"
#include "Socket.hpp"
#include "Functions.hpp"
#include "TelemetryClass.hpp"

using namespace std;

int main(void){

    TypeDirectCommandsStruct DirectCommandsStruct;

    TelemetryClass Sensors;

    InitSPI();

    //thread BNO_055_Thread(BNO_055_Init);
    //BNO_055_Thread.detach();

    Socket socket;
    socket.MakeServerSocket(1999);
    socket.Listen();

    char msg[2*DirectCommandsStructLen]={};

    while (1) {
        while (socket.GetSocketConnectionStatus()) {

            socket.RecvDataLen(msg, DirectCommandsStructLen);

            memcpy(&DirectCommandsStruct, msg, DirectCommandsStructLen);

            if (DirectCommandsStruct.stabilize) {}
            else { memcpy(&msg[DirectCommandsStructLen], msg, DirectCommandsStructLen); }

            bcm2835_spi_transfern(msg, 2 * DirectCommandsStructLen);

        }
        cout<<"gg\n";
        socket.Listen();
    }


    return 0;
}

