// to the pins used:
const int analogIn0 = A0, analogIn1 = A1, analogIn2 = A2, analogIn3 = A3, analogIn4 = A4;

int ValueA0 = 0, ValueA1 = 0, ValueA2 = 0, ValueA3 = 0, ValueA4 = 0;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {
  // read the analog in value:
  ValueA0 = analogRead(analogIn0);
  ValueA1 = analogRead(analogIn1);
  ValueA2 = analogRead(analogIn2);
  ValueA3 = analogRead(analogIn3);
  ValueA4 = analogRead(analogIn4);

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

  delay(10);
}
