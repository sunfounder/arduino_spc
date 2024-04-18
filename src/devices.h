#ifndef __DEVICES_H__
#define __DEVICES_H__

#include "Arduino.h"

typedef struct {
    // battery
    bool battery_voltage;
    bool battery_current;
    bool battery_capacity;
    bool battery_percentage;
    bool is_charging;
    bool shutdown_battery_percentage;
    // input
    bool input_voltage;
    bool input_current;
    bool is_plugged_in;
    // output
    bool output_voltage;
    bool output_current;
    // others
    bool fan_power;
    bool rtc;
    bool power_source;
    bool shutdown_request;
    bool ref_voltage;
    bool power_source_voltage;
    bool always_on;
} peripherals_t;

typedef struct {
    char *name;
    char *id;
    uint8_t *address;
    peripherals_t peripherals;
} device_t;

extern uint8_t DEVICE_ADDRESSES[];
extern uint8_t DEVICE_COUNT;
extern device_t DEVICES[];

#endif // __DEVICES_H__