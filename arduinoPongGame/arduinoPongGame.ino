#include "Arduino_LED_Matrix.h"
ArduinoLEDMatrix matrix;
byte frame[8][12];
int lifeCount = 3;
int lifeOne = 11;
int lifeTwo = 10;
int lifeThree = 9;
int upButton = 2;
int downButton = 4;
int br = 115200;
int delayTime = 75;
int moveUp;
int moveDown;
int pongPosition;
int pongX = 0;
int pongY = 0;

void setup() {
  pinMode(lifeOne, OUTPUT);
  pinMode(lifeTwo, OUTPUT);
  pinMode(lifeThree, OUTPUT);
  pinMode(upButton, INPUT);
  pinMode(downButton, INPUT);
  Serial.begin(br);
  matrix.begin();
}

void loop() {
digitalWrite(lifeOne, HIGH);
digitalWrite(lifeTwo, HIGH);
digitalWrite(lifeThree, HIGH);
frame[pongX][pongY] = !frame[pongX][pongY];
matrix.renderBitmap(frame, 8, 12);
moveUp = digitalRead(upButton);
  if (moveUp == 0){
    pongX = pongX + 1;
    delay(delayTime);
    Serial.println("moving up");
  }
moveDown = digitalRead(downButton);
Serial.println(moveDown);
  if (moveDown == 0){
    pongX = pongX - 1;
    delay(delayTime);
    Serial.println("moving down");
  }

}
