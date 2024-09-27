#include "Arduino_LED_Matrix.h"
ArduinoLEDMatrix matrix;
int br=115200;
int pongPixelTimer = 150;
int xPos=3;
int yPos=2;
int deltaX=1;
int deltaY=1;

int upButton = 2;
int upValue;
int downButton = 4;
int downValue;
int playerPixel;
int playerPixelTimer = 50;
int playerRow = 4;
int step = 1;
int cnt = 0;

int i;
int j;

byte frame[8][12];

void setup() {
pinMode(upButton, INPUT);
pinMode(downButton, INPUT);
Serial.begin(br);
matrix.begin();
}
void loop() {
upValue = digitalRead(upButton);
downValue = digitalRead(downButton);

if(upValue == 0 ){
  playerRow = playerRow + step;
}
if(downValue == 0){
  playerRow = playerRow - step;
}

if(cnt % 2 == 0){

for ( i = 0; i <= 11; i = i + 1){
  for (j = 0; j <= 7; j = j + 1){
    frame[j][i] = 0;
    if (i == xPos && j == yPos){
      frame[j][i] = 1;
    }
    if(i == 0 && j == playerRow){
      frame[j][i] = 1;
    }
  }
}
matrix.renderBitmap(frame, 8, 12);
if (xPos >= 11 || xPos <= 0){
  deltaX = -deltaX;
}
if (yPos >= 7 || yPos <= 0){
  deltaY = -deltaY;
}
if (xPos == 0 && yPos != playerRow){
  Serial.println("Game Over!");
  delay(5000);
}
xPos = xPos + deltaX;
yPos = yPos + deltaY;
}
cnt = cnt + 1;
delay(pongPixelTimer);
}