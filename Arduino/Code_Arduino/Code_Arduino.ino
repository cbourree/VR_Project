#include <SPI.h>                         // Include the SPI library
#include "I2Cdev.h"
#include "MPU6050.h"
// Arduino Wire library is required if I2Cdev I2CDEV_ARDUINO_WIRE implementation
// is used in I2Cdev.h
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    #include "Wire.h"
#endif


SPISettings MCP3008(2000000, MSBFIRST, SPI_MODE0);
MPU6050 accelgyro(0x69); // <-- MPU I2C adress

int16_t ax, ay, az;
int16_t gx, gy, gz;


int ValueA0 = 0, ValueA1 = 0, ValueA2 = 0, ValueA3 = 0, ValueA4 = 0;

const int  CS_MCP3008 = 4;     // ADC Chip Select
const byte adc_ch3 = 0x0B;     // ADC Channel 3
const byte adc_ch4 = 0x0C;     // ADC Channel 4
const byte adc_ch5 = 0x0D;     // ADC Channel 5
const byte adc_ch6 = 0x0E;     // ADC Channel 6
const byte adc_ch7 = 0x0F;     // ADC Channel 7

String BTMessage;

void setup() {
  delay(7000);

}

void loop() {
  //##### TRAITEMENT CMD BT ####

}

//Return ADC ch tension
int CAN(byte readAddress)
{

  byte dataMSB = 0;
  byte dataLSB = 0;
  byte value = 0;
  
  SPI.beginTransaction(MCP3008);
  digitalWrite(CS_MCP3008, LOW);
  SPI.transfer(0x01);                                 // Start Bit
  dataMSB = SPI.transfer(readAddress << 4) & 0x03;    // Send readAddress and receive MSB data, masked to two bits
  dataLSB = SPI.transfer(0x00);                       // Push junk data and get LSB byte return
  digitalWrite(CS_MCP3008, HIGH);
  SPI.endTransaction   ();
  value = (dataMSB << 8) | dataLSB;
  return (((value * 5) / 1024) * 2);
}
