// ================================================================================
// Author: Dinura Silva
// Project: Robotics workshop
// Description: Control 2 motors using L298N Motor Driver
// ================================================================================

// Set the constants for motor driver pins
const int MOTOR1PIN1 = 2;
const int MOTOR1PIN2 = 3;
const int MOTOR2PIN1 = 4;
const int MOTOR2PIN2 = 5;

void setup() {
  // Begin Serial communication
  Serial.begin(9600);

  // Set modes for motor driver's pins
  pinMode(MOTOR1PIN1, OUTPUT);
  pinMode(MOTOR1PIN2, OUTPUT);
  pinMode(MOTOR2PIN1, OUTPUT);
  pinMode(MOTOR2PIN2, OUTPUT);

  // Default all pins to low (disable all motors)
  digitalWrite(MOTOR1PIN1, LOW);
  digitalWrite(MOTOR1PIN2, LOW);
  digitalWrite(MOTOR2PIN1, LOW);
  digitalWrite(MOTOR2PIN2, LOW);
}

void loop() {
  // Make some movements 
  moveForward();
  delay(5000);
  moveBackward();
  delay(5000);
  turnRight();
  delay(5000);
  turnLeft();
  delay(5000);
}

// Move both wheels forward
void moveForward() {
  digitalWrite(MOTOR1PIN1, LOW);
  digitalWrite(MOTOR1PIN2, LOW);
  digitalWrite(MOTOR2PIN1, LOW);
  digitalWrite(MOTOR2PIN2, LOW);
}

// Move both wheels backward
void moveBackward() {
  digitalWrite(MOTOR1PIN1, LOW);
  digitalWrite(MOTOR1PIN2, HIGH);
  digitalWrite(MOTOR2PIN1, LOW);
  digitalWrite(MOTOR2PIN2, HIGH);
}

// Start rotating clockwise (turning right)
void turnRight() {
  // Left motor forwards, right motor backwards
  digitalWrite(MOTOR1PIN1, HIGH);
  digitalWrite(MOTOR1PIN2, LOW);
  digitalWrite(MOTOR2PIN1, LOW);
  digitalWrite(MOTOR2PIN2, HIGH);
}

// Start rotating counter-clockwise (turning left)
void turnLeft() {
  // Left motor backwards, right motor forwards
  digitalWrite(MOTOR1PIN1, LOW);
  digitalWrite(MOTOR1PIN2, HIGH);
  digitalWrite(MOTOR2PIN1, HIGH);
  digitalWrite(MOTOR2PIN2, LOW);
}

// Stop moving motors
void stopMotors() {
  // Setting both pins LOW will stop a motor
  digitalWrite(MOTOR1PIN1, LOW);
  digitalWrite(MOTOR1PIN2, LOW);

  digitalWrite(MOTOR2PIN1, LOW);
  digitalWrite(MOTOR2PIN2, LOW);
}