#include "I2Cdev.h"
#include "MPU6050.h"
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    #include "Wire.h"
#endif


MPU6050 accelgyro(0x69); // <-- use for AD0 high

int16_t ax, ay, az;
int16_t gx, gy, gz;


void setup() {
    delay(5000);
    Serial.begin(9600);
    // join I2C bus (I2Cdev library doesn't do this automatically)
    #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
        Wire.begin();
    #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
        Fastwire::setup(400, true);
    #endif
    

    // initialize device
    Serial.print("Initializing I2C devices...");
    Wire.beginTransmission(0x69);
    accelgyro.initialize();

    // verify connection
    Serial.write("Testing device connections...");
    Serial.write(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");

}

void loop() {
    // read raw accel/gyro measurements from device
    accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

    // display tab-separated accel/gyro x/y/z values
    Serial.write("\tD");
    Serial.print(ax);Serial.write(":");
    Serial.print(ay);Serial.write(":");
    Serial.print(az);Serial.write(":");
    Serial.print(gx);Serial.write(":");
    Serial.print(gy);Serial.write(":");
    Serial.print(gz);Serial.write("F");

    // blink LED to indicate activity
    delay(500);
}
