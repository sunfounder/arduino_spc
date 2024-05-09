#include "devices.h"

extern uint8_t DEVICE_ADDRESSES[] = {0x5A, 0x5B};
extern uint8_t DEVICE_COUNT = 2;

device_t pironman_u1 = {.name = "Pironman",
                        .id = "Pironman-U1",
                        .address = &DEVICE_ADDRESSES[0],
                        .peripherals = {.battery_voltage = true,
                                        .battery_current = true,
                                        .battery_capacity = true,
                                        .battery_percentage = true,
                                        .is_charging = true,
                                        .shutdown_percentage = true,
                                        .power_off_percentage = false,
                                        .input_voltage = true,
                                        .input_current = true,
                                        .is_input_plugged_in = true,
                                        .output_voltage = true,
                                        .output_current = true,
                                        .fan_power = true,
                                        .rtc = true,
                                        .power_source = true,
                                        .shutdown_request = true,
                                        .ref_voltage = true,
                                        .default_on = false}};

device_t pipower3 = {.name = "PiPower 3",
                     .id = "PiPower-3",
                     .address = &DEVICE_ADDRESSES[1],
                     .peripherals = {.battery_voltage = true,
                                     .battery_current = false,
                                     .battery_capacity = false,
                                     .battery_percentage = true,
                                     .is_charging = true,
                                     .shutdown_percentage = true,
                                     .power_off_percentage = true,
                                     .input_voltage = true,
                                     .input_current = false,
                                     .is_input_plugged_in = true,
                                     .output_voltage = true,
                                     .output_current = false,
                                     .fan_power = false,
                                     .rtc = false,
                                     .power_source = true,
                                     .shutdown_request = true,
                                     .ref_voltage = false,
                                     .default_on = true}};

extern device_t DEVICES[] = {pironman_u1, pipower3};
