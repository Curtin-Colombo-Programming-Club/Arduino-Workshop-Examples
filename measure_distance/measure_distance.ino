// ================================================================================
// Author: Dinura Silva
// Project: Robotics workshop
// Description: Detect distance using HC SR-04 Ultrasonic Distance
//              Sensor and report it back via Serial comms. 
// ================================================================================

// Set the constants for trigger and echo pin numbers
const int TRIGPIN = 6;
const int ECHOPIN = 7;

// Global variables for program
unsigned long duration;
float distanceCM;

void setup() {
  // Begin Serial communication
  Serial.begin(9600);

  // Set modes for ultrasonic sensor's trigger and echo pins
  pinMode(TRIGPIN, OUTPUT);
  pinMode(ECHOPIN, INPUT);

  // Set trigger to LOW
  digitalWrite(TRIGPIN, LOW);
}

void loop() {
  // Pulse trigger HIGH for 10 microseconds
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);

  // Measure duration of HIGH pulse on echo
  duration = pulseIn(echo, HIGH)

  // duration > 36000 means no object detected
  if (duration > 36000) {
    Serial.println("No object detected.")
  } else {
    // Calculate distance in cm (divide by 58)
    distanceCM = duration / 58;
    // Print distance to Serial
    Serial.print("Distance: ");
    Serial.print(distanceCM);
    Serial.println(" cm");
  }
}
