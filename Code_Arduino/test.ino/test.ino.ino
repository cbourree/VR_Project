#include "MPU6050.h"
#include <SPI.h>                         // Include the SPI library
#include "Wire.h"

SPISettings MCP3008(2000000, MSBFIRST, SPI_MODE0);
MPU6050 accelgyro(0x69); // <-- use for AD0 high

//int16_t ax, ay, az;
//int16_t gx, gy, gz;

const int  CS_MCP3008       = 4;          // ADC Chip Select

const byte adc_single_ch3 = 0x0B;     // ADC Channel 3
const byte adc_single_ch4 = 0x0C;     // ADC Channel 4
const byte adc_single_ch5 = 0x0D;     // ADC Channel 5
const byte adc_single_ch6 = 0x0E;     // ADC Channel 6
const byte adc_single_ch7 = 0x0F;     // ADC Channel 7

int16_t G_doigts[18];

void setup() {
    for (int i = 0 ; i < 18 ; i++) {
      G_doigts[i] = 0;
    }
    delay(1000);
    Serial.begin(9600);
    SPI.begin();
    Wire.begin();
    
    pinMode       (CS_MCP3008, OUTPUT);
    digitalWrite  (CS_MCP3008, LOW);        // Cycle the ADC CS pin as per datasheet
    digitalWrite  (CS_MCP3008, HIGH);

    Wire.beginTransmission(0x69);
    accelgyro.initialize();

    //Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");
}

void loop() {
  int    adc_reading = 0;

  adc_reading = adc_single_channel_read (adc_single_ch6);
  Serial.write       ("A");
  Serial.print     ((adc_reading * 5.0) / 1024) * 2;
  adc_reading        = adc_single_channel_read (adc_single_ch5);
  Serial.write       (";B");
  Serial.print     ((adc_reading * 5.0) / 1024) * 2;
  
  adc_reading        = adc_single_channel_read (adc_single_ch4);

  Serial.write       (";C");
  Serial.print     ((adc_reading * 5.0) / 1024) * 2;
  
  adc_reading        = adc_single_channel_read (adc_single_ch3);

  Serial.write       (";D");
  Serial.print     ((adc_reading * 5.0) / 1024) * 2;

    for (int i = 0 ; i < 3 ; i++) {
      accelgyro.getMotion6(&(G_doigts[i * 6]), &(G_doigts[(i * 6) + 1]), &(G_doigts[(i * 6) + 2]), &(G_doigts[(i * 6) + 3]), &(G_doigts[(i * 6) + 4]), &(G_doigts[(i * 6) + 5]));
      delay(10);
    }
    
    Serial.write(";AX");
    printDouble((G_doigts[0] + G_doigts[6] + G_doigts[12]) / 3);Serial.write(";AY:");
    printDouble((G_doigts[1] + G_doigts[7] + G_doigts[13]) / 3);Serial.write(";AZ:");
    printDouble((G_doigts[2] + G_doigts[8] + G_doigts[14]) / 3);Serial.write(";GX:");
    printDouble((G_doigts[3] + G_doigts[9] + G_doigts[15]) / 3);Serial.write(";GY:");
    printDouble((G_doigts[4] + G_doigts[10] + G_doigts[16]) / 3);Serial.write(";GZ:");
    printDouble((G_doigts[5] + G_doigts[11] + G_doigts[17]) / 3);Serial.write("F\n");

    // blink LED to indicate activity
    delay(20);
}

int adc_single_channel_read(byte readAddress)
{

  byte dataMSB =    0;
  byte dataLSB =    0;
  
  SPI.beginTransaction (MCP3008);
  digitalWrite         (CS_MCP3008, LOW);
  SPI.transfer         (0x01);
  dataMSB =            SPI.transfer(readAddress << 4) & 0x03;  // Send readAddress and receive MSB data, masked to two bits
  dataLSB =            SPI.transfer(0);                     // Push junk data and get LSB byte return
  digitalWrite         (CS_MCP3008, HIGH);
  SPI.endTransaction   ();

  return               dataMSB << 8 | dataLSB;

}

void printDouble(double val){
   if (long(val) < 0) {
     Serial.print("-");
     val = -val;
    }
    else {
      Serial.print("+");
    }
    
   if (long(val) < 10) {
     Serial.print("0000");
   } else if (long(val) < 100) {
     Serial.print("000");
   } else if (long(val) < 1000) {
     Serial.print("00");
   } else if (long(val) < 10000) {
     Serial.print("0");
   }
   Serial.print(long(val));  //prints the int part
} 
