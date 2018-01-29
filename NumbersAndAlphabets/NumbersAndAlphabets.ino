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

void letterA(){
  for(int i = 0; i < 8; i++){
    bitClear(pinVals[1], i); 
    bitClear(pinVals[6], i); 
  }

  for(int i = 2; i < 6; i++){
    bitClear(pinVals[i], 0);
    bitClear(pinVals[i], 3);
  }

  for(int i = 0; i < 8; i++){
    bitSet(pinVals[1], i); 
    bitSet(pinVals[6], i); 
  }

  for(int i = 2; i < 6; i++){
    bitSet(pinVals[i], 0);
    bitSet(pinVals[i], 3);
  }
}
void letterB(){
  for(int i = 0; i < 8; i++){
    bitClear(pinVals[6], i);  
  }

  for(int i = 0; i < 4; i++){
    bitClear(pinVals[2], i);  
  }

  for(int i = 3; i < 8; i++){
    bitClear(pinVals[0], i);  
  }

  for(int i = 0; i < 7; i++){
    bitClear(pinVals[i], 3);
    bitClear(pinVals[i], 7);   
  }

  for(int i = 2; i < 7; i++){
    bitClear(pinVals[i], 0);  
  } 

  for(int i = 0; i < 8; i++){
    bitSet(pinVals[6], i);  
  }

  for(int i = 0; i < 4; i++){
    bitSet(pinVals[2], i);  
  }

  for(int i = 3; i < 8; i++){
    bitSet(pinVals[0], i);  
  }

  for(int i = 0; i < 7; i++){
    bitSet(pinVals[i], 3);
    bitSet(pinVals[i], 7);   
  }

  for(int i = 2; i < 7; i++){
    bitSet(pinVals[i], 0);  
  }
}


void letterC(){
  for(int i = 1; i < 7; i++){
    bitClear(pinVals[i], 0);  
    bitClear(pinVals[i], 7); 
  }

  for(int i = 1; i < 8; i++){
    bitClear(pinVals[6], i); 
  }

  for(int i = 1; i < 7; i++){
    bitSet(pinVals[i], 0);  
    bitSet(pinVals[i], 7); 
  }

  for(int i = 1; i < 8; i++){
    bitSet(pinVals[6], i); 
  }
}

void letterD(){
  for(int i = 1; i < 6; i++){
    bitClear(pinVals[i], 0);  
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
    bitSet(pinVals[i], 7); 
  }

  for(int i = 1; i < 8; i++){
    bitSet(pinVals[6], i); 
  }

  for(int i = 1; i < 7; i++){
    bitSet(pinVals[1], i);
  }
}
void letterE(){
  for(int i = 1; i < 7; i++){
    bitClear(pinVals[i], 0);  
    bitClear(pinVals[i], 7); 
  }

  for(int i = 1; i < 8; i++){
    bitClear(pinVals[6], i); 
  }

  for(int i = 3; i < 7; i++){
    bitClear(pinVals[i], 3);
  }

  for(int i = 1; i < 7; i++){
    bitSet(pinVals[i], 0);  
    bitSet(pinVals[i], 7); 
  }

  for(int i = 1; i < 8; i++){
    bitSet(pinVals[6], i); 
  }

  for(int i = 3; i < 7; i++){
    bitSet(pinVals[i], 3);
  }
}

void letterF(){
  for(int i = 1; i < 7; i++){
    bitClear(pinVals[i], 0);  
  }

  for(int i = 1; i < 8; i++){
    bitClear(pinVals[6], i); 
  }

  for(int i = 3; i < 7; i++){
    bitClear(pinVals[i], 3);
  }

  for(int i = 1; i < 7; i++){
    bitSet(pinVals[i], 0);  
  }

  for(int i = 1; i < 8; i++){
    bitSet(pinVals[6], i); 
  }

  for(int i = 3; i < 7; i++){
    bitSet(pinVals[i], 3);
  }
}

void letterG(){
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

  bitClear(pinVals[1], 1);

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

  bitSet(pinVals[1], 1);
}
void letterH(){
  for(int i = 0; i < 8; i++){
    bitClear(pinVals[1], i); 
    bitClear(pinVals[6], i); 
  }

  for(int i = 2; i < 6; i++){
    bitClear(pinVals[i], 3);
  }

  for(int i = 0; i < 8; i++){
    bitSet(pinVals[1], i); 
    bitSet(pinVals[6], i); 
  }

  for(int i = 2; i < 6; i++){
    bitSet(pinVals[i], 3);
  }
}

void letterI(){
  for(int i = 0; i < 8; i++){
    bitClear(pinVals[3], i);  
  }

  for(int i = 2; i < 5; i++){
    bitClear(pinVals[i], 0);
    bitClear(pinVals[i], 7);
  }

  for(int i = 0; i < 8; i++){
    bitSet(pinVals[3], i);  
  }

  for(int i = 2; i < 5; i++){
    bitSet(pinVals[i], 0);
    bitSet(pinVals[i], 7);
  }
}


