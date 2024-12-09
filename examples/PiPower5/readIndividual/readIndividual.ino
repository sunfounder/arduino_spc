#include "SunFounderPowerControl.h"
#include <Wire.h>

SunFounderPowerControl spc;

void setup()
{
  Serial.begin(9600);
  Serial.println(F("PiPower 5 Read "));
  Wire.begin();

  while (spc.begin() == -1)
  {
    Serial.println(F("[ERROR] Device not found"));
    delay(3000);
  }
  Serial.println(F("Device found"));
  Serial.print(F("Device name: "));
  Serial.println(spc.device.name);
  Serial.print(F("Firmware version: "));
  Serial.println(spc.firmwareVersion.c_str());
  Serial.println();
  delay(3000);
}

void loop()
{
  Serial.print(F("Input voltage: "));
  Serial.print(spc.readInputVoltage());
  Serial.println(F(" mV"));
  Serial.print(F("Output voltage: "));
  Serial.print(spc.readOutputVoltage());
  Serial.println(F(" mV"));
  Serial.print(F("Output current: "));
  Serial.print(spc.readOutputCurrent());
  Serial.println(F(" mA"));
  Serial.print(F("Battery voltage: "));
  Serial.print(spc.readBatteryVoltage());
  Serial.println(F(" mV"));
  Serial.print(F("Battery current: "));
  Serial.print(spc.readBatteryCurrent());
  Serial.println(F(" mA"));
  Serial.print(F("Battery percentage: "));
  Serial.print(spc.readBatteryPercentage());
  Serial.println(F(" %"));
  uint8_t powerSource = spc.readPowerSource();
  Serial.print(F("Power source: "));
  Serial.print(powerSource);
  Serial.print(F(" - "));
  Serial.println(powerSource == POWER_SOURCE_EXTERNAL ? "External" : "Battery");
  Serial.print(F("Is input plugged in: "));
  Serial.println(spc.readIsInputPluggedIn() ? "Yes" : "No");
  Serial.print(F("Is charging: "));
  Serial.println(spc.readIsCharging() ? "Yes" : "No");
  Serial.println(F("Internal data:"));
  Serial.print(F("Shutdown request: "));
  uint8_t shutdownRequest = spc.readShutdownRequest();

  Serial.print(shutdownRequest);
  Serial.print(F(" - "));
  if (shutdownRequest == SHUTDOWN_REQUEST_NONE)
  {
    Serial.println(F("None"));
  }
  else if (shutdownRequest == SHUTDOWN_REQUEST_LOW_BATTERY)
  {
    Serial.println(F("Low battery"));
  }
  else if (shutdownRequest == SHUTDOWN_REQUEST_BUTTON)
  {
    Serial.println(F("Button"));
  }
  else
  {
    Serial.println(F("Unknown"));
  }

  Serial.print(F("Default on: "));
  Serial.println(spc.readIsDefaultOn() ? "Yes" : "No");
  Serial.print(F("Shutdown percentage: "));
  Serial.print(spc.readShutdownPercentage());
  Serial.println(F(" %"));

  Serial.println("");

  delay(1000);
}
