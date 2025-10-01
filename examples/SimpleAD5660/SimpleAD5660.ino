#include <SPI.h>
#include "AD5660.h"

// Example: use SPI1 on custom pins (Pico pinout shown)
constexpr uint8_t PIN_CS   = 5;   // any free GPIO for CS
constexpr uint8_t PIN_SCK  = 10;  // SPI1 SCK
constexpr uint8_t PIN_MOSI = 11;  // SPI1 TX
constexpr uint8_t PIN_MISO = 12;  // SPI1 RX (not needed by the DAC, but set anyway)

AD5660 dac(PIN_CS, &SPI1);

void setup() {
  SPI1.setSCK(PIN_SCK);
  SPI1.setTX(PIN_MOSI);
  SPI1.setRX(PIN_MISO);
  SPI1.begin();               // must match the bus you pass to AD5660

  // If using default SPI (SPI0), you could instead call:
  // SPI.begin();
  // and construct as: AD5660 dac(5);  // defaults to &SPI
}

void loop() {
  dac.Set(0x7FFF);
  delay(10);
}