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
  Serial.println("Battery:");
  Serial.print("Battery voltage: ");
  Serial.print(spc.readBatteryVoltage());
  Serial.println(" mV");
  Serial.print("Battery percentage: ");
  Serial.print(spc.readBatteryPercentage());
  Serial.println(" %");
  Serial.print("Is charging: ");
  Serial.println(spc.readIsCharging() ? "Yes" : "No");
  Serial.println("Input:");
  Serial.print("Is plugged in: ");
  Serial.println(spc.readIsInputPluggedIn() ? "Yes" : "No");
  Serial.print("Input voltage: ");
  Serial.print(spc.readInputVoltage());
  Serial.println(" mV");
  Serial.println("Output:");
  Serial.print("Output voltage: ");
  Serial.print(spc.readOutputVoltage());
  Serial.println(" mV");
  Serial.print("Power source: ");
  Serial.println(spc.readPowerSource() == POWER_SOURCE_EXTERNAL ? "External"
                                                                : "Battery");
  Serial.println("Other values:");
  Serial.print("Shutdown battery percentage: ");
  Serial.print(spc.readShutdownBatteryPercentage());
  Serial.println(" %");
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
  Serial.print("Power source voltage: ");
  Serial.print(spc.readPowerSourceVoltage());
  Serial.println(" mV");
  Serial.print("Always on: ");
  Serial.println(spc.readIsAlwaysOn() ? "Yes" : "No");
  Serial.println("");

  delay(1000);
}