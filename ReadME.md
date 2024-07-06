1. Car Control Code (car_control.ino)
This code is uploaded to the Arduino on the car. It receives commands via Bluetooth and controls the car's motors using an L298 motor driver.
Components:
•	Arduino (e.g., Uno, Nano)
•	HC-05 Bluetooth module
•	L298 Motor Driver
•	Motors and wheels
Connections:
•	HC-05 Bluetooth Module:
o	RX: Arduino pin 10
o	TX: Arduino pin 11
•	L298 Motor Driver:
o	ENA: Arduino pin 9
o	ENB: Arduino pin 10
o	IN1: Arduino pin 2
o	IN2: Arduino pin 3
o	IN3: Arduino pin 4
o	IN4: Arduino pin 5
Code Overview:
•	The code initializes the motor driver pins as outputs.
•	It sets up Bluetooth communication using the SoftwareSerial library.
•	In the loop, it reads commands from the Bluetooth module and controls the motors accordingly to move forward, backward, turn left, turn right, or stop.
________________________________________
2. Hand Gesture Controller Code (hand_gesture_controller.ino)
This code is uploaded to the Arduino that reads the accelerometer data and sends control signals to the car via Bluetooth.
Components:
•	Arduino (e.g., Uno, Nano)
•	HC-05 Bluetooth module
•	LIS3DH accelerometer
Connections:
•	HC-05 Bluetooth Module:
o	RX: Arduino pin 10
o	TX: Arduino pin 11
•	LIS3DH Accelerometer:
o	SCL: Arduino SCL
o	SDA: Arduino SDA
o	VCC: 3.3V
o	GND: GND
Code Overview:
•	The code initializes the LIS3DH accelerometer and sets its range to 2G.
•	It sets up Bluetooth communication using the SoftwareSerial library.
•	In the loop, it reads the accelerometer data and determines the direction based on defined thresholds.
•	It sends corresponding commands ('F', 'B', 'L', 'R') to the car via Bluetooth based on the accelerometer readings.
________________________________________
Instructions:
1.	Set Up the Car:
o	Connect the HC-05 Bluetooth module and L298 motor driver to your Arduino as per the connections given.
o	Upload the car_control.ino code to the Arduino.
2.	Set Up the Hand Gesture Controller:
o	Connect the HC-05 Bluetooth module and LIS3DH accelerometer to your Arduino as per the connections given.
o	Upload the hand_gesture_controller.ino code to the Arduino.
3.	Pair Bluetooth Modules:
o	Pair the HC-05 Bluetooth module connected to the car with the HC-05 Bluetooth module connected to the hand gesture controller.
4.	Control the Car:
o	Use hand gestures to control the car. The accelerometer data will determine the commands sent to the car, allowing you to control it by tilting your hand in different directions.
Notes:
•	Ensure both Bluetooth modules are correctly paired.
•	Adjust the threshold values in the hand gesture controller code if necessary for better sensitivity.
•	Use the Serial Monitor to debug and verify the commands being sent.
Files:
•	car_control.ino: Code for the car that receives commands and controls the motors.
•	hand_gesture_controller.ino: Code for the controller that reads accelerometer data and sends commands via Bluetooth.

