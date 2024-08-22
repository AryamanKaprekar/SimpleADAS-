// Pin definitions

const int motorPin1 = 4;
const int motorPin2 = 5;

void setup() {
  // Set motor pins as output
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);

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
