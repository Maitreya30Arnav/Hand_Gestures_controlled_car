#include <SoftwareSerial.h>

// Pin definitions for Bluetooth module
const int bluetoothRx = 10; // RX pin of HC-05 connected to pin 10 of Arduino
const int bluetoothTx = 11; // TX pin of HC-05 connected to pin 11 of Arduino

// Create SoftwareSerial object for Bluetooth communication
SoftwareSerial bluetooth(bluetoothRx, bluetoothTx);

// Pin definitions for motor driver
const int ENA = 9;  // Enable pin for motor A
const int ENB = 10; // Enable pin for motor B
const int IN1 = 2;  // Input 1 for motor A
const int IN2 = 3;  // Input 2 for motor A
const int IN3 = 4;  // Input 3 for motor B
const int IN4 = 5;  // Input 4 for motor B

void setup() {
  // Set the motor driver pins as outputs
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Initialize serial communication for the Bluetooth module
  bluetooth.begin(9600);
  Serial.begin(9600);
}

void loop() {
  // Check if there is any data from the Bluetooth module
  if (bluetooth.available()) {
    char command = bluetooth.read(); // Read the command
    
    // Print received command to Serial Monitor (optional)
    Serial.println(command);
    
    // Execute the command
    switch(command) {
      case 'F': // Move forward
        moveForward();
        break;
      case 'B': // Move backward
        moveBackward();
        break;
      case 'L': // Turn left
        turnLeft();
        break;
      case 'R': // Turn right
        turnRight();
        break;
      default: // Stop the car
        stop();
        break;
    }
  }
}

void moveForward() {
  // Set motor A forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  // Set motor B forward
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  // Set speed (adjust if necessary)
  analogWrite(ENA, 255); // Full speed
  analogWrite(ENB, 255); // Full speed
}

void moveBackward() {
  // Set motor A backward
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  // Set motor B backward
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  // Set speed (adjust if necessary)
  analogWrite(ENA, 255); // Full speed
  analogWrite(ENB, 255); // Full speed
}

void turnLeft() {
  // Set motor A backward
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  // Set motor B forward
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  // Set speed (adjust if necessary)
  analogWrite(ENA, 255); // Full speed
  analogWrite(ENB, 255); // Full speed
}

void turnRight() {
  // Set motor A forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  // Set motor B backward
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  // Set speed (adjust if necessary)
  analogWrite(ENA, 255); // Full speed
  analogWrite(ENB, 255); // Full speed
}

void stop() {
  // Stop both motors
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}
