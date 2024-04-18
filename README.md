# SunFounder_Power_Control

## API

### Class SunFounderPowerControl()

Class for SunFounder Power Control.

```
SunFounderPowerControl spc;
```

### Properties

#### device_t SunFounderPowerControl.device

current device type.

```
Serial.println(spc.device.name)
```

#### String SunFounderPowerControl.firmwareVersion

firmware version

```
Serial.println(spc.firmwareVersion.c_str())
```


### Methods

#### int8_t SunFounderPowerControl.begin()

Begin 

```
int8_t result = spc.begin();
if (result == -1) {
    Serial.println("[ERROR] Device not found");
    while (1);;
}
```

#### uint16_t SunFounderPowerControl.readInputVoltage()

Read the input voltage in mV.

```
Serial.print("Input voltage: ");
Serial.print(spc.readInputVoltage());
Serial.println(" mV");
```

#### uint16_t SunFounderPowerControl.readInputCurrent()

Read the input current in mA.

```
Serial.print("Input current: ");
Serial.print(spc.readInputCurrent());
Serial.println(" mA");
```

#### uint16_t SunFounderPowerControl.readOutputVoltage()

Read the output voltage in mV.

```
Serial.print("Output voltage: ");
Serial.print(spc.readOutputVoltage());
Serial.println(" mV");
```

#### uint16_t SunFounderPowerControl.readOutputCurrent()

Read the output current in mA.

```
Serial.print("Output current: ");
Serial.print(spc.readOutputCurrent());
Serial.println(" mA");
```

#### uint16_t SunFounderPowerControl.readBatteryVoltage()

Read the battery voltage in mV.

```
Serial.print("Battery voltage: ");
Serial.print(spc.readBatteryVoltage());
Serial.println(" mV");
```

#### int16_t SunFounderPowerControl.readBatteryCurrent()

Read the battery current in mA.

```
Serial.print("Battery current: ");
Serial.print(spc.readBatteryCurrent());
Serial.println(" mA");
```

#### uint8_t SunFounderPowerControl.readBatteryPercentage()

Read the battery percentage in %.

```
Serial.print("Battery percentage: ");
Serial.print(spc.readBatteryPercentage());
Serial.println(" %");
```

#### uint16_t SunFounderPowerControl.readBatteryCapacity()

Read the battery capacity in mAh.

```
Serial.print("Battery capacity: ");
Serial.print(spc.readBatteryCapacity());
Serial.println(" mAh");
```

#### uint8_t SunFounderPowerControl.readPowerSource()

Read the power source. 0: EXTERNAL_INPUT, 1: BATTERY.

```
uint8_t power_source = spc.readPowerSource();
if (power_source == spc.EXTERNAL_INPUT) {
    Serial.println("Power source: EXTERNAL_INPUT");
} else if (power_source == spc.BATTERY) {
    Serial.println("Power source: BATTERY");
} else {
    Serial.println("Unknown power source");
}
```

#### bool SunFounderPowerControl.readIsInputPluggedIn()

Read if the input is plugged in.

```
bool is_input_plugged_in = spc.readIsInputPluggedIn();
Serial.print("Is input plugged in: ");
Serial.println(is_input_plugged_in);
```

#### bool SunFounderPowerControl.readIsBatteryPluggedIn()

Read if the battery is plugged in.

```
bool is_battery_plugged_in = spc.readIsBatteryPluggedIn();
Serial.print("Is battery plugged in: ");
Serial.println(is_battery_plugged_in);
```

#### bool SunFounderPowerControl.readIsCharging()

Read if the battery is charging.

```
bool is_charging = spc.readIsCharging();
Serial.print("Is charging: ");
Serial.println(is_charging);
```

#### uint8_t SunFounderPowerControl.readFanPower()

Read the fan power in %.

```
uint8_t fan_power = spc.readFanPower();
Serial.print("Fan power: ");
Serial.println(fan_power);
```

#### uint8_t SunFounderPowerControl.readShutdownRequest()

Read if a shutdown request is received. 0: None, 1: Low battery, 2: Button.

```
uint8_t shutdown_request = spc.readShutdownRequest();
if (shutdown_request == spc.SHUTDOWN_REQUEST_NONE) {
    Serial.println("Shutdown request: None");
} else if (shutdown_request == spc.SHUTDOWN_REQUEST_LOW_BATTERY) {
    Serial.println("Shutdown request: Low battery");
} else if (shutdown_request == spc.SHUTDOWN_REQUEST_BUTTON) {
    Serial.println("Shutdown request: Button");
} else {
    Serial.println("Unknown shutdown request");
}
```

#### bool SunFounderPowerControl.readAlwaysOn()

Read if the always-on mode is enabled.

```
bool always_on = spc.readAlwaysOn();
Serial.print("Always on: ");
Serial.println(always_on);
```

#### uint16_t SunFounderPowerControl.readPowerSourceVoltage()

Read the power source voltage in mV.

```
uint16_t power_source_voltage = spc.readPowerSourceVoltage();
Serial.print("Power source voltage: ");
Serial.println(power_source_voltage);
```

