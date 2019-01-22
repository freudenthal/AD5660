#include "AD5660.h"

AD5660::AD5660(byte CSSelectPin)
{
	SelectPin = CSSelectPin;
	PowerMode = PowerDownMode::Normal;
	pinMode(CSSelectPin, OUTPUT);
	digitalWrite(CSSelectPin, HIGH);
	ConnectionSettings = SPISettings(1000000, MSBFIRST, SPI_MODE2);
}

void AD5660::Set(uint16_t Setting)
{
	SPI.beginTransaction(ConnectionSettings);
	SPI.transfer( 0 );
	digitalWrite(SelectPin,LOW);
	SPI.transfer( static_cast<uint8_t>(PowerMode) );
	SPI.transfer( (uint8_t)(Setting>>8) );
	SPI.transfer( (uint8_t)(Setting & 0xFF) );
	SPI.endTransaction();
	digitalWrite(SelectPin, HIGH);
}

void AD5660::SetPowerDown(PowerDownMode Mode)
{
	PowerMode = Mode;
}

SPISettings* AD5660::GetSPISettings()
{
	return &ConnectionSettings;
}