void letterJ(){
  for(int i = 1; i < 7; i++){
    bitClear(pinVals[i], 0);
  }

  for(int i = 0; i < 7; i++){
    bitClear(pinVals[1], i);
  }

  for(int i = 2; i < 6; i++){
    bitClear(pinVals[i], 7);
  }

  bitClear(pinVals[6], 6);

  for(int i = 1; i < 7; i++){
    bitSet(pinVals[i], 0);
  }

  for(int i = 0; i < 7; i++){
    bitSet(pinVals[1], i);
  }

  for(int i = 2; i < 6; i++){
    bitSet(pinVals[i], 7);
  }

  bitSet(pinVals[6], 6);  
}

void letterK(){
  for(int i = 0; i < 8; i++){
    bitClear(pinVals[6], i);
  }

  bitClear(pinVals[1], 0);
  bitClear(pinVals[2], 1);
  bitClear(pinVals[3], 2);
  bitClear(pinVals[4], 3);
  bitClear(pinVals[5], 4);

  bitClear(pinVals[4], 5);
  bitClear(pinVals[3], 6);
  bitClear(pinVals[2], 7);

  for(int i = 0; i < 8; i++){
    bitSet(pinVals[6], i);
  }

  bitSet(pinVals[1], 0);
  bitSet(pinVals[2], 1);
  bitSet(pinVals[3], 2);
  bitSet(pinVals[4], 3);
  bitSet(pinVals[5], 4);

  bitSet(pinVals[4], 5);
  bitSet(pinVals[3], 6);
  bitSet(pinVals[2], 7); 
}

void letterL(){
  for(int i = 0; i < 8; i++){
    bitClear(pinVals[6], i);  
  }

  for(int i = 1; i < 7; i++){
    bitClear(pinVals[i], 7);  
  }

  for(int i = 0; i < 8; i++){
    bitSet(pinVals[6], i);  
  }

  for(int i = 1; i < 7; i++){
    bitSet(pinVals[i], 7);  
  }
}

void letterM(){
  for(int i = 0; i < 8; i++){
    bitClear(pinVals[1], i);
    bitClear(pinVals[6], i);    
  }
  bitClear(pinVals[2], 1);
  bitClear(pinVals[3], 2);
  bitClear(pinVals[4], 2);
  bitClear(pinVals[5], 1);

  for(int i = 0; i < 8; i++){
    bitSet(pinVals[1], i);
    bitSet(pinVals[6], i);    
  }
  bitSet(pinVals[2], 1);
  bitSet(pinVals[3], 2);
  bitSet(pinVals[4], 2);
  bitSet(pinVals[5], 1);
}

void letterN(){
  for(int i = 0; i < 8; i++){
    bitClear(pinVals[1], i);
    bitClear(pinVals[6], i);    
  }
  bitClear(pinVals[2], 5);
  bitClear(pinVals[3], 4);
  bitClear(pinVals[4], 3);
  bitClear(pinVals[5], 2);

  for(int i = 0; i < 8; i++){
    bitSet(pinVals[1], i);
    bitSet(pinVals[6], i);    
  }
  bitSet(pinVals[2], 5);
  bitSet(pinVals[3], 4);
  bitSet(pinVals[4], 3);
  bitSet(pinVals[5], 2);
}

void letterO(){
  for(int i = 0; i < 8; i++){
    bitClear(pinVals[1], i);
    bitClear(pinVals[6], i);    
  }

  for(int i = 2; i < 6; i++){
    bitClear(pinVals[i], 0);
    bitClear(pinVals[i], 7);
  }

  for(int i = 0; i < 8; i++){
    bitSet(pinVals[1], i);
    bitSet(pinVals[6], i);    
  }

  for(int i = 2; i < 6; i++){
    bitSet(pinVals[i], 0);
    bitSet(pinVals[i], 7);
  }
}

void letterP(){
  for(int i = 0; i < 8; i++){
    bitClear(pinVals[1], i);   
  }
  bitClear(pinVals[1], 1);   
  bitClear(pinVals[1], 2);  
  bitClear(pinVals[1], 3);  
  

  for(int i = 2; i < 6; i++){
    bitClear(pinVals[i], 0);
    bitClear(pinVals[i], 3);
  }

  for(int i = 0; i < 8; i++){
    bitSet(pinVals[1], i);   
  }
  bitSet(pinVals[1], 1);   
  bitSet(pinVals[1], 2);  
  bitSet(pinVals[1], 3);  
  

  for(int i = 2; i < 6; i++){
    bitSet(pinVals[i], 0);
    bitSet(pinVals[i], 3);
  }
}

