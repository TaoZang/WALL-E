#include <Servo.h>

const int SERVO_L_FORWARD_FAST = 180;
const int SERVO_L_FORWARD_MEDIUM = 135;
const int SERVO_L_FORWARD_SLOW = 95;
const int SERVO_L_BACKWARD_SLOW = 85;
const int SERVO_L_BACKWARD_MEDIUM = 45;
const int SERVO_L_BACKWARD_FAST = 0;

const int SERVO_R_FORWARD_FAST = 0;
const int SERVO_R_FORWARD_MEDIUM = 45;
const int SERVO_R_FORWARD_SLOW = 85;
const int SERVO_R_BACKWARD_SLOW = 95;
const int SERVO_R_BACKWARD_MEDIUM = 135;
const int SERVO_R_BACKWARD_FAST = 180;

// head angle: 160 - 100

const int SONIC_FORWARD_TRIG = 8;
const int SONIC_FORWARD_ECHO = 9;
const int SONIC_DOWNWARD_TRIG = 10;
const int SONIC_DOWNWARD_ECHO = 11;

const int SERVO_HEAD = 2;
const int SERVO_NECK = 3;
const int SERVO_WHEEL_L = 4;
const int SERVO_WHEEL_R = 5;
const int SERVO_LEG_L = 6;
const int SERVO_LEG_R = 7;

Servo servo_wheel_l, servo_wheel_r;
Servo servo_head, servo_neck;

int valX = 0;
int valY = 0; 

long duration_forward, distance_forward;
long duration_downward, distance_downward;

void setup()
{
  Serial.begin(9600);

//  servo_head.attach(SERVO_HEAD);
//  servo_neck.attach(SERVO_NECK);
//  servo_wheel_l.attach(SERVO_WHEEL_L);
//  servo_wheel_r.attach(SERVO_WHEEL_R);
//  
  pinMode(SONIC_FORWARD_TRIG, OUTPUT);
  pinMode(SONIC_FORWARD_ECHO, INPUT);
  pinMode(SONIC_DOWNWARD_TRIG, OUTPUT);
  pinMode(SONIC_DOWNWARD_ECHO, INPUT);
}

void loop()
{
  Serial.println(get_distance(SONIC_FORWARD_TRIG, SONIC_FORWARD_ECHO));
  delay(100);
//  say_hello();
//  move_backward();
//  distance_forward = filter_forward(get_distance_forward());
//  
//  Serial.println(distance_forward);
//  if (get_distance_forward() < 10) {
//    move_stop();
//    say_hello();
//    move_backward();
//  } else {
//    move_forward();
//  }
}

void say_hello()
{
  servo_neck.write(90);
  servo_head.write(140);
  delay(1000);
  
  servo_neck.write(0);
  delay(1000);
  
  servo_neck.write(180);
  delay(1000);
  
  servo_neck.write(90);
  servo_head.write(100);
  delay(1000);
  
  servo_head.write(160);
}

void move_stop()
{
  servo_wheel_l.write(SERVO_L_FORWARD_SLOW);
  servo_wheel_r.write(SERVO_R_FORWARD_SLOW);
}

void move_forward()
{
  servo_wheel_l.write(SERVO_L_FORWARD_FAST);
  servo_wheel_r.write(SERVO_R_FORWARD_FAST);
}

void move_backward()
{
  servo_wheel_l.write(SERVO_L_BACKWARD_FAST);
  servo_wheel_r.write(SERVO_R_BACKWARD_FAST);
}

long get_distance(int trig, int echo)
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  long duration = pulseIn(echo, HIGH);
  return duration / 58.2;
}

