# I2C AXP192 Power Management Library

This is a library of AXP192, the Power Management for I2C connectivity.

## Support Devices

- [M5Stack M5Stick](https://docs.m5stack.com/#/en/core/m5stickc)
- [M5Stack M5Stick Plus](https://docs.m5stack.com/#/en/core/m5stickc_plus)

## On-board devices

- [LilyGO-T-Beam](https://github.com/Xinyuan-LilyGO/LilyGO-T-Beam)
- [LilyGO T-PCIE](https://github.com/Xinyuan-LilyGO/LilyGo-T-PCIE)

## Usage
```c
#include "I2C_AXP192.h";

I2C_AXP192 axp192(I2C_AXP192_DEFAULT_ADDRESS, Wire1);

void setup() {
  Serial.begin(115200);
  delay(1000);

  Wire1.begin(21, 22);

  I2C_AXP192_InitDef initDef = {
    .EXTEN  = true,
    .BACKUP = true,
    .DCDC1  = 3300,
    .DCDC2  = 0,
    .DCDC3  = 0,
    .LDO2   = 3000,
    .LDO3   = 3000,
    .GPIO0  = 2800,
    .GPIO1  = -1,
    .GPIO2  = -1,
    .GPIO3  = -1,
    .GPIO4  = -1,
  };
  axp192.begin(initDef);
}

void loop() {
}
```
