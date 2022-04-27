#!/bin/bash
g++ -o ./realise/server *.cpp -l bcm2835 -lwiringPi -lwiringPiDev -lpthread
