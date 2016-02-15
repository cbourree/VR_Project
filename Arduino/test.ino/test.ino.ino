
#include <I2Cdev.h>

#include "MPU6050.h"
#include <SPI.h>                         // Include the SPI library
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    #include "Wire.h"
#endif

SPISettings MCP3008(2000000, MSBFIRST, SPI_MODE0);
MPU6050 accelgyro(0x69); // <-- use for AD0 high

int16_t ax, ay, az;
int16_t gx, gy, gz;

const int  CS_MCP3008       = 4;          // ADC Chip Select

const byte adc_single_ch3   = (0x0B);     // ADC Channel 3
const byte adc_single_ch4   = (0x0C);     // ADC Channel 4
const byte adc_single_ch5   = (0x0D);     // ADC Channel 5
const byte adc_single_ch6   = (0x0E);     // ADC Channel 6
const byte adc_single_ch7   = (0x0F);     // ADC Channel 7

String msg = "";

void setup() {
    delay(2000);
    Serial.begin(9600);
    SPI.begin();
    
    pinMode       (CS_MCP3008, OUTPUT);
    digitalWrite  (CS_MCP3008, LOW);        // Cycle the ADC CS pin as per datasheet
    digitalWrite  (CS_MCP3008, HIGH);
    
    // join I2C bus (I2Cdev library doesn't do this automatically)
    #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
        Wire.begin();
    #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
        Fastwire::setup(400, true);
    #endif

    Wire.beginTransmission(0x69);
    accelgyro.initialize();

    //Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");

}

void loop() {
  int    adc_reading = 0;
  msg = "";
  adc_reading = adc_single_channel_read (adc_single_ch6);
  msg += "A";
  msg += String((adc_reading * 5.0) / 1024);
  adc_reading        = adc_single_channel_read (adc_single_ch5);
  msg += ";B";
  msg += String((adc_reading * 5.0) / 1024);
  
  adc_reading        = adc_single_channel_read (adc_single_ch4);

  msg += ";C";
  msg += String((adc_reading * 5.0) / 1024);
  
  adc_reading        = adc_single_channel_read (adc_single_ch3);

  msg += ";D";
  msg += String((adc_reading * 5.0) / 1024);

  // read raw accel/gyro measurements from device
    accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
    msg += ";AX";
<<<<<<< HEAD
    printDouble(ax);msg += ";AY:";
    printDouble(ay);msg += ";AZ:";
    printDouble(az);msg += ";GX:";
    printDouble(gx);msg += ";GY:";
    printDouble(gy);msg += ";GZ:";
    printDouble(gz);msg += "F";

    // blink LED to indicate activity
    Serial.println(msg);
    delay(40);
=======
    printDouble((G_doigts[0] + G_doigts[6] + G_doigts[12]) / 3);msg += ";AY:";
    printDouble((G_doigts[1] + G_doigts[7] + G_doigts[13]) / 3);msg += ";AZ:";
    printDouble((G_doigts[2] + G_doigts[8] + G_doigts[14]) / 3);msg += ";GX:";
    printDouble((G_doigts[3] + G_doigts[9] + G_doigts[15]) / 3);msg += ";GY:";
    printDouble((G_doigts[4] + G_doigts[10] + G_doigts[16]) / 3);msg += ";GZ:";
    printDouble((G_doigts[5] + G_doigts[11] + G_doigts[17]) / 3);msg += "F\n";

    Serial.println(msg);
    delay(20);
>>>>>>> 0e074f8a5e823008eb6104e7e34f2ad6800bb7fc
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
     msg += "-";
     val = -val;
    }
    else {
      msg += "+";
    }
    
   if (long(val) < 10) {
     msg += "0000";
   } else if (long(val) < 100) {
     msg += "000";
   } else if (long(val) < 1000) {
     msg += "00";
   } else if (long(val) < 10000) {
     msg += "0";
   }
   msg += String(long(val));  //prints the int part
} 
