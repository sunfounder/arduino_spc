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
  Serial.println("Battery:");
  Serial.print("Battery voltage: ");
  Serial.print(spc.batteryVoltage);
  Serial.println(" mV");
  Serial.print("Battery percentage: ");
  Serial.print(spc.batteryPercentage);
  Serial.println(" %");
  Serial.print("Is charging: ");
  Serial.println(spc.isCharging ? "Yes" : "No");
  Serial.println("Input:");
  Serial.print("Is plugged in: ");
  Serial.println(spc.isInputPluggedIn ? "Yes" : "No");
  Serial.print("Input voltage: ");
  Serial.print(spc.inputVoltage);
  Serial.println(" mV");
  Serial.println("Output:");
  Serial.print("Output voltage: ");
  Serial.print(spc.outputVoltage);
  Serial.println(" mV");
  Serial.print("Power source: ");
  Serial.println(spc.powerSource == POWER_SOURCE_EXTERNAL ? "External"
                                                          : "Battery");
  Serial.println("Other values:");
  Serial.print("Shutdown battery percentage: ");
  Serial.print(spc.shutdownBatteryPercentage);
  Serial.println(" %");
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
  Serial.print("Power source voltage: ");
  Serial.print(spc.readPowerSourceVoltage());
  Serial.println(" mV");
  Serial.print("Always on: ");
  Serial.println(spc.readIsAlwaysOn() ? "Yes" : "No");
  Serial.println("");

  delay(1000);
}