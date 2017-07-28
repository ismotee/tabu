
#include "Hidpen.h"

bool Hidpen::openDevice(unsigned int i) {
    if (i >= deviceList.size()) return false;
    device = hid_open_path(deviceList[i].path.c_str());
    if (!device) return false;
    else {
        hid_set_nonblocking(device, 1);
        return true;
    }
}

void Hidpen::clearBuffer() {
    std::fill(buffer, buffer + BUF_SIZE, 0);
}

bool Hidpen::readPressure() {
    int err = 0;
    err = hid_read(device, buffer, sizeof (buffer));

    if (err > 0) {
        //get pressure
        unsigned short pressure_s = (unsigned short) buffer[PRESSURE_BYTE + 1] << 8 | (unsigned short) buffer[PRESSURE_BYTE];
        pressure = (float) pressure_s / PRESSURE_SCALE;
        return true;
    } else
        return false;
}

bool Hidpen::setup(int i) {
    pressure = 0;
            
    if (!getDevices())
        return false;
    if(!openDevice(i))
        return false;
    return true;
}

bool Hidpen::getDevices() {
    //temporary linked list of devices and an iterator to it:
    struct hid_device_info *devs, *cur_dev;

    //init, TODO: put this to a better place
    if (hid_init() == -1)
        return false;

    deviceList.clear();

    //get the devices to the linked list:
    devs = hid_enumerate(0x0, 0x0);

    //copy info from the temporary linked list to the deviceList vector:
    cur_dev = devs;
    while (cur_dev) {
        deviceInfo newDeviceInfo(cur_dev->vendor_id, cur_dev->product_id, cur_dev->path);
        deviceList.push_back(newDeviceInfo);
        cur_dev = cur_dev->next;
    }

    //free the temporary list:
    hid_free_enumeration(devs);

    return true;
}