void letterQ(){
  for(int i = 0; i < 8; i++){
    bitClear(pinVals[1], i);
    bitClear(pinVals[6], i);    
  }

  for(int i = 2; i < 6; i++){
    bitClear(pinVals[i], 0);
    bitClear(pinVals[i], 7);
  }
  bitClear(pinVals[0], 7);

  for(int i = 0; i < 8; i++){
    bitSet(pinVals[1], i);
    bitSet(pinVals[6], i);    
  }

  for(int i = 2; i < 6; i++){
    bitSet(pinVals[i], 0);
    bitSet(pinVals[i], 7);
  }
  bitSet(pinVals[0], 7);
}

void letterR(){
  for(int i = 0; i < 8; i++){
    bitClear(pinVals[1], i);   
  }
  bitClear(pinVals[1], 1);   
  bitClear(pinVals[1], 2);  
  bitClear(pinVals[1], 3);  
  

  for(int i = 2; i < 6; i++){
    bitClear(pinVals[i], 0);
    bitClear(pinVals[i], 3);
  }
  bitClear(pinVals[1], 7);
  bitClear(pinVals[2], 6);
  bitClear(pinVals[3], 5);
  bitClear(pinVals[4], 4);

  for(int i = 0; i < 8; i++){
    bitSet(pinVals[1], i);   
  }
  bitSet(pinVals[1], 1);   
  bitSet(pinVals[1], 2);  
  bitSet(pinVals[1], 3);  
  

  for(int i = 2; i < 6; i++){
    bitSet(pinVals[i], 0);
    bitSet(pinVals[i], 3);
  }
  bitSet(pinVals[1], 7);
  bitSet(pinVals[2], 6);
  bitSet(pinVals[3], 5);
  bitSet(pinVals[4], 4);
}

void letterS(){
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
  bitClear(pinVals[1], 1);
  bitClear(pinVals[7], 7);

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
  bitSet(pinVals[1], 1);
  bitSet(pinVals[7], 7);
}

void letterT(){
  for(int i = 1; i < 8; i++){
    bitClear(pinVals[3], i);
  }

  for(int i = 0; i < 7; i++){
    bitClear(pinVals[i], 0);
  }

  for(int i = 1; i < 8; i++){
    bitSet(pinVals[3], i);
  }

  for(int i = 0; i < 7; i++){
    bitSet(pinVals[i], 0);
  }
}

void letterU(){
  for(int i = 0; i < 8; i++){
    bitClear(pinVals[1], i);
    bitClear(pinVals[6], i);    
  }

  for(int i = 2; i < 6; i++){
    bitClear(pinVals[i], 7);
  }

  for(int i = 0; i < 8; i++){
    bitSet(pinVals[1], i);
    bitSet(pinVals[6], i);    
  }

  for(int i = 2; i < 6; i++){
    bitSet(pinVals[i], 7);
  }
}

void letterV(){
  for(int i = 0; i < 6; i++){
    bitClear(pinVals[1], i);
    bitClear(pinVals[6], i);    
  }
  bitClear(pinVals[2], 6);
  bitClear(pinVals[3], 7);
  bitClear(pinVals[4], 7);
  bitClear(pinVals[5], 6);
  

  for(int i = 0; i < 8; i++){
    bitSet(pinVals[1], i);
    bitSet(pinVals[6], i);    
  }
  bitSet(pinVals[2], 6);
  bitSet(pinVals[3], 7);
  bitSet(pinVals[4], 7);
  bitSet(pinVals[5], 6);
}

void letterW(){
  for(int i = 0; i < 8; i++){
    bitClear(pinVals[1], i);
    bitClear(pinVals[6], i);    
  }
  bitClear(pinVals[2], 6);
  bitClear(pinVals[3], 5);
  bitClear(pinVals[4], 5);
  bitClear(pinVals[5], 6);

  for(int i = 0; i < 8; i++){
    bitSet(pinVals[1], i);
    bitSet(pinVals[6], i);    
  }
  bitSet(pinVals[2], 6);
  bitSet(pinVals[3], 5);
  bitSet(pinVals[4], 5);
  bitSet(pinVals[5], 6);
}

void letterZ(){
  for(int i = 1; i < 7; i++){
    bitClear(pinVals[i], 0);
    bitClear(pinVals[i], 7);
    bitClear(pinVals[i], i);
  }

  for(int i = 1; i < 7; i++){
    bitSet(pinVals[i], 0);
    bitSet(pinVals[i], 7);
    bitSet(pinVals[i], i);
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

void loop(){
  digitalWrite(latchPin, LOW);
  for(int i = 0; i < 8; i++){
   shiftOut(dataPin, clockPin, MSBFIRST, pinVals[i]);
  }
  digitalWrite(latchPin, HIGH);

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
