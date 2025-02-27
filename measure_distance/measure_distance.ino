// ================================================================================
// Author: Dinura Silva
// Project: Robotics workshop
// Description: Detect distance using HC SR-04 Ultrasonic Distance
//              Sensor and report it back via Serial comms. 
// ================================================================================

// Set the constants for trigger and echo pin numbers
const int TRIGPIN = 6;
const int ECHOPIN = 7;

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
  // Get duration of sensor echo pulse
  unsigned long duration = getDuration();

  // duration > 36000 means no object detected
  if (duration > 36000) {
    Serial.println("No object detected.");
  } else {
    // Calculate distance to object
    float distance = getDistanceCM(duration);
    // Print distance to Serial
    Serial.print("Distance: ");
    Serial.print(distanceCM);
    Serial.println(" cm");
  }
}

// Poll sensor and get echo duration
unsigned long getDuration() {
  // Pulse trigger HIGH for 10 microseconds
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);

  // Measure duration of HIGH pulse on echo
  unsigned long duration = pulseIn(echo, HIGH);

  // 10 millisecond delay betweek echo and trigger
  delay(10);

  return duration;
}

// Convert sensor echo duration to distance (cm)
float getDistanceCM(unsigned long duration) {
  // Divide by 58 (source: datasheet)
  return (float) duration / 58;
}
