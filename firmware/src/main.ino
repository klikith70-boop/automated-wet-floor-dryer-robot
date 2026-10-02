/**
 * @file main.ino
 * @brief Automated Wet Floor Dryer Robot Firmware
 * @target Arduino Uno R3 / ATmega328P
 */

const int MOTOR_RIGHT_FWD = 4;
const int MOTOR_RIGHT_REV = 5;
const int MOTOR_LEFT_FWD  = 6;
const int MOTOR_LEFT_REV  = 7;
const int AUX_ROLLER_1    = 8;
const int AUX_ROLLER_2    = 9;

const int RELAY_BLOWER_PIN = 2;
const int IR_SENSOR_PIN    = 3;

void moveForward();
void moveBackward();
void turnLeft();
void turnRight();
void stopRobot();

void setup() {
  Serial.begin(9600);

  pinMode(MOTOR_RIGHT_FWD, OUTPUT);
  pinMode(MOTOR_RIGHT_REV, OUTPUT);
  pinMode(MOTOR_LEFT_FWD, OUTPUT);
  pinMode(MOTOR_LEFT_REV, OUTPUT);
  pinMode(AUX_ROLLER_1, OUTPUT);
  pinMode(AUX_ROLLER_2, OUTPUT);

  pinMode(IR_SENSOR_PIN, INPUT);
  pinMode(RELAY_BLOWER_PIN, OUTPUT);

  stopRobot();
  digitalWrite(RELAY_BLOWER_PIN, LOW);
  delay(1000);
}

void loop() {
  int irState = digitalRead(IR_SENSOR_PIN);

  if (irState == LOW) {
    Serial.println("[EVENT] Obstacle detected! Executing avoidance sequence...");

    digitalWrite(RELAY_BLOWER_PIN, LOW);
    stopRobot();
    delay(2000);

    moveBackward();
    delay(2000);

    stopRobot();
    delay(2000);

    turnLeft();
    delay(3000);

    stopRobot();
    delay(2000);

    moveForward();
    delay(2000);

    stopRobot();
    delay(500);
  } else {
    Serial.println("[STATUS] Path clear. Activating blower and progressing...");
    digitalWrite(RELAY_BLOWER_PIN, HIGH);
    moveForward();
    delay(1000);
  }
}

void moveForward() {
  digitalWrite(MOTOR_RIGHT_FWD, HIGH);
  digitalWrite(MOTOR_RIGHT_REV, LOW);
  digitalWrite(MOTOR_LEFT_FWD, HIGH);
  digitalWrite(MOTOR_LEFT_REV, LOW);
  digitalWrite(AUX_ROLLER_1, HIGH);
  digitalWrite(AUX_ROLLER_2, LOW);
}

void moveBackward() {
  digitalWrite(MOTOR_RIGHT_FWD, LOW);
  digitalWrite(MOTOR_RIGHT_REV, HIGH);
  digitalWrite(MOTOR_LEFT_FWD, LOW);
  digitalWrite(MOTOR_LEFT_REV, HIGH);
  digitalWrite(AUX_ROLLER_1, LOW);
  digitalWrite(AUX_ROLLER_2, LOW);
}

void turnLeft() {
  digitalWrite(MOTOR_RIGHT_FWD, HIGH);
  digitalWrite(MOTOR_RIGHT_REV, LOW);
  digitalWrite(MOTOR_LEFT_FWD, LOW);
  digitalWrite(MOTOR_LEFT_REV, HIGH);
  digitalWrite(AUX_ROLLER_1, LOW);
  digitalWrite(AUX_ROLLER_2, LOW);
}

void turnRight() {
  digitalWrite(MOTOR_RIGHT_FWD, LOW);
  digitalWrite(MOTOR_RIGHT_REV, HIGH);
  digitalWrite(MOTOR_LEFT_FWD, HIGH);
  digitalWrite(MOTOR_LEFT_REV, LOW);
  digitalWrite(AUX_ROLLER_1, LOW);
  digitalWrite(AUX_ROLLER_2, LOW);
}

void stopRobot() {
  digitalWrite(MOTOR_RIGHT_FWD, LOW);
  digitalWrite(MOTOR_RIGHT_REV, LOW);
  digitalWrite(MOTOR_LEFT_FWD, LOW);
  digitalWrite(MOTOR_LEFT_REV, LOW);
  digitalWrite(AUX_ROLLER_1, LOW);
  digitalWrite(AUX_ROLLER_2, LOW);
}
