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
  }
}

void loop(){
  digitalWrite(latchPin, LOW);
  for(int i = 0; i < 8; i++){
   shiftOut(dataPin, clockPin, MSBFIRST, pinVals[i]);
  }
  digitalWrite(latchPin, HIGH);
 
  //Increase for slower effect
  //delay(1000);
 
  //Set the display bits
  bitClear(pinVals[yc], xc);

  //light(xc,yc,zLayer);
  //basic();
  controlLight(analogRead(x_pin), analogRead(y_pin));
  
  
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
