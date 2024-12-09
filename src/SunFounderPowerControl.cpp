
#include "SunFounderPowerControl.h"

SunFounderPowerControl::SunFounderPowerControl() {}

int8_t SunFounderPowerControl::begin()
{
  uint8_t address = 0;
  uint8_t deviceIndex = 0;
  uint8_t addresses[128];
  uint8_t size = i2c.scanIntoArray(addresses);

  for (uint8_t i = 0; i < size; i++)
  {
    for (uint8_t j = 0; j < DEVICE_COUNT; j++)
    {
      if (addresses[i] == DEVICE_ADDRESSES[j])
      {
        address = addresses[i];
        deviceIndex = j;
        break;
      }
    }
  }
  if (address == 0)
    return -1;
  this->i2c.begin(address);
  this->address = address;
  this->device = DEVICES[deviceIndex];
  this->readFirmwareVersion();
  return 0;
}

uint16_t SunFounderPowerControl::readInputVoltage()
{
  if (!this->device.peripherals.input_voltage)
  {
    Serial.println(F("[Warning] Device does not support reading input voltage"));
    return -1;
  }
  return i2c.readU16(REG_READ_INPUT_VOLTAGE);
}

uint16_t SunFounderPowerControl::readInputCurrent()
{
  if (!this->device.peripherals.input_current)
  {
    Serial.println(F("[Warning] Device does not support reading input current"));
    return -1;
  }
  return i2c.readU16(REG_READ_INPUT_CURRENT);
}

uint16_t SunFounderPowerControl::readOutputVoltage()
{
  if (!this->device.peripherals.output_voltage)
  {
    Serial.println(F("[Warning] Device does not support reading output voltage"));
    return -1;
  }
  return i2c.readU16(REG_READ_OUTPUT_VOLTAGE);
}

uint16_t SunFounderPowerControl::readOutputCurrent()
{
  if (!this->device.peripherals.output_current)
  {
    Serial.println(F("[Warning] Device does not support reading output current"));
    return -1;
  }
  return i2c.readU16(REG_READ_OUTPUT_CURRENT);
}

uint16_t SunFounderPowerControl::readBatteryVoltage()
{
  if (!this->device.peripherals.battery_voltage)
  {
    Serial.println(F("[Warning] Device does not support reading battery voltage"));
    return -1;
  }
  return i2c.readU16(REG_READ_BATTERY_VOLTAGE);
}

int16_t SunFounderPowerControl::readBatteryCurrent()
{
  if (!this->device.peripherals.battery_current)
  {
    Serial.println(F("[Warning] Device does not support reading battery current"));
    return -1;
  }
  return i2c.readS16(REG_READ_BATTERY_CURRENT);
}

uint8_t SunFounderPowerControl::readBatteryPercentage()
{
  if (!this->device.peripherals.battery_percentage)
  {
    Serial.println(F("[Warning] Device does not support reading battery percentage"));
    return -1;
  }
  return i2c.readU8(REG_READ_BATTERY_PERCENTAGE);
}

uint16_t SunFounderPowerControl::readBatteryCapacity()
{
  if (!this->device.peripherals.battery_capacity)
  {
    Serial.println(F("[Warning] Device does not support reading battery capacity"));
    return -1;
  }
  return i2c.readU16(REG_READ_BATTERY_CAPACITY);
}

uint8_t SunFounderPowerControl::readPowerSource()
{
  if (!this->device.peripherals.power_source)
  {
    Serial.println(F("[Warning] Device does not support reading power source"));
    return -1;
  }
  return i2c.readU8(REG_READ_POWER_SOURCE);
}

bool SunFounderPowerControl::readIsInputPluggedIn()
{
  if (!this->device.peripherals.is_input_plugged_in)
  {
    Serial.println(F("[Warning] Device does not support reading is input plugged in"));
    return false;
  }
  return i2c.readU8(REG_READ_IS_INPUT_PLUGGED_IN);
}

bool SunFounderPowerControl::readIsCharging()
{
  if (!this->device.peripherals.is_charging)
  {
    Serial.println(F("[Warning] Device does not support reading is charging"));
    return false;
  }
  return i2c.readU8(REG_READ_IS_CHARGING);
}

