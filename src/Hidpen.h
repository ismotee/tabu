#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <hidapi/hidapi.h>
#include <algorithm>


struct deviceInfo {
    std::string path;
    unsigned short vendor_id;
    unsigned short product_id;

    deviceInfo(unsigned short vid, unsigned short pid, std::string path) {
        this->path = path;
        this->vendor_id = vid;
        this->product_id = pid;
    }
};

struct Hidpen {
    std::vector<deviceInfo> deviceList; //vector containing info of all the devices
    hid_device* device; //the open device
    static const unsigned int BUF_SIZE = 256;
    unsigned char buffer[BUF_SIZE]; //buffer for reading and writing
    float pressure;
    const unsigned int PRESSURE_BYTE = 6;
    const unsigned int PRESSURE_SCALE = 2048;

    bool openDevice(unsigned int i);
    bool getDevices();
    void clearBuffer();
    bool readPressure();
    void setup();
    //~Hidpen(){delete buffer;}
};


