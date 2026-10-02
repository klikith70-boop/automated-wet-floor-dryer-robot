int motor1 = 4;
int motor2 = 5;
int motor3 = 6;
int motor4 = 7;
int motor5 = 8;
int motor6 = 9;
int relay  = 2;
int ir     = 3;

void forward_movement();
void back_movement();
void left_movement();
void right_movement();
void stop_robot();

void setup() {
  Serial.begin(9600);
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(motor3, OUTPUT);
  pinMode(motor4, OUTPUT);
  pinMode(motor5, OUTPUT);
  pinMode(motor6, OUTPUT);
  pinMode(ir, INPUT);
  pinMode(relay, OUTPUT);

  stop_robot();
  digitalWrite(relay, LOW);
  delay(1000);
}

void loop() {
  int irValue = digitalRead(ir);

  if (irValue == LOW) {
    Serial.println("Obstacle detected!");
    digitalWrite(relay, LOW);
    stop_robot();
    delay(2000);
    back_movement();
    delay(2000);
    stop_robot();
    delay(2000);
    left_movement();
    delay(3000);
    stop_robot();
    delay(2000);
    forward_movement();
    delay(2000);
    stop_robot();
    delay(500);
  } else {
    Serial.println("Path clear, moving forward...");
    digitalWrite(relay, HIGH);
    forward_movement();
    delay(1000);
  }
}

void forward_movement() {
  digitalWrite(motor1, HIGH);
  digitalWrite(motor2, LOW);
  digitalWrite(motor3, HIGH);
  digitalWrite(motor4, LOW);
  digitalWrite(motor5, HIGH);
  digitalWrite(motor6, LOW);
}

void back_movement() {
  digitalWrite(motor1, LOW);
  digitalWrite(motor2, HIGH);
  digitalWrite(motor3, LOW);
  digitalWrite(motor4, HIGH);
  digitalWrite(motor5, LOW);
  digitalWrite(motor6, LOW);
}

void left_movement() {
  digitalWrite(motor1, HIGH);
  digitalWrite(motor2, LOW);
  digitalWrite(motor3, LOW);
  digitalWrite(motor4, HIGH);
  digitalWrite(motor5, LOW);
  digitalWrite(motor6, LOW);
}

void right_movement() {
  digitalWrite(motor1, LOW);
  digitalWrite(motor2, HIGH);
  digitalWrite(motor3, HIGH);
  digitalWrite(motor4, LOW);
  digitalWrite(motor5, LOW);
  digitalWrite(motor6, LOW);
}

void stop_robot() {
  digitalWrite(motor1, LOW);
  digitalWrite(motor2, LOW);
  digitalWrite(motor3, LOW);
  digitalWrite(motor4, LOW);
  digitalWrite(motor5, LOW);
  digitalWrite(motor6, LOW);
}
