// Normally you don't need to shutdown arduino before power off, you just turn
// off the power, but if you want to do it, you can connect a io to SDSIG
// Shutdown signal, and pull it down to GND to poweroff pipower after you do
// what you want to do before poweroff.

#include "SPC.h"
#include <Wire.h>

SPC spc;

uint8_t SDSIG = 2;

void setup() {
  Serial.begin(9600);
  Serial.println(F("PiPower 3 Shutdown When Requested"));
  Wire.begin();
  pinMode(SDSIG, OUTPUT);
  digitalWrite(SDSIG, LOW);

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
  uint8_t shutdownRequest = spc.readShutdownRequest();
  if (shutdownRequest != SHUTDOWN_REQUEST_NONE) {
    Serial.print("Shutdown request: ");
    Serial.print(shutdownRequest);
    Serial.print(" - ");
    if (shutdownRequest == SHUTDOWN_REQUEST_LOW_BATTERY) {
      Serial.println("Low battery");
    } else if (shutdownRequest == SHUTDOWN_REQUEST_BUTTON) {
      Serial.println("Button");
    } else {
      Serial.println("Unknown");
    }
    Serial.println("Shutting down...");
    // Do something before shutting down
    digitalWrite(SDSIG, HIGH);
  }
  delay(1000);
}