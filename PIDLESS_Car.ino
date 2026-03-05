const int motorPin1A = 5;   // IN1 
const int motorPin1B = 6;   // IN2 
const int motorPin2A = 7;   // IN3 
const int motorPin2B = 8;   // IN4 
// ENA and ENB connected to GND

const int irLeft = 3;       // Left IR sensor
const int irRight = 4;      // Right IR sensor
const int irStraight = 51; //Centre IR Sensor

int motorSpeedL = 130;
int motorSpeedR = 143;


void setup() {
  pinMode(motorPin1A, OUTPUT);
  pinMode(motorPin1B, OUTPUT);
  pinMode(motorPin2A, OUTPUT);
  pinMode(motorPin2B, OUTPUT);

  pinMode(irLeft, INPUT);
  pinMode(irRight, INPUT);
  pinMode(irStraight, INPUT);
}

void loop() {
  int left = digitalRead(irLeft);
  int right = digitalRead(irRight);
  int straight = digitalRead(irStraight);
  if(straight == 1)
  {
	  moveForward();
  }
  else if(straight == 0)
  {
	  if(left == 0 && right == 1)
	  {
      stopMotors();
		  turnRight();
	  }
	  else if(left == 1 && right == 0)
	  {
      stopMotors();
		  turnLeft();
	  }
	  else if(left == 0 && right == 0)
	  {
      stopMotors();
      delay(750);
      reverse();
      delay(750);
      stopMotors();
      delay(750);
    }
    else
    {
      moveForward();
    }
  }
  else
  {
	  reverse();
  }

  delay(50);
}


void moveForward() {
  analogWrite(motorPin1A, motorSpeedL);
  analogWrite(motorPin1B, 0);
  analogWrite(motorPin2A, motorSpeedR);
  analogWrite(motorPin2B, 0);  
}

void turnLeft() {
  analogWrite(motorPin1A, 0);
  analogWrite(motorPin1B, motorSpeedL + 5);
  analogWrite(motorPin2A, motorSpeedR - 5);
  analogWrite(motorPin2B, 0);
}

void turnRight() {
  analogWrite(motorPin1A, motorSpeedL - 5);
  analogWrite(motorPin1B, 0);
  analogWrite(motorPin2A, 0);
  analogWrite(motorPin2B, motorSpeedR + 5); 
}

void stopMotors() {
  analogWrite(motorPin1A, 0);
  analogWrite(motorPin1B, 0);
  analogWrite(motorPin2A, 0);
  analogWrite(motorPin2B, 0);
}

void reverse()
{
  analogWrite(motorPin1A, 0);
  analogWrite(motorPin1B, motorSpeedL);
  analogWrite(motorPin2A, 0);
  analogWrite(motorPin2B, motorSpeedR);
}
