#include "AD5660.h"

AD5660::AD5660(byte CSSelectPin, SPIClass* spi)
    : _spi(spi),
      ConnectionSettings(1000000, MSBFIRST, SPI_MODE2),
      PowerMode(PowerDownMode::Normal),
      SelectPin(CSSelectPin)
{
    pinMode(SelectPin, OUTPUT);
    digitalWrite(SelectPin, HIGH);
}

void AD5660::Set(uint16_t Setting)
{
    _spi->beginTransaction(ConnectionSettings);
    digitalWrite(SelectPin, LOW);

    // Frame: [CMD/PD bits][MSB][LSB]
    _spi->transfer(static_cast<uint8_t>(PowerMode));
    _spi->transfer(static_cast<uint8_t>(Setting >> 8));
    _spi->transfer(static_cast<uint8_t>(Setting & 0xFF));

    digitalWrite(SelectPin, HIGH);
    _spi->endTransaction();
}

void AD5660::SetPowerDown(PowerDownMode Mode)
{
    PowerMode = Mode;
}

SPISettings* AD5660::GetSPISettings()
{
    return &ConnectionSettings;
}