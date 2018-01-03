#include <TimerOne.h>
#include <string.h>

//Pin verbunden mit ST_CP 
int latchPin = 10;
//Pin verbunden mit SH_CP
int clockPin = 13;
//Pin verbunden mit DS
int dataPin = 11;

//Enthält Werte für alle Pins (0 oder 1)
byte cube [8][8][8];


void setup() {
  // put your setup code here, to run once:
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() {
 
  for(int i = 0; i <= 8; i++){
    digitalWrite(storePin, LOW);
    for(int j = 0; i <= 8; i++){
      for(int k = 0; i <= 8; i++){
        cube[i][j][k] = 1;
      }
    }

    digitalWrite(shiftPin, LOW);
    digitalWrite(dataPin, cube[i][j][k]);
    digitalWrite(shiftPin, HIGH);

    digitalWrite(storePin, HIGH);
  }
}
  
