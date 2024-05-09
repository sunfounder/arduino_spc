#ifndef __SPC_H__
#define __SPC_H__

#include "Arduino.h"
#include "devices.h"
#include "i2c.h"

#define POWER_SOURCE_EXTERNAL 0x00
#define POWER_SOURCE_BATTERY 0x01

#define SHUTDOWN_REQUEST_NONE 0x00
#define SHUTDOWN_REQUEST_LOW_BATTERY 0x01
#define SHUTDOWN_REQUEST_BUTTON 0x02

#define SHUTDOWN_PERCENTAGE_MIN 10
#define SHUTDOWN_PERCENTAGE_MAX 100
#define POWER_OFF_PERCENTAGE_MIN 10
#define POWER_OFF_PERCENTAGE_MAX 100

#define REG_READ_START 0x00
#define REG_READ_COMMON_LENGTH 21

#define REG_READ_INPUT_VOLTAGE 0x00
#define REG_READ_INPUT_CURRENT 0x02
#define REG_READ_OUTPUT_VOLTAGE 0x04
#define REG_READ_OUTPUT_CURRENT 0x06
#define REG_READ_BATTERY_VOLTAGE 0x08
#define REG_READ_BATTERY_CURRENT 0x0A
#define REG_READ_BATTERY_PERCENTAGE 0x0C
#define REG_READ_BATTERY_CAPACITY 0x0D
#define REG_READ_POWER_SOURCE 0x0F
#define REG_READ_IS_INPUT_PLUGGED_IN 0x10
#define REG_READ_IS_CHARGING 0x12
#define REG_READ_FAN_POWER 0x13
#define REG_READ_SHUTDOWN_REQUEST 0x14

#define REG_READ_FIRMWARE_VERSION_MAJOR 0x80
#define REG_READ_FIRMWARE_VERSION_MINOR 0x81
#define REG_READ_FIRMWARE_VERSION_PATCH 0x82
#define REG_READ_RTC_CODE 0x83
#define REG_READ_RTC_YEAR 0x84
#define REG_READ_RTC_MONTH 0x85
#define REG_READ_RTC_DAY 0x86
#define REG_READ_RTC_HOUR 0x87
#define REG_READ_RTC_MINUTE 0x88
#define REG_READ_RTC_SECOND 0x89
#define REG_READ_RTC_MILLISECOND 0x8A
#define REG_READ_IS_DEFAULT_ON 0x8B
#define REG_READ_BOARD_ID 0x8C
#define REG_READ_SHUTDOWN_PERCENTAGE 0x8F
#define REG_READ_POWER_OFF_PERCENTAGE 0x90

#define REG_WRITE_FAN_POWER 0x00
#define REG_WRITE_RTC_YEAR 0x01
#define REG_WRITE_RTC_MONTH 0x02
#define REG_WRITE_RTC_DAY 0x03
#define REG_WRITE_RTC_HOUR 0x04
#define REG_WRITE_RTC_MINUTE 0x05
#define REG_WRITE_RTC_SECOND 0x06
#define REG_WRITE_RTC_MILLISECOND 0x07
#define REG_WRITE_RTC_SETTING 0x08
#define REG_WRITE_SHUTDOWN_PERCENTAGE 0x09
#define REG_WRITE_POWER_OFF_PERCENTAGE 0x0A

extern device_t DEVICES[];
extern uint8_t DEVICE_ADDRESSES[];
extern uint8_t DEVICE_COUNT;

class SunFounderPowerControl {
  public:
    SunFounderPowerControl();
    int8_t begin();
    uint16_t readInputVoltage();
    uint16_t readInputCurrent();
    uint16_t readOutputVoltage();
    uint16_t readOutputCurrent();
    uint16_t readBatteryVoltage();
    int16_t readBatteryCurrent();
    uint8_t readBatteryPercentage();
    uint16_t readBatteryCapacity();
    uint16_t readReferenceVoltage();
    uint8_t readPowerSource();
    bool readIsInputPluggedIn();
    bool readIsCharging();
    uint8_t readFanPower();
    uint8_t readShutdownRequest();
    void readAll();

    bool readIsDefaultOn();
    uint8_t readBoardId();
    uint8_t readShutdownPercentage();
    uint8_t readPowerOffPercentage();

    void writeFanPower(uint8_t power);
    void writeShutdownPercentage(uint8_t percentage);
    void writePowerOffPercentage(uint8_t percentage);
    uint8_t firmwareVersionMajor;
    uint8_t firmwareVersionMinor;
    uint8_t firmwareVersionPatch;
    String firmwareVersion;
    device_t device;

    uint16_t inputVoltage;
    int16_t inputCurrent;
    uint16_t outputVoltage;
    int16_t outputCurrent;
    uint16_t batteryVoltage;
    int16_t batteryCurrent;
    uint8_t batteryPercentage;
    uint16_t batteryCapacity;
    uint8_t powerSource;
    bool isInputPluggedIn;
    bool isCharging;
    uint8_t fanPower;
    uint8_t shutdownRequest;

  private:
    uint8_t address;
    I2C i2c;

    String readFirmwareVersion();
};

#endif // __SPC_H__