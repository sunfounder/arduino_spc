#include "Arduino.h"
#include "Wire.h"

class I2C {
  public:
    I2C();
    void begin(uint8_t address);
    uint8_t scanIntoArray(uint8_t *array);
    uint8_t readU8(uint8_t reg);
    int8_t readS8(uint8_t reg);
    uint16_t readU16(uint8_t reg);
    int16_t readS16(uint8_t reg);
    uint8_t readIntoArray(uint8_t reg, uint8_t *array, uint8_t size);

    void writeU8(uint8_t reg, uint8_t data);
  private:
    uint8_t address;
};