
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

typedef struct LED{
  int x, y, z;
  LED* next;
}LED;

typedef struct LEDList{
  LED* head;
  LED* tail;
  int length;
}LEDList;

//Snake
int lastInput;
int head;
int tail;
int bodyLength;
int direction;

LED* firstLight;
LEDList* list;

LED createLED(int x, int y, int z, LEDList list){
  LED* newLED;
  newLED->x = x;
  newLED->y = y;
  newLED->z = z;  

  pushOnList(newLED, &list);

  return *newLED;
}

void pushOnList(LED* led, LEDList* list){
  if(list->head == NULL && list->tail == NULL){
    list->head = head;
    list->head->next = list->tail;
  }else{
  }
  list->length += 1;
}

void light (int x, int y, int z, LEDList* list){
  list->head->x = x;
  list->head->y = y;
  list->head->z = z;
  digitalWrite(list->head->z, LOW);
  
}

/*Enable to control LED light left, right, forward and backward*/
void controlLight(int x_axe, int y_axe, LEDList* list){
  int x = list->head->x;
  int y = list->head->y;
  int z = list->head->z;
  if(y_axe < 10){
    x--;
    if(x < 0){
      x = 7;
    }
    light(x, y, z, list);
  }else if(y_axe > 1000){
    x++;
    if(x > 7){
      x = 0;
    }
    light(x, y, z, list);
  }else if(x_axe < 10){
    y++;
    if(y > 7){
      y = 0;
    }
    light(x, y, z, list);
  }else if(x_axe > 1000){
    y--;
    if(y < 0){
      y = 7;
    }
    light(x, y, z, list);
  }
}

// Lights a random LED, use this for the apple
void randomLight(){
  //digitalWrite(zLayer, HIGH);
  //bitClear(pinVals[yc], xc);
  light(random(8), random(8), random(2, 10), list);
}

/*
void flowLight(){
  led1->x += 1;;
  if(led1->x > 7)
    led1->x = 0;
  bitSet(pinVals[led1->y], led1->x);
}*/

//Snake goes up while Button is pressed
void buttonPressed(LEDList* list){
  int x = list->head->x;
  int y = list->head->y;
  int z = list->head->z;
  buttonStateUp = digitalRead(buttonPinUp);
  buttonStateDown = digitalRead(buttonPinDown);
  if (buttonStateUp == HIGH){
    digitalWrite(z, HIGH);
    z++;
    if(z > 9){
    z = 2;
    }
    light(x, y, z, list);
  }
  else if (buttonStateDown == HIGH){
    digitalWrite(z, HIGH);
    z--;
    if(z < 2){
      z = 9;
    }
    light(x, y, z, list);
  } else{
    light(x, y, z, list);
  }
  
}

LED createApple(){

  LED* apple;
  int x = random(8);
  int y = random(8);
  int z = random(2,10);
  
  digitalWrite(apple->z, LOW);
  bitSet(pinVals[apple->y], apple->x);

  return *apple;
}

void eatApple();

void StopGame();

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
  
  *firstLight = createLED(0, 0, 0, *list);
  
  light(list->head->x, list->head->y, list->head->z, list);
}



void loop(){
  digitalWrite(latchPin, LOW);
  for(int i = 0; i < 8; i++){
   shiftOut(dataPin, clockPin, MSBFIRST, pinVals[i]);
  }
  digitalWrite(latchPin, HIGH);

  buttonPressed(list); //Check if a button is pressed, if it is pressed Snake goes up or down
 
  //Increase for slower effect
  //randomLight();
  //delay(500);
 
  //Set the display bits
  bitClear(pinVals[list->head->y], list->head->x);

  //light(xc,yc,zLayer);
  //basic();
  controlLight(analogRead(x_pin), analogRead(y_pin), list);

  //flowLight();
  //delay(50);
  
  bitSet(pinVals[list->head->y], list->head->x);
  
  delay(100);
}
