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
  for(int h = 7; h < 0; h--){
    for(int i = 0; i < 8; i++){
      for(int j = 0; j < 8; j++){
        bitClear(pinVals[j], i);
      }
    }

    for(int i = 0; i < 8; i++){
        bitSet(pinVals[h], i);
    }
    delay(num);
  }
}

void lightShow2(int num){
  int k = 0;
 for(int h = 0; h < 8; h++){
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      bitClear(pinVals[i], j);
    }
  }

  for(int i = 0; i < 8; i++){
    bitSet(pinVals[i], k);
  }

  k++;
  delay(num);
 }
}

void lightShow3(int num){
  int k = 0;
 for(int h = 0; h < 8; h++){
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      bitClear(pinVals[i], j);
    }
  }

  for(int i = 0; i < 8; i++){
    bitSet(pinVals[i], k);
  }
   
  k++;
  delay(num);
 }
}
  


void lightShow4(int num){
  int k = 0;
 for(int h = 0; h < 8; h++){
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      bitClear(pinVals[i], j);
    }
  }

  for(int i = 0; i < 8; i++){
    bitSet(pinVals[i], k);
  }

  k--;
  delay(num); 
 }
}

void lightShow5(int num){
 for(int h = 0; h < 8; h++){
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
  digitalWrite(zLayer, LOW);

  delay(num);
 }
}

void lightShow6(int num){
 for(int h = 0; h < 8; h++){
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
  digitalWrite(zLayer, LOW);
  delay(num);
 }
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
    num -= 10;
  }else{
    lightShow++;
    if(lightShow > 6){
      lightShow = 1;
    }
  }
  num = 120; 
}
