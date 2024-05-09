#include "SunFounderPowerControl.h"
#include <Wire.h>

SunFounderPowerControl spc;

void setup() {
  Serial.begin(9600);
  Serial.println(F("PiPower 3 Read Individually"));
  Wire.begin();

  int8_t result = spc.begin();
  if (result == -1) {
    Serial.println("[ERROR] Device not found");
    while (1);;
  }
  Serial.println("Device found");
  Serial.print("Device name: ");
  Serial.println(spc.device.name);
  Serial.print("Firmware version: ");
  Serial.println(spc.firmwareVersion.c_str());
}

void loop() {
  Serial.print("Input voltage: ");
  Serial.print(spc.readInputVoltage());
  Serial.println(" mV");
  Serial.print("Output voltage: ");
  Serial.print(spc.readOutputVoltage());
  Serial.println(" mV");
  Serial.print("Battery voltage: ");
  Serial.print(spc.readBatteryVoltage());
  Serial.println(" mV");
  Serial.print("Battery percentage: ");
  Serial.print(spc.readBatteryPercentage());
  Serial.println(" %");
  uint8_t powerSource = spc.readPowerSource();
  Serial.print("Power source: ");
  Serial.print(powerSource);
  Serial.print(" - ");
  Serial.println(powerSource == POWER_SOURCE_EXTERNAL ? "External" : "Battery");
  Serial.print("Is input plugged in: ");
  Serial.println(spc.readIsInputPluggedIn() ? "Yes" : "No");
  Serial.print("Is charging: ");
  Serial.println(spc.readIsCharging() ? "Yes" : "No");
  Serial.println("Internal data:");
  Serial.print("Shutdown request: ");
  uint8_t shutdownRequest = spc.readShutdownRequest();
  Serial.print(shutdownRequest);
  Serial.print(" - ");
  if (shutdownRequest == SHUTDOWN_REQUEST_NONE) {
    Serial.println("None");
  } else if (shutdownRequest == SHUTDOWN_REQUEST_LOW_BATTERY) {
    Serial.println("Low battery");
  } else if (shutdownRequest == SHUTDOWN_REQUEST_BUTTON) {
    Serial.println("Button");
  } else {
    Serial.println("Unknown");
  }
  Serial.print("Default on: ");
  Serial.println(spc.readIsDefaultOn() ? "Yes" : "No");
  Serial.print("Shutdown percentage: ");
  Serial.print(spc.readShutdownPercentage());
  Serial.println(" %");
  Serial.print("Power off percentage: ");
  Serial.print(spc.readPowerOffPercentage());
  Serial.println(" %");

  Serial.println("");

  delay(1000);
}