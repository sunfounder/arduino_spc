#include <SunFounderPowerControl.h>
#include <Wire.h>

SunFounderPowerControl spc;

void setup()
{
  Serial.begin(9600);
  Serial.println(F("PiPower 5 Set Shutdown Percentage"));
  Wire.begin();

  while (spc.begin() == -1)
  {
    Serial.println("[ERROR] Device not found");
    delay(3000);
  }
  Serial.println(F("Device found"));
  Serial.print(F("Board name: "));
  Serial.println(spc.device.name);
  Serial.print(F("Firmware Version: "));
  Serial.println(spc.firmwareVersion.c_str());

  Serial.println(F(
      "\nSet shutdown percentage example, shutdown percentage means if it's not charging, and\n"
      "the battery percentage is less than the shutdown percentage,it will give a shutdown request\n"
      "Low Battery, for device to safely shutdown.\n"));
  delay(2000);
  Serial.print(F("Shutdown percentage: "));
  Serial.println(spc.readShutdownPercentage());
  delay(2000);

  Serial.println(F("Setting shutdown percentage to 20%"));
  spc.writeShutdownPercentage(20);
  delay(2000); // Wait for the shutdown percentage to be updated
  int current_shutdown_percentage = spc.readShutdownPercentage();
  Serial.print(F("Shutdown percentage: "));
  Serial.println(current_shutdown_percentage);
  if (current_shutdown_percentage == 20)
  {
    Serial.println(F("Success"));
  }
  delay(2000);

  Serial.println(F("Setting shutdown percentage to 10%"));
  spc.writeShutdownPercentage(10);
  delay(2000); // Wait for the shutdown percentage to be updated
  current_shutdown_percentage = spc.readShutdownPercentage();
  Serial.print(F("Shutdown percentage: "));
  Serial.println(current_shutdown_percentage);
  if (current_shutdown_percentage == 10)
  {
    Serial.println(F("Success"));
  }
  delay(2000);

  Serial.println(F("Setting shutdown percentage to 5%"));
  spc.writeShutdownPercentage(5);
  delay(2000); // Wait for the shutdown percentage to be updated
  current_shutdown_percentage = spc.readShutdownPercentage();
  Serial.print(F("Shutdown percentage: "));
  Serial.println(current_shutdown_percentage);
  if (current_shutdown_percentage == 5)
  {
    Serial.println(F("Success"));
  }
  else
  {
    Serial.println(F("Failed, shutdown percentage minimal is 10%"));
  }
}

void loop() {}
