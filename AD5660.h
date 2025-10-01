#ifndef __ARDUINO_AD5660X
#define __ARDUINO_AD5660X

#include <Arduino.h>
#include <SPI.h>

class AD5660 {
public:
    enum class PowerDownMode {
        Normal    = 0,
        k1ToGND   = 1,
        k100ToGND = 2,
        TriState  = 3,
        Count     = 4,
    };

    // New: optionally pass which SPI bus to use (defaults to the global SPI)
    AD5660(byte CSSelectPin, SPIClass* spi = &SPI);

    void Set(uint16_t Setting);
    void SetPowerDown(PowerDownMode Mode);

    // Keep your existing accessor
    SPISettings* GetSPISettings();

private:
    SPIClass*     _spi;               // pointer to the SPI interface to use
    SPISettings   ConnectionSettings;
    PowerDownMode PowerMode;
    byte          SelectPin;
};

#endif