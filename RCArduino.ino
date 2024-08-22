// Pin definitions

const int motorPin1 = 4;
const int motorPin2 = 5;
const int irSensor1 = 2;
const int irSensor2 = 3;

// Variables to store sensor values
int irValue1 = 0;
int irValue2 = 0;

void setup() {
  // Set motor pins as output
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);

  // Set IR sensor pins as input
  pinMode(irSensor1, INPUT);
  pinMode(irSensor2, INPUT);

  // Initialize serial communication
  Serial.begin(9600);

  // Test motor pins
  Serial.println("Testing motors...");
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, HIGH);
  delay(2000); // Run motors for 2 seconds
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  Serial.println("Motor test complete.");
}

void loop() {
  // Read values from IR sensors
  irValue1 = digitalRead(irSensor1);
  irValue2 = digitalRead(irSensor2);

  // Print sensor values to serial monitor for debugging
  Serial.print("IR Sensor 1: ");
  Serial.print(irValue1);
  Serial.print("  IR Sensor 2: ");
  Serial.println(irValue2);
  // Check if any sensor detects an obstacle
  if (Serial.available() > 0) {
    char command = Serial.read();
    controlCar(command);
  }
  // Small delay to avoid rapid changes
  delay(1000);
}
void controlCar(char command) {
  switch (command) {
    case 'F': // Forward
      moveForward();
      break;
    case 'L': // Left
      moveLeft();
      break;
    case 'R': // Right
      moveRight();
      break;
    case 'S': // Stop
      stopCar();
      break;
  }
}

void moveLeft() {
  Serial.println("Moving left...");
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
}

void moveRight() {
  Serial.println("Moving right...");
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
}

void moveForward() {
  Serial.println("Moving forward...");
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, HIGH);
}

void stopCar() {
  Serial.println("Stopping car...");
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
}