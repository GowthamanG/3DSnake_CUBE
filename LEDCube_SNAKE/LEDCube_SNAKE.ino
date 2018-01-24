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
int zLayer = 2;
int xc = 2;
int yc = 7;

int xc2 = 2;
int yc2 = 6;

int xc3 = 2;
int yc3 = 5;

int xc4 = 2;
int yc4 = 4;

int xc5 = 2;
int yc5 = 3;


const int sw_pin = 1;
const int x_pin = 0;
const int y_pin = 1;

typedef struct Led{
  int x;
  int y;
}Led;

Led snake [100];

int listCounter;

Led apple;


void light (int x, int y, int z){
  xc = x;
  yc = y;
  zLayer = z;
  digitalWrite(zLayer, LOW);
}

void controlLight(int x_axe, int y_axe, Led list[], int counter){
  if(y_axe < 10){
    for(int i = 0; i < counter; i++){
      snake[i].x--;
    }
    for(int i = 0; i < counter; i++){
      if(snake[i].x < 0){
        snake[i].x = 7;
      } 
    }
    light(snake[0].x, snake[0].y, zLayer);
  }else if(y_axe > 1000){
    for(int i = 0; i < counter; i++){
      snake[i].x++;
    }
    for(int i = 0; i < counter; i++){
      if(snake[i].x > 7){
        snake[i].x = 0;
      } 
    }
    light(snake[0].x, snake[0].y, zLayer);
  }else if(x_axe < 10){
    for(int i = 0; i < counter; i++){
      snake[i].y++;
    }
    for(int i = 0; i < counter; i++){
      if(snake[i].y > 7){
        snake[i].y = 0;
      } 
    }
    light(snake[0].x, snake[0].y, zLayer);
  }else if(x_axe > 1000){
    for(int i = 0; i < counter; i++){
      snake[i].y--;
    }
    for(int i = 0; i < counter; i++){
      if(snake[i].y < 0){
        snake[i].y = 7;
      } 
    }
    light(snake[0].x, snake[0].y, zLayer);
  }
}

// Lights a random LED, use this for the apple
Led randomLight(){
  int x = random(8);
  int y = random(8);
  int z = random(2, 9);
  Led light = {x, y};
  
  return light;
}

void flowLight(){
  xc++;
  if(xc > 7)
    xc = 0;
  bitSet(pinVals[yc], xc);
}

//Snake goes up while Button is pressed
void buttonPressed(){
  buttonStateUp = digitalRead(buttonPinUp);
  buttonStateDown = digitalRead(buttonPinDown);
  digitalWrite(zLayer, HIGH);
  if (buttonStateUp == HIGH){                   //Knopf Hoch, Blauer Knopf
    zLayer++;
    if(zLayer > 9){
    zLayer = 2;
    }
  }
  else if (buttonStateDown == HIGH){    //Knopf runter: Gelber Knopf
    zLayer--;
    if(zLayer < 2){
      zLayer = 9;
    }
  } 
  for(int i = 0; i < listCounter; i++){
    light(snake[i].x, snake[i].y , zLayer);
  }
  
}

void setBit(Led list[], int counter, Led apple){
  for(int i = 0; i < counter; i++){
    bitClear(pinVals[snake[i].y], snake[i].x);
  }
  bitClear(pinVals[apple.y], apple.x);
  
  controlLight(analogRead(x_pin), analogRead(y_pin), snake, listCounter);

  for(int i = 0; i < counter; i++){
    bitSet(pinVals[snake[i].y], snake[i].x);
  }
  bitSet(pinVals[apple.y], apple.x);
  
}

Led createLight(int x, int y){
  Led newLed = {x, y};
  return newLed;
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

  Led led1 = {xc, yc};
  listCounter++;
  Led led2 = {xc2, yc2};
  listCounter++;
  Led led3 = {xc3, yc3};
  listCounter++;
  Led led4 = {xc4, yc4};
  listCounter++;
  Led led5 = {xc5, yc5};
  listCounter++;

  snake[0] = led1;
  snake[1] = led2;
  snake[2] = led3;
  snake[3] = led4;
  snake[4] = led5;

  apple = randomLight();
  if(snake[0].x == apple.x && snake[0].y == apple.y){
    listCounter++;
    if(snake[0].x == snake[1].x){
      snake[listCounter] = createLight(snake[listCounter-1].x, snake[listCounter-1].y--);
    }else if(snake[0].y == snake[1].y){
      snake[listCounter] = createLight(snake[listCounter-1].x--, snake[listCounter-1].y);
    }
    apple = randomLight();
  }

}

void loop(){
  digitalWrite(latchPin, LOW);
  for(int i = 0; i < 8; i++){
   shiftOut(dataPin, clockPin, MSBFIRST, pinVals[i]);
  }
  digitalWrite(latchPin, HIGH);

  buttonPressed(); //Check if a button is pressed, if it is pressed Snake goes up or down
 
  //Set the display bits
  setBit(snake, listCounter, apple);

  Serial.print("Switch:  ");
  Serial.print(digitalRead(sw_pin));
  Serial.print("\n");
  Serial.print("X-axis: ");
  Serial.print(analogRead(x_pin));
  Serial.print("\n");
  Serial.print("Y-axis: ");
  Serial.println(analogRead(y_pin));
  Serial.print("\n\n");
  
  delay(100);
  
}
