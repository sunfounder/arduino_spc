#include <SunFounderPowerControl.h>
#include <Wire.h>

SunFounderPowerControl spc;

void setup() {
  Serial.begin(9600);
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
  Serial.println("Set power off percentage example, power off percentage means when battery percentage is less than the power off percentage, the device will cut off the power to protect battery.");
  delay(2000);
  Serial.print("Power Off percentage: ");
  Serial.println(spc.readPowerOffPercentage());
  delay(2000);

  Serial.println("Setting power off percentage to 20%");
  spc.writePowerOffPercentage(20);
  delay(2000); // Wait for the power off percentage to be updated
  int current_power_off_percentage = spc.readPowerOffPercentage();
  Serial.print("Power Off percentage: ");
  Serial.println(current_power_off_percentage);
  if (current_power_off_percentage == 20) {
    Serial.println("Success");
  }
  delay(2000);

  Serial.println("Setting power off percentage to 10%");
  spc.writePowerOffPercentage(10);
  delay(2000); // Wait for the power off percentage to be updated
  current_power_off_percentage = spc.readPowerOffPercentage();
  Serial.print("Power Off percentage: ");
  Serial.println(current_power_off_percentage);
  if (current_power_off_percentage == 10) {
    Serial.println("Success");
  }
  delay(2000);

  Serial.println("Setting power off percentage to 0%");
  spc.writePowerOffPercentage(0);
  delay(2000); // Wait for the power off percentage to be updated
  current_power_off_percentage = spc.readPowerOffPercentage();
  Serial.print("Power Off percentage: ");
  Serial.println(current_power_off_percentage);
  if (current_power_off_percentage == 0) {
    Serial.println("Success");
  } else {
    Serial.println("Failed, power off percentage minimal is 5%");
  }
}

void loop() {}