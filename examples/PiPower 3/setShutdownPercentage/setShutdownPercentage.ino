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
  Serial.print("Shutdown battery percentage: ");
  Serial.println(spc.readShutdownBatteryPercentage());
  delay(2000);

  Serial.println("Setting shutdown battery percentage to 20%");
  spc.writeShutdownBatteryPercentage(20);
  delay(2000); // Wait for the shutdown battery percentage to be updated
  int current_shutdown_battery_percentage = spc.readShutdownBatteryPercentage();
  Serial.print("Shutdown battery percentage: ");
  Serial.println(current_shutdown_battery_percentage);
  if (current_shutdown_battery_percentage == 20) {
    Serial.println("Success");
  }
  delay(2000);

  Serial.println("Setting shutdown battery percentage to 10%");
  spc.writeShutdownBatteryPercentage(10);
  delay(2000); // Wait for the shutdown battery percentage to be updated
  current_shutdown_battery_percentage = spc.readShutdownBatteryPercentage();
  Serial.print("Shutdown battery percentage: ");
  Serial.println(current_shutdown_battery_percentage);
  if (current_shutdown_battery_percentage == 10) {
    Serial.println("Success");
  }
  delay(2000);

  Serial.println("Setting shutdown battery percentage to 5%");
  spc.writeShutdownBatteryPercentage(5);
  delay(2000); // Wait for the shutdown battery percentage to be updated
  current_shutdown_battery_percentage = spc.readShutdownBatteryPercentage();
  Serial.print("Shutdown battery percentage: ");
  Serial.println(current_shutdown_battery_percentage);
  if (current_shutdown_battery_percentage == 5) {
    Serial.println("Success");
  } else {
    Serial.println("Failed, shutdown battery percentage minimal is 10%");
  }
}

void loop() {}