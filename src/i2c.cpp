#include "i2c.h"

I2C::I2C() {}

void I2C::begin(uint8_t address)
{
    this->address = address;
}

// scan for devices on the I2C bus
uint8_t I2C::scanIntoArray(uint8_t *array)
{
    uint8_t count = 0;
    Wire.setWireTimeout(5000 /* us */, false /* reset_on_timeout */);

    Serial.println(F("scaning device ..."));
    for (uint8_t i = 0; i < 128; i++)
    {
        Wire.beginTransmission(i);
        if (Wire.endTransmission() == 0)
        {
            array[count] = i;
            count++;
        }
    }
    return count;
}

uint8_t I2C::readU8(uint8_t reg)
{
    Wire.beginTransmission(this->address);
    Wire.write(reg);
    Wire.endTransmission();
    Wire.requestFrom(this->address, (uint8_t)1);
    uint8_t data = Wire.read();
    return data;
}

int8_t I2C::readS8(uint8_t reg)
{
    Serial.print(F("this->address"));
    Serial.println(this->address);
    Wire.beginTransmission(this->address);
    Wire.write(reg);
    Wire.endTransmission();
    Wire.requestFrom(this->address, (uint8_t)1);
    uint8_t data = Wire.read();
    int8_t signedData = (int8_t)data;
    return signedData;
}

uint16_t I2C::readU16(uint8_t reg)
{
    Wire.beginTransmission(this->address);
    Wire.write(reg);
    Wire.endTransmission();
    Wire.requestFrom(this->address, (uint8_t)2);
    uint8_t dataL = Wire.read();
    uint8_t dataH = Wire.read();
    return (dataH << 8) | dataL;
}

int16_t I2C::readS16(uint8_t reg)
{
    Wire.beginTransmission(this->address);
    Wire.write(reg);
    Wire.endTransmission();
    Wire.requestFrom(this->address, (uint8_t)2);
    uint8_t dataL = Wire.read();
    uint8_t dataH = Wire.read();
    return (int16_t)((dataH << 8) | dataL);
}

uint8_t I2C::readIntoArray(uint8_t reg, uint8_t *array, uint8_t size)
{
    Wire.beginTransmission(this->address);
    Wire.write(reg);
    Wire.endTransmission();
    Wire.requestFrom(this->address, (uint8_t)size);
    uint8_t count = 0;
    while (Wire.available())
    {
        array[count] = Wire.read();
        count++;
    }
    return count;
}

void I2C::writeU8(uint8_t reg, uint8_t data)
{
    Wire.beginTransmission(this->address);
    Wire.write(reg);
    Wire.write(data);
    Wire.endTransmission();
}
