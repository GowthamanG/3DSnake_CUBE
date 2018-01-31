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
  
  digitalWrite(zLayer, LOW);
}
 
void loop(){
  digitalWrite(latchPin, LOW);
  for(int i = 0; i < 8; i++){
   shiftOut(dataPin, clockPin, MSBFIRST, pinVals[i]);
  }
  digitalWrite(latchPin, HIGH);
 
  //Set the display bits
  for(int i = 0; i < 8; i++){
      bitClear(pinVals[6], i);
    }
  


  for(int i = 0; i < 8; i++){
    for(int j = i; j < 8; j++){
      bitSet(pinVals[i], j);
    }
  } 

  digitalWrite(zLayer, HIGH);
  zLayer++;
  if(zLayer > 9){
    zLayer = 2;
  }
    
  digitalWrite(zLayer, LOW);

  delay(50);
 
}
