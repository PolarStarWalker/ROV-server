#pragma once
#include <stdint.h>
#include <stddef.h>

struct TypeSensorsStruct {
    char angle_x[5] = {'x',0,0,0,0};

    char angle_y[5] = {'y',0,0,0,0};

    char angle_z[5] = {'z',0,0,0,0};

    char depth[5] = {'d',0,0,0,0};

    char temperature[5] = {'t',0,0,0,0};

    char pressure[5] = {'p',0,0,0,0};

    char  humidity[5] = {'h',0,0,0,0};

};

extern TypeSensorsStruct SensorsStruct;
constexpr size_t SensorsStructLen = sizeof(SensorsStruct);

struct TypeCommandsStruct
{
    char begin = 's';

    uint8_t message = 0;

    bool power = true;
    bool stabilize = false;
    bool reboot = false;

    int8_t TheHand = 0; //Okuyasu Nijimura

    bool angle = false;

    float move[6] = {};

    char end[4]={0,0,0,'s'};
};

extern TypeCommandsStruct CommandsStruct;
constexpr size_t CommandsStructLen = sizeof(CommandsStruct);

struct TypeDirectCommandsStruct
{
    char begin = 's';

    uint8_t message = 1;

    bool power = true;
    bool stabilize = false;
    bool reboot = false;

    int8_t TheHand = 0; //Okuyasu Nijimura
    bool angle = false;

    int16_t move[8] = {};

    char end[4]={0,0,0,'s'};
};

extern TypeDirectCommandsStruct DirectCommandsStruct;
constexpr size_t DirectCommandsStructLen = sizeof(DirectCommandsStruct);

