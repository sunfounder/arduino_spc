#include <SunFounderPowerControl.h>
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
  Serial.print("Board name: ");
  Serial.println(spc.device.name);
  Serial.print("Firmware Version: ");
  Serial.println(spc.firmwareVersion.c_str());
  Serial.println("Set shutdown percentage example, shutdown percentage means if it's not charging, and the battery percentage is less than the shutdown percentage, it will give a shutdown request Low Battery, for device to safely shutdown.");
  delay(2000);
  Serial.print("Shutdown percentage: ");
  Serial.println(spc.readShutdownPercentage());
  delay(2000);

  Serial.println("Setting shutdown percentage to 20%");
  spc.writeShutdownPercentage(20);
  delay(2000); // Wait for the shutdown percentage to be updated
  int current_shutdown_percentage = spc.readShutdownPercentage();
  Serial.print("Shutdown percentage: ");
  Serial.println(current_shutdown_percentage);
  if (current_shutdown_percentage == 20) {
    Serial.println("Success");
  }
  delay(2000);

  Serial.println("Setting shutdown percentage to 10%");
  spc.writeShutdownPercentage(10);
  delay(2000); // Wait for the shutdown percentage to be updated
  current_shutdown_percentage = spc.readShutdownPercentage();
  Serial.print("Shutdown percentage: ");
  Serial.println(current_shutdown_percentage);
  if (current_shutdown_percentage == 10) {
    Serial.println("Success");
  }
  delay(2000);

  Serial.println("Setting shutdown percentage to 5%");
  spc.writeShutdownPercentage(5);
  delay(2000); // Wait for the shutdown percentage to be updated
  current_shutdown_percentage = spc.readShutdownPercentage();
  Serial.print("Shutdown percentage: ");
  Serial.println(current_shutdown_percentage);
  if (current_shutdown_percentage == 5) {
    Serial.println("Success");
  } else {
    Serial.println("Failed, shutdown percentage minimal is 10%");
  }
}

void loop() {}