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
int delayTime = 250;
int movementDelay = 75;
int moveUp;
int moveDown;
int pongPosition;
int pongX = 0;
int pongY = 0;
int xPos = 3;
int yPos = 2;
int deltaX = 1;
int deltaY = 1;
int i;
int j;

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

memset(frame, 0, sizeof(frame)); 

frame[pongX][pongY] = 1;

matrix.renderBitmap(frame, 8, 12);

if (digitalRead(upButton) == HIGH){
  if (pongX > 0) { 
    pongX--;
    delay(delayTime);
    Serial.println("moving up");
  }
}
  
if (digitalRead(downButton) == HIGH){
  if (pongX < 7) { 
    pongX++;
    delay(delayTime);
    Serial.println("moving down");
  }
}

  for(i = 0; i < 8; i= i + 1) {
    for(j = 0; j < 12; j = j + 1) {
      frame[i][j] = 0;
      if(i == xPos && j == yPos){
        frame[i][j] = 1;
      }
    }
  }

  if(xPos >= 7 || xPos <= 0){
    deltaX = -deltaX;
  }
  if(yPos >= 11 || yPos <= 0){
    deltaY = -deltaY;
  }
matrix.renderBitmap(frame, 8, 12);
  xPos += deltaX;
  yPos += deltaY;
  delay(movementDelay);
}
