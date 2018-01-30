int num;
char current;
char myName[20];

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
  for(int i = 1; i < 7; i++){
    bitClear(pinVals[i], 0);
    bitClear(pinVals[i], 3);
    bitClear(pinVals[i], 7);
  }

  for(int i = 1; i < 4; i++){
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
  for(int i = 2; i < 6; i++){
    bitClear(pinVals[i], 0);  
    bitClear(pinVals[i], 7); 
  }

  for(int i = 0; i < 8; i++){
    bitClear(pinVals[6], i); 
  }

  for(int i = 1; i < 7; i++){
    bitClear(pinVals[1], i);
  }

  for(int i = 2; i < 6; i++){
    bitSet(pinVals[i], 0);  
    bitSet(pinVals[i], 7); 
  }

  for(int i = 0; i < 8; i++){
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
    bitClear(pinVals[6], i);   
  }

  for(int i = 0; i < 4; i++){
    bitClear(pinVals[1], i);   
  }
  

  for(int i = 2; i < 6; i++){
    bitClear(pinVals[i], 0);
    bitClear(pinVals[i], 3);
  }

  for(int i = 0; i < 8; i++){
    bitSet(pinVals[1], i);   
  }

  for(int i = 0; i < 4; i++){
    bitSet(pinVals[6], i);   
  }
  
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
    bitClear(pinVals[6], i);   
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
    bitSet(pinVals[6], i);   
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
  bitClear(pinVals[6], 6);

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
  bitSet(pinVals[6], 6);
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
  

  for(int i = 0; i < 6; i++){
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

void letterUp(){
  for(int i = 0; i < 8; i++) {
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
}



void chooseLetter(int a){
  switch(a){
    case 1:
      letterA();
      letterUp();
       break;
    case 2:
      letterB();
      letterUp();
      break;
    case 3:
      letterC();
      letterUp();
      break;
    case 4:
      letterD();
      letterUp();
      break;
    case 5:
      letterE();
      letterUp();
      break;
    case 6:
      letterF();
      letterUp();
      break;
    case 7:
      letterG();
      letterUp();
      break;
    case 8:
      letterH();
      letterUp();
      break;
    case 9:
      letterI();
      letterUp();
      break;
    case 10:
      letterJ();
      letterUp();
      break;
    case 11:
      letterK();
      letterUp();
      break;
    case 12:
      letterL();
      letterUp();
      break;
    case 13:
      letterM();
      letterUp();
      break;
    case 14:
      letterN();
      letterUp();
      break;
    case 15:
      letterO();
      letterUp();
      break;
    case 16:
      letterP();
      letterUp();
      break;
    case 17:
      letterQ();
      letterUp();
      break;
    case 18:
      letterR();
      letterUp();
      break;
    case 19:
      letterS();
      letterUp();
      break;
    case 20:
      letterT();
      letterUp();
      break;
    case 21:
      letterU();
      letterUp();
      break;
    case 22:
      letterV();
      letterUp();
      break;
    case 23:
      letterW();
      letterUp();
      break;
    case 24:
      letterZ();
      letterUp();
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

  Serial.begin(9600);

  num = 1;
}

void helloWorld(int a){
  switch(a){
    case 1:
      chooseLetter(8);  //H
      break;
    case 2:
      chooseLetter(5);   //E
      break;
    case 3:
      chooseLetter(12);  //L
      break;
    case 4:
      chooseLetter(12);  //L
      break;
    case 5:
      chooseLetter(15);  //O
      break;
    case 6:
      chooseLetter(23);    //W
      break;
    case 7:
      chooseLetter(15);  //O
      break;
    case 8:
      chooseLetter(18);  //R
      break;
    case 9:
      chooseLetter(12);  //L
      break;
    case 10:
      chooseLetter(4);  //D    
      break;
  }
  
}


void loop(){
  digitalWrite(latchPin, LOW);
  for(int i = 0; i < 8; i++){
   shiftOut(dataPin, clockPin, MSBFIRST, pinVals[i]);
  }
  digitalWrite(latchPin, HIGH);

  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      bitClear(pinVals[i], j);
    }
  }
  
  //chooseLetter(num);
  helloWorld(num);
  num++;
  if(num > 10){
    num = 1;
  }

  /*letterA();

  digitalWrite(zLayer, HIGH);
  zLayer++;
  if(zLayer > 9){
    zLayer = 2;
  }

  delay(100);*/
   

}
