#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_LIS3DH.h>
#include <SoftwareSerial.h>

// Bluetooth module pins
const int bluetoothRx = 10;
const int bluetoothTx = 11;

// Create SoftwareSerial object for Bluetooth communication
SoftwareSerial bluetooth(bluetoothRx, bluetoothTx);

// Create an LIS3DH object
Adafruit_LIS3DH lis = Adafruit_LIS3DH();

// Thresholds for determining movement directions
const float forwardThreshold = 1.5;
const float backwardThreshold = -1.5;
const float leftThreshold = -1.5;
const float rightThreshold = 1.5;

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);
  // Initialize Bluetooth communication
  bluetooth.begin(9600);

  // Initialize the LIS3DH sensor
  if (!lis.begin(0x18)) {   // change this to 0x19 for alternative i2c address
    Serial.println("Could not start LIS3DH.");
    while (1);
  }
  
  // Set the range to 2G (you can set it to 4G, 8G, 16G for more sensitivity)
  lis.setRange(LIS3DH_RANGE_2_G);
  
  Serial.println("LIS3DH found!");
}

void loop() {
  // Read accelerometer data
  lis.read();
  sensors_event_t event;
  lis.getEvent(&event);

  // Print accelerometer values for debugging
  Serial.print("X: "); Serial.print(event.acceleration.x); 
  Serial.print(" Y: "); Serial.print(event.acceleration.y);
  Serial.print(" Z: "); Serial.println(event.acceleration.z);

  // Determine direction based on thresholds
  if (event.acceleration.y > forwardThreshold) {
    bluetooth.write('F');
    Serial.println("Forward");
  } else if (event.acceleration.y < backwardThreshold) {
    bluetooth.write('B');
    Serial.println("Backward");
  } else if (event.acceleration.x < leftThreshold) {
    bluetooth.write('L');
    Serial.println("Left");
  } else if (event.acceleration.x > rightThreshold) {
    bluetooth.write('R');
    Serial.println("Right");
  } else {
    bluetooth.write('S'); // Send 'S' to stop
    Serial.println("Stop");
  }

  // Delay to avoid sending too many commands in a short time
  delay(200);
}
