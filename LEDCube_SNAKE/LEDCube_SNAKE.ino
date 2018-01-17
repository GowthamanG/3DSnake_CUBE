//Test an 8x8x8 LED cube

 //LEDS DIE NICHT FUNKTIOIEREN: x = 2, y = 1, z = 0; x = 1, y = 3, z  = 4; x = 0, y = 2, z = 7; x = 4, y = 4, z = 7
 
//--- Pin connected to ST_CP of 74HC595
int latchPin = 10;
//--- Pin connected to SH_CP of 74HC595
int clockPin = 13;
//--- Pin connected to DS of 74HC595
int dataPin = 11;

// Pin connected to the Button to change the height
int buttonPinUp = 12;
int buttonStateUp = 0;
int buttonPinDown = A5;
int buttonStateDown = 0;
 
byte pinVals[8];
//int zLayer = 1;
//int xc = 2;
//int yc = 7;


const int sw_pin = 1;
const int x_pin = 0;
const int y_pin = 1;

typedef struct Led{
  int x, y, z;
}Led;

typedef struct LedList{
  Led* head;
}LedList;

//Snake
int lastInput;
int head;
int tail;
int bodyLength;
int direction;

Led* led1;
led1->x = 2;
led1->y = 7;
led1->z = 1;

void light (int x, int y, int z){
  led1->x = x;
  led1->y = y;
  led1->z = z;
  digitalWrite(led1->z, LOW);
  
}


void controlLight(int x_axe, int y_axe, int x, int y, int z){
  if(y_axe < 10){
    x--;
    if(x < 0){
      x = 7;
    }
    light(x, y, z);
  }else if(y_axe > 1000){
    x++;
    if(x > 7){
      x = 0;
    }
    light(x, y, z);
  }else if(x_axe < 10){
    y++;
    if(y > 7){
      y = 0;
    }
    light(x, y, z);
  }else if(x_axe > 1000){
    y--;
    if(y < 0){
      y = 7;
    }
    light(x, y, z);
  }
}

// Lights a random LED, use this for the apple
void randomLight(){
  //digitalWrite(zLayer, HIGH);
  //bitClear(pinVals[yc], xc);
  light(random(8), random(8), random(2, 10));
}

void flowLight(){
  xc++;
  if(xc > 7)
    xc = 0;
  bitSet(pinVals[led1->y], led1->x);
}

//Snake goes up while Button is pressed
void buttonPressed(int x, int y, int z){
  buttonStateUp = digitalRead(buttonPinUp);
  buttonStateDown = digitalRead(buttonPinDown);
  if (buttonStateUp == HIGH){
    digitalWrite(z, HIGH);
    z++;
    if(z > 9){
    z = 2;
    }
    light(x, y, z);
  }
  else if (buttonStateDown == HIGH){
    digitalWrite(z, HIGH);
    z--;
    if(z < 2){
      z = 9;
    }
    light(x, y, z);
  } else{
    light(x, y, z);
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

  pinMode(buttonPinUp, INPUT); //Button Up
  pinMode(buttonPinDown, INPUT); // Button Down
  
  light(led1->x, led1->y,led1->z);
}



void loop(){
  digitalWrite(latchPin, LOW);
  for(int i = 0; i < 8; i++){
   shiftOut(dataPin, clockPin, MSBFIRST, pinVals[i]);
  }
  digitalWrite(latchPin, HIGH);

  buttonPressed(led1->x, led1->y, led1->z); //Check if a button is pressed, if it is pressed Snake goes up or down
 
  //Increase for slower effect
  //randomLight();
  //delay(500);
 
  //Set the display bits
  bitClear(pinVals[led1->y], led1->x);

  //light(xc,yc,zLayer);
  //basic();
  controlLight(analogRead(x_pin), analogRead(y_pin), led1->x, led1->y, led1->z);

  //flowLight();
  //delay(50);
  
  bitSet(pinVals[led1->y], led1->x);
  
  delay(100);
}
