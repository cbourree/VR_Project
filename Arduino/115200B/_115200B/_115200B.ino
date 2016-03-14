

void setup() {
    Serial.begin(9600);
    Serial.write("AT+BAUD8");
}

void loop() {
    Serial.begin(115200);
    while(Serial.available()){
      Serial.println(Serial.read());
    }
    Serial.println("Test");
    delay(40);
}




