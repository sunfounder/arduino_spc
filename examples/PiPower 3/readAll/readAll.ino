#include "SunFounderPowerControl.h"
#include <Wire.h>

SunFounderPowerControl spc;

void setup() {
  Serial.begin(9600);
  Serial.println(F("PiPower 3 Read All"));
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
  spc.readAll();
  Serial.print("Input voltage: ");
  Serial.print(spc.inputVoltage);
  Serial.println(" mV");
  Serial.print("Output voltage: ");
  Serial.print(spc.outputVoltage);
  Serial.println(" mV");
  Serial.print("Battery voltage: ");
  Serial.print(spc.batteryVoltage);
  Serial.println(" mV");
  Serial.print("Battery percentage: ");
  Serial.print(spc.batteryPercentage);
  Serial.println(" %");
  Serial.print("Power source: ");
  Serial.print(spc.powerSource);
  Serial.print(" - ");
  Serial.println(spc.powerSource == POWER_SOURCE_EXTERNAL ? "External"
                                                          : "Battery");
  Serial.print("Is inut plugged in: ");
  Serial.println(spc.isInputPluggedIn ? "Yes" : "No");
  Serial.print("Is charging: ");
  Serial.println(spc.isCharging ? "Yes" : "No");
  Serial.println("Internal data:");
  Serial.print("Shutdown request: ");
  Serial.print(spc.shutdownRequest);
  Serial.print(" - ");
  if (spc.shutdownRequest == SHUTDOWN_REQUEST_NONE) {
    Serial.println("None");
  } else if (spc.shutdownRequest == SHUTDOWN_REQUEST_LOW_BATTERY) {
    Serial.println("Low battery");
  } else if (spc.shutdownRequest == SHUTDOWN_REQUEST_BUTTON) {
    Serial.println("Button");
  } else {
    Serial.println("Unknown");
  }
  Serial.print("Default on: ");
  Serial.println(spc.readIsDefaultOn() ? "Yes" : "No");
  Serial.print("Shutdown percentage: ");
  Serial.print(spc.readShutdownPercentage());
  Serial.println(" %");

  Serial.println("");

  delay(1000);
}