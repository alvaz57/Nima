#include <SoftwareSerial.h>
#include <Servo.h>

int num = 0;

int state = 0;//What the bluetooth reads
int motor1B = 5;// motor 1 moving backward
int motor1F = 6;// motor 1 moving forward
int motor2B = 9;//motor 2 moving backward
int motor2F = 10;//motor 2 moving forward

//led's inside the robot for a cool factor
int led1 = 7;
int led2 = 8;

//movable arm
Servo myServo;

//the robot does not move
void parked(){
 digitalWrite(motor1F, LOW);
 digitalWrite(motor2F, LOW);
 digitalWrite(motor1B, LOW);
 digitalWrite(motor2B, LOW);
}

//move forward
void forward(){
  digitalWrite(motor1F, HIGH);
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2F, HIGH);
  digitalWrite(motor2B, LOW);
}

//move backward
void backward(){
  digitalWrite(motor1F, LOW);
  digitalWrite(motor1B, HIGH);
  digitalWrite(motor2F, LOW);
  digitalWrite(motor2B, HIGH);
}

//turn to the left
void turnLeft(){
  digitalWrite(motor1F, HIGH);
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2F, LOW);
  digitalWrite(motor2B, HIGH);
}

//turn to the right
void turnRight(){
  digitalWrite(motor1F, LOW);
  digitalWrite(motor1B, HIGH);
  digitalWrite(motor2F, HIGH);
  digitalWrite(motor2B, LOW);
}

void setup(){ 
  //Set up 4 pins as output on the arduino to run the stepper motor
  pinMode(motor1F, OUTPUT);
  pinMode(motor2F, OUTPUT);
  pinMode(motor1B, OUTPUT);
  pinMode(motor2B, OUTPUT);

  //attach servo to pwm 11
  myServo.attach(11);

  //set led's as output to turn them on
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  //turn on LED's
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);

  //initialize serial monitor for bluetooth communication
  Serial.begin(38400);

  //start the car parked/not moving
  parked();
}

void loop(){
  forward();

  //set servos to min point
  myServo.write(num);

  //change num by 90 degrees if less than 180
  if (num == 180) {
    num = 0;
  }
  else {
    num = num + 90;
  }

  //wait for half a second
  delay(1000);
  
  backward();

  delay(1000);
}
