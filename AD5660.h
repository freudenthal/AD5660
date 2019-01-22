#ifndef __ARDUINO_AD5660X
#define __ARDUINO_AD5660X

#include <Arduino.h>
#include <SPI.h>

class AD5660
{
	public:
		enum class PowerDownMode
		{
			Normal = 0,
			k1ToGND = 1,
			k100ToGND = 2,
			TriState = 3,
			Count = 4,
		};
		AD5660(byte CSSelectPin);
		void Set(uint16_t Setting);
		void SetPowerDown(PowerDownMode Mode);
		SPISettings* GetSPISettings();
	private:
		SPISettings ConnectionSettings;
		PowerDownMode PowerMode;
		byte SelectPin;
};
#endif