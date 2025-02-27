// ================================================================================
// Author: Dinura Silva
// Project: Robotics workshop
// Description: Turn right on proximity to an object
// ================================================================================

// Set the constants for trigger and echo pin numbers
const int TRIGPIN = 6;
const int ECHOPIN = 7;

// Set the constants for motor driver pins
const int MOTOR1PIN1 = 2;
const int MOTOR1PIN2 = 3;
const int MOTOR2PIN1 = 4;
const int MOTOR2PIN2 = 5;

void setup() {
  // Begin serial communication
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

  // Set modes for ultrasonic sensor's trigger and echo pins
  pinMode(TRIGPIN, OUTPUT);
  pinMode(ECHOPIN, INPUT);

  // Set trigger to LOW
  digitalWrite(TRIGPIN, LOW);
}

void loop() {
  // Poll distance from sensor
  float distance = getDistanceCM(getDuration());

  if (distance > 25) {
    moveForward();
  } else {
    turnRight();
    delay(250);
    stopMotors();
  }
}

// Move both wheels forward
void moveForward() {
  digitalWrite(MOTOR1PIN1, HIGH);
  digitalWrite(MOTOR1PIN2, LOW);
  digitalWrite(MOTOR2PIN1, HIGH);
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
  digitalWrite(MOTOR1PIN1, LOW);
  digitalWrite(MOTOR1PIN2, HIGH);
  digitalWrite(MOTOR2PIN1, HIGH);
  digitalWrite(MOTOR2PIN2, LOW);
}

// Start rotating counter-clockwise (turning left)
void turnLeft() {
  // Left motor backwards, right motor forwards
  digitalWrite(MOTOR1PIN1, HIGH);
  digitalWrite(MOTOR1PIN2, LOW);
  digitalWrite(MOTOR2PIN1, LOW);
  digitalWrite(MOTOR2PIN2, HIGH);
}
// Stop moving motors
void stopMotors() {
  // Setting both pins LOW will stop a motor
  digitalWrite(MOTOR1PIN1, LOW);
  digitalWrite(MOTOR1PIN2, LOW);

  digitalWrite(MOTOR2PIN1, LOW);
  digitalWrite(MOTOR2PIN2, LOW);
}

// Poll sensor and get echo duration
unsigned long getDuration() {
  // Pulse trigger HIGH for 10 microseconds
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);

  // Measure duration of HIGH pulse on echo
  unsigned long duration = pulseIn(ECHOPIN, HIGH);

  // 10 millisecond delay betweek echo and trigger
  delay(10);

  return duration;
}

// Convert sensor echo duration to distance (cm)
float getDistanceCM(unsigned long duration) {
  // Divide by 58 (source: datasheet)
  return (float) duration / 58;
}