uint8_t SunFounderPowerControl::readFanPower()
{
  if (!this->device.peripherals.fan_power)
  {
    Serial.println(F("[Warning] Device does not support reading fan power"));
    return -1;
  }
  return i2c.readU8(REG_READ_FAN_POWER);
}

uint8_t SunFounderPowerControl::readShutdownRequest()
{
  if (!this->device.peripherals.shutdown_request)
  {
    Serial.println(F("[Warning] Device does not support reading shutdown request"));
    return -1;
  }
  return i2c.readU8(REG_READ_SHUTDOWN_REQUEST);
}

bool SunFounderPowerControl::readIsDefaultOn()
{
  if (!this->device.peripherals.default_on)
  {
    Serial.println(F("[Warning] Device does not support reading default on"));
    return false;
  }
  return i2c.readU8(REG_READ_IS_DEFAULT_ON);
}

uint8_t SunFounderPowerControl::readBoardId() { return i2c.readU8(REG_READ_BOARD_ID); }

uint8_t SunFounderPowerControl::readShutdownPercentage()
{
  if (!this->device.peripherals.shutdown_percentage)
  {
    Serial.println(F("[Warning] Device does not support reading shutdown percentage"));
    return -1;
  }
  return i2c.readU8(REG_READ_SHUTDOWN_PERCENTAGE);
}

void SunFounderPowerControl::writeFanPower(uint8_t power)
{
  if (!this->device.peripherals.fan_power)
  {
    Serial.println(F("[Warning] Device does not support setting fan power"));
    return;
  }
  i2c.writeU8(REG_WRITE_FAN_POWER, power);
}

void SunFounderPowerControl::writeShutdownPercentage(uint8_t percentage)
{
  if (!this->device.peripherals.shutdown_percentage)
  {
    Serial.println(F("[Warning] Device does not support setting shutdown percentage"));
    return;
  }
  percentage = constrain(percentage, SHUTDOWN_PERCENTAGE_MIN, SHUTDOWN_PERCENTAGE_MAX);
  i2c.writeU8(REG_WRITE_SHUTDOWN_PERCENTAGE, percentage);
}

void SunFounderPowerControl::readAll()
{
  uint8_t buffer[REG_READ_COMMON_LENGTH];
  uint8_t size = i2c.readIntoArray(REG_READ_START, buffer, REG_READ_COMMON_LENGTH);
  // Serial.print("Read size: ");Serial.println(size);
  // Serial.print("[");
  // for (uint8_t i = 0; i < REG_READ_COMMON_LENGTH; i++) {
  //     Serial.print(buffer[i]);
  //     if (i < 21) Serial.print(", ");
  // }
  // Serial.println("]");
  this->inputVoltage = buffer[1] << 8 | buffer[0];
  this->inputCurrent = buffer[3] << 8 | buffer[2];
  this->outputVoltage = buffer[5] << 8 | buffer[4];
  this->outputCurrent = buffer[7] << 8 | buffer[6];
  this->batteryVoltage = buffer[9] << 8 | buffer[8];
  this->batteryCurrent = buffer[11] << 8 | buffer[10];
  this->batteryPercentage = buffer[12];
  this->batteryCapacity = buffer[14] << 8 | buffer[13];
  this->powerSource = buffer[15];
  this->isInputPluggedIn = buffer[16];
  this->isCharging = buffer[18];
  this->fanPower = buffer[19];
  this->shutdownRequest = buffer[20];
}

String SunFounderPowerControl::readFirmwareVersion()
{
  this->firmwareVersionMajor = i2c.readU8(REG_READ_FIRMWARE_VERSION_MAJOR);
  this->firmwareVersionMinor = i2c.readU8(REG_READ_FIRMWARE_VERSION_MINOR);
  this->firmwareVersionPatch = i2c.readU8(REG_READ_FIRMWARE_VERSION_PATCH);
  this->firmwareVersion = String(this->firmwareVersionMajor) + "." +
                          String(this->firmwareVersionMinor) + "." +
                          String(this->firmwareVersionPatch);
  return this->firmwareVersion;
}
