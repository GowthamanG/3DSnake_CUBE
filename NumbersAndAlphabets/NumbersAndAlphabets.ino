//Test an 8x8x8 LED cube
 
 
//--- Pin connected to ST_CP of 74HC595
int latchPin = 10;
//--- Pin connected to SH_CP of 74HC595
int clockPin = 13;
//--- Pin connected to DS of 74HC595
int dataPin = 11;
 
byte pinVals[8];
 int zLayer = 2;
 int xc = 0;
 int yc = 0;

void numberOne(){
  for(int i = 0; i < 8; i++){
    bitClear(pinVals[2], i);
  }

  bitClear(pinVals[3], 1);
  bitClear(pinVals[4], 2);
  bitClear(pinVals[5], 3);

  for(int i = 0; i < 8; i++){
    bitSet(pinVals[2], i);
  }

  bitSet(pinVals[3], 1);
  bitSet(pinVals[4], 2);
  bitSet(pinVals[5], 3);
}

void numberTwo(){
  for(int i = 1; i < 7; i++){
    bitClear(pinVals[i], 0);
    bitClear(pinVals[i], 3);
    bitClear(pinVals[i], 7);
  }

  for(int i = 1; i < 4; i++){
    bitClear(pinVals[1], i);
  }

  for(int i = 4; i < 7; i++){
    bitClear(pinVals[6], i);
  }

  for(int i = 1; i < 7; i++){
    bitSet(pinVals[i], 0);
    bitSet(pinVals[i], 3);
    bitSet(pinVals[i], 7);
  }

  for(int i = 1; i < 4; i++){
    bitSet(pinVals[1], i);
  }

  for(int i = 4; i < 7; i++){
    bitSet(pinVals[6], i);
  }
}

void numberThree(){
  for(int i = 0; i < 8; i++){
    bitClear(pinVals[1], i);
  }

  for(int i = 2; i < 7; i++){
    bitClear(pinVals[i], 0);
    bitClear(pinVals[i], 7);
  }

  for(int i = 2; i < 5; i++){
    bitClear(pinVals[i], 3);
  }

  for(int i = 0; i < 8; i++){
    bitSet(pinVals[1], i);
  }

  for(int i = 2; i < 7; i++){
    bitSet(pinVals[i], 0);
    bitSet(pinVals[i], 7);
  }

  for(int i = 2; i < 5; i++){
    bitSet(pinVals[i], 3);
  }
}

void numberFour(){
  for(int i = 0; i < 8; i++){
    bitClear(pinVals[2], i);
  }

  for(int i = 1; i < 7; i++){
    bitClear(pinVals[i], 3);
  }

  for(int i = 0; i < 4; i++){
    bitClear(pinVals[6], i);
  }

  for(int i = 0; i < 8; i++){
    bitSet(pinVals[2], i);
  }

  for(int i = 1; i < 7; i++){
    bitSet(pinVals[i], 3);
  }

  for(int i = 0; i < 4; i++){
    bitSet(pinVals[6], i);
  }
}

void numberFive(){
  for(int i = 1; i < 7; i++){
    bitClear(pinVals[i], 0);
    bitClear(pinVals[i], 3);
    bitClear(pinVals[i], 7);
  }

  for(int i = 1; i < 4; i++){
    bitClear(pinVals[6], i);
  }

  for(int i = 4; i < 7; i++){
    bitClear(pinVals[1], i);
  }

  for(int i = 1; i < 7; i++){
    bitSet(pinVals[i], 0);
    bitSet(pinVals[i], 3);
    bitSet(pinVals[i], 7);
  }

  for(int i = 1; i < 4; i++){
    bitSet(pinVals[6], i);
  }

  for(int i = 4; i < 7; i++){
    bitSet(pinVals[1], i);
  }
}

void numberSix(){
  for(int i = 1; i < 7; i++){
    bitClear(pinVals[i], 0);
    bitClear(pinVals[i], 3);
    bitClear(pinVals[i], 7);
  }

  for(int i = 1; i < 8; i++){
    bitClear(pinVals[6], i);
  }

  for(int i = 4; i < 7; i++){
    bitClear(pinVals[1], i);
  }

  for(int i = 1; i < 7; i++){
    bitSet(pinVals[i], 0);
    bitSet(pinVals[i], 3);
    bitSet(pinVals[i], 7);
  }

  for(int i = 1; i < 8; i++){
    bitSet(pinVals[6], i);
  }

  for(int i = 4; i < 7; i++){
    bitSet(pinVals[1], i);
  }
}

void numberSeven(){
  for(int i = 0; i < 8; i++){
    bitClear(pinVals[1], i);
  }

  for(int i = 2; i < 7; i++){
    bitClear(pinVals[i], 0);
  }

  for(int i = 1; i < 4; i++){
    bitClear(pinVals[6], i);
  }

  for(int i = 0; i < 8; i++){
    bitSet(pinVals[1], i);
  }

  for(int i = 2; i < 7; i++){
    bitSet(pinVals[i], 0);
  }

  for(int i = 1; i < 4; i++){
    bitSet(pinVals[6], i);
  }
}

void numberEight(){
  for(int i = 1; i < 7; i++){
    bitClear(pinVals[i], 0);
    bitClear(pinVals[i], 3);
    bitClear(pinVals[i], 7);
  }

  for(int i = 1; i < 8; i++){
    bitClear(pinVals[6], i);
  }

  for(int i = 1; i < 7; i++){
    bitClear(pinVals[1], i);
  }

  for(int i = 1; i < 7; i++){
    bitSet(pinVals[i], 0);
    bitSet(pinVals[i], 3);
    bitSet(pinVals[i], 7);
  }

  for(int i = 1; i < 8; i++){
    bitSet(pinVals[6], i);
  }

  for(int i = 1; i < 7; i++){
    bitSet(pinVals[1], i);
  }
  
}

void numberNine(){
/*  for(int i = 1; i < 7; i++){
    bitClear(pinVals[i], 0);
    bitClear(pinVals[i], 3);
    bitClear(pinVals[i], 7);
  }

  for(int i = 1; i < 4; i++){
    bitClear(pinVals[6], i);
  }

  for(int i = 1; i < 7; i++){
    bitClear(pinVals[1], i);
  }*/

  for(int i = 1; i < 7; i++){
    bitSet(pinVals[i], 0);
    bitSet(pinVals[i], 3);
    bitSet(pinVals[i], 7);
  }

  for(int i = 1; i < 4; i++){
    bitSet(pinVals[6], i);
  }

  for(int i = 1; i < 7; i++){
    bitSet(pinVals[1], i);
  }
}

 
void setup(){
    //layer pins
  for(int i = 2; i < 10; i++)
  {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
 
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
 
  digitalWrite(latchPin,LOW);
  digitalWrite(dataPin,LOW);
  digitalWrite(clockPin,LOW);
  
}

int counter = 0;
 
void loop(){
  digitalWrite(latchPin, LOW);
  for(int i = 0; i < 8; i++){
   shiftOut(dataPin, clockPin, MSBFIRST, pinVals[i]);
  }
  digitalWrite(latchPin, HIGH);

  for (counter; counter < 3; counter){
    
  }

  numberNine();
  
 
  digitalWrite(zLayer, HIGH);
  digitalWrite(zLayer+1, HIGH);
  
  zLayer++;
  if(zLayer > 9){
    zLayer = 2;
  }
    
  digitalWrite(zLayer, LOW);
  digitalWrite(zLayer+1, LOW);

  delay(50);

  
    
  
  
 
}
