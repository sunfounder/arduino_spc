// Normally you don't need to shutdown arduino before power off, you just turn
// off the power, but if you want to do it, you can connect a io to SDSIG
// Shutdown signal, and pull it down to GND to poweroff pipower after you do
// what you want to do before poweroff.

#include <SunFounderPowerControl.h>
#include <Wire.h>

SunFounderPowerControl spc;

uint8_t SDSIG = 2;

void setup()
{
  Serial.begin(9600);
  Serial.println(F("PiPower 3 Shutdown When Requested"));
  Wire.begin();
  pinMode(SDSIG, OUTPUT);
  digitalWrite(SDSIG, LOW);

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
  delay(1000);

  uint8_t shutdownRequest = spc.readShutdownRequest();

  if (shutdownRequest != SHUTDOWN_REQUEST_NONE)
  {
    Serial.print(F("Shutdown request: "));
    Serial.print(shutdownRequest);
    Serial.print(F(" - "));
    if (shutdownRequest == SHUTDOWN_REQUEST_LOW_BATTERY)
    {
      Serial.println(F("Low battery"));
    }
    else if (shutdownRequest == SHUTDOWN_REQUEST_BUTTON)
    {
      Serial.println(F("Button"));
    }
    else
    {
      Serial.println(F("Unknown"));
      digitalWrite(SDSIG, LOW);
      return;
    }
    Serial.println(F("Shutting down..."));
    // Do something before shutting down
    digitalWrite(SDSIG, HIGH);
  }
  else
  {
    digitalWrite(SDSIG, LOW);
  }
}