#### uint8_t SunFounderPowerControl.readShutdownPercentage()

Read the shutdown percentage in %.

```
uint8_t shutdown_percentage = spc.readShutdownPercentage();
Serial.print("Shutdown percentage: ");
Serial.println(shutdown_percentage);
```


#### uint8_t SunFounderPowerControl.readPowerOffPercentage()

Read the power off percentage in %.

```
uint8_t power_off_percentage = spc.readPowerOffPercentage();
Serial.print("Power off percentage: ");
Serial.println(power_off_percentage);
```

#### void SunFounderPowerControl.readAll()

Read all avaliable the data into the class.

```
spc.readAll();
Serial.println(spc.inputVoltage);
Serial.println(spc.inputCurrent);
Serial.println(spc.outputVoltage);
```

#### void SunFounderPowerControl.writeFanPower(uint8_t power)

Write the fan power in %.

```
spc.writeFanPower(50);
```

#### void SunFounderPowerControl.writeShutdownPercentage(uint8_t percentage)

Write the shutdown percentage in %. Range: 10-100

```
spc.writeShutdownPercentage(10);
```

#### void SunFounderPowerControl.writePowerOffPercentage(uint8_t percentage)

Write the power off percentage in %. Range: 5-100

```
spc.writePowerOffPercentage(10);
```

### Constants

#### POWER_SOURCE_EXTERNAL

Power source: EXTERNAL_INPUT.

#### POWER_SOURCE_BATTERY

Power source: BATTERY.

#### SHUTDOWN_REQUEST_NONE

Shutdown request: None.

#### SHUTDOWN_REQUEST_LOW_BATTERY

Shutdown request: Low battery.

#### SHUTDOWN_REQUEST_BUTTON

Shutdown request: Button.

## Data Buffer Sheet

### dataBuffer

|name|addr|len|type|unit|description|
|:--|:--:|:--:|:--:|:--:|:--|
|external_input_voltage|0|2|u16|mV|-|
|external_input_current|2|2|u16|mA|-|
|output_voltage|4|2|u16|mV|-|
|output_current|6|2|u16|mA|-|
|battery_voltage|8|2|u16|mV|-|
|battery_current|10|2|int16|mA|-|
|battery_percentage|12|1|u8|%|-|
|battery_capacity|13|2|u16|mAh|-|
|power_source|15|1|u8|-| 0,  battery isn't supplying power; <br> 1,  battery is supplying power;|
|is_usb_plugged|16|1|u8|-| 0, usb is unplugged; <br> 1, usb is plugged in;|
|is_battery_plugged|17|1|u8|-| 0, battery is unplugged; <br> 1, battery is plugged in;|
|is_charging|18|1|u8|-| 0, not charging; <br> 1, charging;|
|fan_power|19|1|u8|-| 0 ~ 100|
|shutdown_request|20|1|u8|-| 1, Key shutdown request; <br> 1, Low battery shutdown request;|
|-|-|-|-|-|-|
|-|-|-|-|-|-|
|firmware_version_major|128|1|u8|-|-|
|firmware_version_minor|129|1|u8|-|-|
|firmware_version_micro|130|1|u8|-|-|
|rst_code|131|1|u8|-|mcu reset reason Code|
|rtc_year|132|1|u8|-|-|
|rtc_month|133|1|u8|-|-|
|rtc_day|134|1|u8|-|-|
|rtc_hour|135|1|u8|-|-|
|rtc_minute|136|1|u8|-|-|
|rtc_second|137|1|u8|-|-|
|rtc_ssec|138|1|u8|-|1/128 second|
|alwaysOn|139|1|u8|-|0, Enable alwaysOn <br> 1, Disable alwaysOn|
|board_id|140|1|u8|-|0, Pironman U1 <br> 1, Pironman 4 <br> 2, Pipower 3|
|powerSourceVoltage|141|2|u16|-|-|
|shutdown_percentage|143|1|u8|-| Current low battery shutdown percentage threshold|
|power_off_percentage|144|1|u8|-| Current low battery power off percentage threshold|
|-|-|-|-|-|-|
|-|-|-|-|-|-|

### settingBuffer

|name|addr|len|type|unit|description|
|:--|:--:|:--:|:--:|:--:|:--|
|fan_speed|0|1|u8|-|setting fan speed (0~100)|
|rtc_year|1|1|u8|-|setting rtc_year|
|rtc_month|2|1|u8|-|setting rtc_month|
|rtc_day|3|1|u8|-|setting rtc_day|
|rtc_hour|4|1|u8|-|setting rtc_hour|
|rtc_minute|5|1|u8|-|setting rtc_minute|
|rtc_second|6|1|u8|-|setting rtc_second|
|rtc_ssec|7|1|u8|-|setting rtc 1/128 second|
|rtc_setting|8|1|u8|-|1, enable rtc setting|
|shutdown_percentage|9|1|u8|-|setting low battery shutdown percentage threshold (0~100)|
|power_off_percentage|10|1|u8|-|setting low battery power off percentage threshold (0~100)|
|-|-|-|-|-|-|
|-|-|-|-|-|-|
