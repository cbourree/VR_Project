#include <SPI.h>                         // Include the SPI library

SPISettings MCP3008(2000000, MSBFIRST, SPI_MODE0);

int ValueA0 = 0, ValueA1 = 0, ValueA2 = 0, ValueA3 = 0, ValueA4 = 0;

const int  CS_MCP3008 = 4;     // ADC Chip Select
const byte adc_ch3 = 0x0B;     // ADC Channel 3
const byte adc_ch4 = 0x0C;     // ADC Channel 4
const byte adc_ch5 = 0x0D;     // ADC Channel 5
const byte adc_ch6 = 0x0E;     // ADC Channel 6
const byte adc_ch7 = 0x0F;     // ADC Channel 7



void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  
  //##### INITIALISATION ADC MCP3008 ####
  pinMode       (CS_MCP3008, OUTPUT);
  digitalWrite  (CS_MCP3008, LOW);        // Cycle the ADC CS pin as per datasheet
  digitalWrite  (CS_MCP3008, HIGH);
 
}

void loop() {
  // read the analog in value:
  ValueA0 = CAN(adc_ch3);
  ValueA1 = CAN(adc_ch4);
  ValueA2 = CAN(adc_ch5);
  ValueA3 = CAN(adc_ch6);
  ValueA4 = CAN(adc_ch7);

  Serial.print("A0 = " );
  Serial.print(ValueA0);
  Serial.print(" : A1 = " );
  Serial.print(ValueA1);
  Serial.print(" : A2 = " );
  Serial.print(ValueA2);
  Serial.print(" : A3 = " );
  Serial.print(ValueA3);
  Serial.print(" : A4 = " );
  Serial.println(ValueA4);

  delay(500);
}

//Return ADC ch tension
int CAN(byte readAddress)
{

  byte dataMSB =    0;
  byte dataLSB =    0;
  byte value = 0;
  
  SPI.beginTransaction(MCP3008);
  digitalWrite(CS_MCP3008, LOW);
  SPI.transfer(0x01);                                 // Start Bit
  dataMSB = SPI.transfer(readAddress << 4) & 0x03;    // Send readAddress and receive MSB data, masked to two bits
  dataLSB = SPI.transfer(0x00);                       // Push junk data and get LSB byte return
  digitalWrite(CS_MCP3008, HIGH);
  SPI.endTransaction   ();
  value = (dataMSB << 8) | dataLSB;
  return ((value * 5) / 1024) * 2;
}
