#include <Arduino.h>
#include <Servo.h>

Servo myservo;

int xPin = 34; // define x axis joystick pin
int yPin = 35; // define y axis joystick pin

int xVal; // variable to store x axis value
int yVal; // variable to store y axis value

int servoPin = 13; // define servo pin
int servoPos = 90; // initial servo position

void setup()
{
  Serial.begin(9600);
  myservo.attach(servoPin);
  myservo.write(90);
}

void loop()
{
  // read x and y axis values from joystick
  xVal = analogRead(xPin);
  yVal = analogRead(yPin);

  // map joystick values to servo position (0 to 180)
  servoPos = map(yVal, 0, 4095, 0, 180);

  // move servo to new position
  myservo.write(servoPos);

  delay(15); // small delay for stability
}
