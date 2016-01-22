// to the pins used:
const int analogIn0 = A0; 
const int analogIn1 = A1; 
const int analogIn2 = A2; 
const int analogIn3 = A3; 
const int analogIn4 = A4; 

int Value0 = 0;     
int Value1 = 0; 
int Value2 = 0; 
int Value3 = 0; 
int Value4 = 0; 

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {
  // read the analog in value:
  Value0 = analogRead(analogIn0);
  Value1 = analogRead(analogIn1);
  Value2 = analogRead(analogIn2);
  Value3 = analogRead(analogIn3);
  Value4 = analogRead(analogIn4);

  Serial.print("A0 = " );
  Serial.print(Value0);
  Serial.print(" : A1 = " );
  Serial.print(Value1);
  Serial.print(" : A2 = " );
  Serial.print(Value2);
  Serial.print(" : A3 = " );
  Serial.print(Value3);
  Serial.print(" : A4 = " );
  Serial.println(Value4);

  delay(10);
}
