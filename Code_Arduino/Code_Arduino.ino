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
  //##### INITIALISATION liaison série (BT)####
  Serial.begin(9600);
  
  //##### INITIALISATION ADC MCP3008 ####
  pinMode(CS_MCP3008, OUTPUT);
  digitalWrite(CS_MCP3008, LOW);        // Cycle the ADC CS pin as per datasheet
  digitalWrite(CS_MCP3008, HIGH);
  
  //##### INITIALISATION GYRO ####
  #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
     Wire.begin();
  #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
     Fastwire::setup(400, true);
  #endif

  // initialize device
  Serial.write("Initializing I2C devices...");
  Wire.beginTransmission(0x69);
  accelgyro.initialize();

  // verify connection
  Serial.write("Testing device connections...");
  Serial.write(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");
 
}

void loop() {
  //##### TRAITEMENT CMD BT ####
  while(Serial.available())
  {//while there is data available on the serial monitor
    BTMessage += char(Serial.read());//store string from serial command
  }
  if(!Serial.available())
  {
    if(BTMessage != "")
    {//if data is available
      Serial.write("Commande BT recue");
      Serial.write(BTMessage); //show the data
      BTMessage = ""; //clear the data
    }
  }
  
  //##### TRAITEMENT DES DOIGTS ####
  // read the analog in value:
  ValueA0 = CAN(adc_ch3);
  ValueA1 = CAN(adc_ch4);
  ValueA2 = CAN(adc_ch5);
  ValueA3 = CAN(adc_ch6);
  ValueA4 = CAN(adc_ch7);

  Serial.write("A0 = ");
  Serial.write(ValueA0);
  Serial.write(" : A1 = ");
  Serial.write(ValueA1);
  Serial.write(" : A2 = ");
  Serial.write(ValueA2);
  Serial.write(" : A3 = ");
  Serial.write(ValueA3);
  Serial.write(" : A4 = ");
  Serial.write(ValueA4);
  
  //##### TRAITEMENT GYRO ###
  accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  // display tab-separated accel/gyro x/y/z values
  Serial.write("a/g:\t");
  Serial.write(ax); Serial.write("\t");
  Serial.write(ay); Serial.write("\t");
  Serial.write(az); Serial.write("\t");
  Serial.write(gx); Serial.write("\t");
  Serial.write(gy); Serial.write("\t");
  Serial.write(gz);

  delay(500);
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
