#ifndef __I2C_AXP192_H__
#define __I2C_AXP192_H__

#include <Wire.h>
#include <Arduino.h>

#define I2C_AXP192_DEFAULT_ADDRESS 0x34

typedef struct {
  bool EXTEN;
  bool BACKUP;
  int DCDC1;
  int DCDC2;
  int DCDC3;
  int LDO2;
  int LDO3;
  int GPIO0;
  int GPIO1;
  int GPIO2;
  int GPIO3;
  int GPIO4;
} I2C_AXP192_InitDef;

class I2C_AXP192 {
  public:
    I2C_AXP192(uint8_t deviceAddress = I2C_AXP192_DEFAULT_ADDRESS, TwoWire &i2cPort = Wire);
    void begin(I2C_AXP192_InitDef initDef);

    void setDCDC1(int voltage);
    void setDCDC2(int voltage);
    void setDCDC3(int voltage);

    void setLDO2(int voltage);
    void setLDO3(int voltage);

    void setGPIO0(int voltage);
    void setGPIO1(int voltage);
    void setGPIO2(int voltage);
    void setGPIO3(int voltage);
    void setGPIO4(int voltage);

    void setEXTEN(bool enable);
    void setBACKUP(bool enable);

  private:
    uint8_t ReadByte(uint8_t Address);
    void WriteByte(uint8_t Address, uint8_t Data);
    void BitOn(uint8_t Address, uint8_t Bit);
    void BitOff(uint8_t Address, uint8_t Bit);

    TwoWire *_i2cPort;
    int _deviceAddress;
};

#endif