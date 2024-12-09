#include "SunFounderPowerControl.h"
#include <Wire.h>

SunFounderPowerControl spc;

void setup()
{
  Serial.begin(9600);
  Serial.println(F("PiPower 3 Read All"));
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
}

void loop()
{
  spc.readAll();
  Serial.print(F("Input voltage: "));
  Serial.print(spc.inputVoltage);
  Serial.println(F(" mV"));
  Serial.print(F("Output voltage: "));
  Serial.print(spc.outputVoltage);
  Serial.println(F(" mV"));
  Serial.print(F("Battery voltage: "));
  Serial.print(spc.batteryVoltage);
  Serial.println(F(" mV"));
  Serial.print(F("Battery percentage: "));
  Serial.print(spc.batteryPercentage);
  Serial.println(F(" %"));
  Serial.print(F("Power source: "));
  Serial.print(spc.powerSource);
  Serial.print(F(" - "));
  Serial.println(spc.powerSource == POWER_SOURCE_EXTERNAL ? "External"
                                                          : "Battery");
  Serial.print(F("Is inut plugged in: "));
  Serial.println(spc.isInputPluggedIn ? "Yes" : "No");
  Serial.print(F("Is charging: "));
  Serial.println(spc.isCharging ? "Yes" : "No");
  Serial.println(F("Internal data:"));
  Serial.print(F("Shutdown request: "));
  Serial.print(spc.shutdownRequest);
  Serial.print(F(" - "));
  if (spc.shutdownRequest == SHUTDOWN_REQUEST_NONE)
  {
    Serial.println(F("None"));
  }
  else if (spc.shutdownRequest == SHUTDOWN_REQUEST_LOW_BATTERY)
  {
    Serial.println(F("Low battery"));
  }
  else if (spc.shutdownRequest == SHUTDOWN_REQUEST_BUTTON)
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
