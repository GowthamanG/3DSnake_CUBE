//Test an 8x8x8 LED cube

 //LEDS DIE NICHT FUNKTIOIEREN: x = 2, y = 1, z = 0; x = 1, y = 3, z  = 4; x = 0, y = 2, z = 7; x = 4, y = 4, z = 7
 
//--- Pin connected to ST_CP of 74HC595
int latchPin = 10;
//--- Pin connected to SH_CP of 74HC595
int clockPin = 13;
//--- Pin connected to DS of 74HC595
int dataPin = 11;
 
byte pinVals[8];
int zLayer = 2;
int xc = 4;
int yc = 7;

const int sw_pin = 1;
const int x_pin = 0;
const int y_pin = 1;


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

  pinMode(sw_pin, INPUT_PULLUP);
  pinMode(x_pin, INPUT);
  pinMode(y_pin, INPUT);
  Serial.begin(9600);
 
  digitalWrite(latchPin,LOW);
  digitalWrite(dataPin,LOW);
  digitalWrite(clockPin,LOW);
 
  bitSet(pinVals[0], 0);
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);

  light(xc,yc,zLayer);
}

void basic(){
  //digitalWrite(zLayer, HIGH);
        //zLayer++;
        //if(zLayer == 10){
        //  zLayer = 2;
        //}
        //digitalWrite(zLayer, LOW);
  xc++;
  if(xc == 8){
    xc = 0;
    yc++;
    if(yc == 8){
      yc = 0;
      
        
    }
  }
}

void showLedNumbers(int number){
  switch(number){
    case 0: 
      light(0, 1, 0);
      light(0, 2, 0);
      light(0, 3, 0);
      light(0, 4, 0);
      light(0, 5, 0);
      light(0, 6, 0);
      light(0, 1, 1);
      light(0, 1, 2);
      light(0, 1, 3);
      light(0, 1, 4);
      light(0, 1, 5);
      light(0, 1, 6);
      light(0, 1, 7);
      light(0, 6, 1);
      light(0, 6, 2);
      light(0, 6, 3);
      light(0, 6, 4);
      light(0, 6, 5);
      light(0, 6, 6);
      light(0, 6, 7);
      light(0, 5, 7);
      light(0, 4, 7);
      light(0, 3, 7);
      light(0, 2, 7);
      light(0, 1, 7);
      light(0, 3, 5);
      light(0, 4, 5);
      light(0, 5, 5);
      light(0, 3, 4);
      light(0, 3, 3);
      light(0, 3, 2);
      light(0, 5, 4);
      light(0, 5, 3);
      light(0, 5, 2);
      light(0, 4, 2);
      /*
      for(int x = 0; x < 8; x++){
        for(int j = 1; j < 7; j++){
          light(x, j, 0);
          light(x, 6, j);
          light(x, j, 7);
        }
        for(int k = 1; k < 8; k++)
          light(x,1,k);
        for(int l = 3; l < 6; l++){
          light(x, l, 5);
          light(x, 3, l-1);
          light(x, 5, l-1);
        }
        light(x, 4, 2);
      delay(500);
      bitClear(pinVals[yc], xc);
      }
      */
      break;
    case 1: break; 
    case 2: break;
    case 3: break;
    case 4: break;
    case 5: break;
    case 6: break;
    case 7: break;
    case 8: break;
    case 9: break;
  }
}

void light (int x, int y, int z){
  xc = x;
  yc = y;
  zLayer = z;
  digitalWrite(zLayer, LOW);
  
}

void controlLight(int x_axe, int y_axe){
  if(y_axe == 0){
    digitalWrite(zLayer, HIGH);
    zLayer++;
    if(zLayer > 9){
    zLayer = 2;
    }
    light(xc, yc, zLayer);
  }else if(y_axe == 1023){
    digitalWrite(zLayer, HIGH);
    zLayer--;
    if(zLayer < 2){
    zLayer = 9;
    }
    light(xc, yc, zLayer);
  }else if(x_axe == 0){
    yc++;
    if(yc > 7){
      yc = 0;
    }
    light(xc, yc, zLayer);
  }else if(x_axe == 1023){
    yc--;
    if(yc < 0){
      yc = 7;
    }
    light(xc, yc, zLayer);
  }
}

void randomLight(){
  //digitalWrite(zLayer, HIGH);
  //bitClear(pinVals[yc], xc);
  light(random(8), random(8), random(2, 10));
}

void flowLight(){
  xc++;
  if(xc > 7)
    xc = 0;
  bitSet(pinVals[yc], xc);
}

void loop(){
  digitalWrite(latchPin, LOW);
  for(int i = 0; i < 8; i++){
   shiftOut(dataPin, clockPin, MSBFIRST, pinVals[i]);
  }
  digitalWrite(latchPin, HIGH);
 
  //Increase for slower effect
  //randomLight();
  //delay(500);
 
  //Set the display bits
  bitClear(pinVals[yc], xc);

  //light(xc,yc,zLayer);
  //basic();
  controlLight(analogRead(x_pin), analogRead(y_pin));

  //flowLight();
  //delay(50);
  
  bitSet(pinVals[yc], xc);

  Serial.print("Switch: ");
  Serial.print(digitalRead(sw_pin));
  Serial.print("\n");
  Serial.print("X-Axis: ");
  Serial.print(analogRead(x_pin));
  Serial.print("\n");
  Serial.print("Y-Axis: ");
  Serial.println(analogRead(y_pin));
  Serial.print("\n\n");
  delay(100);
}
