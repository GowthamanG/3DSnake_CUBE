int num;
int lightShow;
 
//--- Pin connected to ST_CP of 74HC595
int latchPin = 10;
//--- Pin connected to SH_CP of 74HC595
int clockPin = 13;
//--- Pin connected to DS of 74HC595
int dataPin = 11;
 
byte pinVals[8];
int zLayer = 2;

void lightShow1(int num){
  int k = 7;
    for(int i = 0; i < 8; i++){
      for(int j = 0; j < 8; j++){
        bitClear(pinVals[j], i);
      }
    }

    for(int i = 0; i < 8; i++){
        bitSet(pinVals[k], i);
    }
    
    k--;
    if(k < 0){
      k = 7;
    }
  
    if(k > 7) {
      num -= 10;
    }
    delay(num);
}

void lightShow2(int num){
  int k = 0;
  
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      bitClear(pinVals[i], j);
    }
  }

  for(int i = 0; i < 8; i++){
    bitSet(pinVals[i], k);
  }

  k++;
  if(k > 7){
    k = 0;
  }
  
  if(k > 6) {
    num -= 10;
  }
  delay(num);
}

void lightShow3(int num){
  int k = 0;
  
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      bitClear(pinVals[i], j);
    }
  }

  for(int i = 0; i < 8; i++){
    bitSet(pinVals[i], k);
  }
   
  k++;
  if(k > 7){
    k = 0;
  }
  
  if(k > 6) {
    num -= 10;
  }
  delay(num);
}
  


void lightShow4(int num){
  int k = 0;

  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      bitClear(pinVals[i], j);
    }
  }

  for(int i = 0; i < 8; i++){
    bitSet(pinVals[i], k);
  }

  k--;
  if(k < 0){
    k = 7;
  }

  if(k > 6) {
    num -= 10;
  }
  delay(num); 
}

void lightShow5(int num){
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      bitClear(pinVals[i], j);
    }
  }

  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      bitSet(pinVals[i], j);
    }
  }

  digitalWrite(zLayer, HIGH);
  zLayer++;
  if(zLayer > 9){
    zLayer = 2;
  }
  digitalWrite(zLayer, LOW);

  if(zLayer > 8) {
    num -= 10;
  }
  delay(num);
}

void lightShow6(int num){
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      bitClear(pinVals[i], j);
    }
  }

  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      bitSet(pinVals[i], j);
    }
  }

  digitalWrite(zLayer, HIGH);
  zLayer++;
  if(zLayer > 9){
    zLayer = 2;
  }
  digitalWrite(zLayer, LOW);

  if(zLayer > 8) {
    num -= 10;
  }
  delay(num);
}

void chooseLightShow(int lightShow, int num){
  switch(lightShow){
    case 1:
      lightShow1(num);
      break;
    case 2:
      lightShow2(num);
      break;
    case 3:
      lightShow3(num);
      break;
    case 4:
      lightShow4(num);
      break;
    case 5:
      lightShow5(num);
      break;
    case 6:
      lightShow6(num);
      break;
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
 
  bitSet(pinVals[0], 0);
  digitalWrite(zLayer, LOW);

  lightShow = 1;
  num = 120;
}
 
void loop(){
  digitalWrite(latchPin, LOW);
  for(int i = 0; i < 8; i++){
   shiftOut(dataPin, clockPin, MSBFIRST, pinVals[i]);
  }
  digitalWrite(latchPin, HIGH);

  if(num > 10){
    chooseLightShow(lightShow, num);
  }else{
    lightShow++;
    if(lightShow > 6){
      lightShow = 1;
    }
    num = 120;
  } 
}
