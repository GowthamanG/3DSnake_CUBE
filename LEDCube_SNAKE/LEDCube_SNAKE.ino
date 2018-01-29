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

/*int xc4 = 2;
int yc4 = 4;

int xc5 = 2;
int yc5 = 3;

int xc6 = 2;
int yc6 = 2;*/


const int sw_pin = 1;
const int x_pin = 0;
const int y_pin = 1;

//to give to the next light in the snake the information, in which direction it moved
boolean UP, DOWN, LEFT, RIGHT, UPRIGHT, RIGHTUP, DOWNRIGHT, RIGHTDOWN, UPLEFT, LEFTUP, DOWNLEFT, LEFTDOWN;

//direction in which the snake actually is moving
boolean dirUP, dirDOWN, dirLEFT, dirRIGHT;

//defining led lights,each with x and y coordinate
typedef struct Led{
  int x;
  int y;
}Led;

Led snake [50];

int listCounter;

Led apple;

int elapsedTime;
bool readInput;
unsigned long previousTime;
int layer;


void light (int x, int y, int z){
  xc = x;
  yc = y;
  zLayer = z;
  digitalWrite(zLayer, LOW);
}

Led createLight(int x, int y){
  Led newLed = {x, y};
  return newLed;
}

Led randomLight(){
  int x = random(8);
  int y = random(8);
  int z = random(2, 9);
  Led light = {x, y};
  
  return light;
}

void eatApple(){
  if(snake[0].x == apple.x && snake[0].y == apple.y){
    if(snake[listCounter-1].x < snake[listCounter-2].x){
      Led newLED = createLight(snake[listCounter-1].x--, snake[listCounter-1].y);
      listCounter++;
      snake[listCounter-1] = newLED;
    }else if(snake[listCounter-1].x > snake[listCounter-2].x){
      Led newLED = createLight(snake[listCounter-1].x++, snake[listCounter-1].y);
      listCounter++;
      snake[listCounter-1] = newLED;
    }else if(snake[listCounter-1].y > snake[listCounter-2].y){
      Led newLED = createLight(snake[listCounter-1].x, snake[listCounter-1].y--);
      listCounter++;
      snake[listCounter-1] = newLED;
    }else if(snake[listCounter-1].y < snake[listCounter-2].y){
      Led newLED = createLight(snake[listCounter-1].x, snake[listCounter-1].y++);
      listCounter++;
      snake[listCounter-1] = newLED;
    }

    digitalWrite(zLayer, HIGH);
    zLayer++;
    if(zLayer > 9){
      zLayer = 2;
    } 
    digitalWrite(zLayer, LOW);
    
    moveSnakeBody();
    apple = randomLight();
    bitSet(pinVals[apple.y], apple.x);
  }
}

void moveUp(){
  int head = 0;
  
  if(snake[head].y > snake[head+1].y){
    snake[head].x--;
    LEFTUP = true;
  }else if(snake[head].y < snake[head+1].y){
    snake[head].x--;
    RIGHTUP = true;
  }else if(snake[head].y == snake[head+1].y){
    snake[head].x--;
    UP = true;
  }
    
  moveSnakeBody();
  
  for(int i = 0; i < listCounter; i++){
    if(snake[i].x < 0){
      snake[i].x = 7;
    }
    moveSnakeBody(); 
  }
  
  //light(snake[head].x, snake[head].y, zLayer);
}

void moveDown(){

  int head = 0;
  
  if(snake[head].y > snake[head+1].y){
    snake[head].x++;
    LEFTDOWN = true;
  }else if(snake[head].y < snake[head+1].y){
    snake[head].x++;
    RIGHTDOWN = true;
  }else if(snake[head].y == snake[head+1].y){
    snake[head].x++;
    DOWN = true;
  }
    
  moveSnakeBody();

  for(int i = 0; i < listCounter; i++){
    if(snake[i].x > 7){
      snake[i].x = 0;
    }
    moveSnakeBody(); 
  }
  //light(snake[head].x, snake[head].y, zLayer);
}

void moveRight(){
  int head = 0;
  
  if(snake[head].x > snake[head+1].x){
    snake[head].y--;
    DOWNRIGHT = true;
  }else if(snake[head].x < snake[head+1].x){
    snake[head].y--;
    UPRIGHT = true;
  }else if(snake[head].x == snake[head+1].x){
    snake[head].y--;
    RIGHT = true;
  }
    
  moveSnakeBody();

  for(int i = 0; i < listCounter; i++){
    if(snake[i].y < 0){
      snake[i].y = 7;
    }
    moveSnakeBody(); 
  }
  
  //light(snake[head].x, snake[head].y, zLayer);
}

void moveLeft(){
  int head = 0;
  
  if(snake[head].x > snake[head+1].x){
    snake[head].y++;
    DOWNLEFT = true;
  }else if(snake[head].x < snake[head+1].x){
    snake[head].y++;
    UPLEFT = true;
  }else if(snake[head].x == snake[head+1].x){
    snake[head].y++;
    LEFT = true;
  }
    
  moveSnakeBody();

  for(int i = 0; i < listCounter; i++){
    if(snake[i].y > 7){
      snake[i].y = 0;
    }
    moveSnakeBody(); 
  }
  
  //light(snake[head].x, snake[head].y, zLayer);  
}


/*
 * By changing the movement, the whole of the snake should follow the direction. Each led light should
 * be checked in which direction they have to move on. For each led should the direction, in where it moved, be saved as boolean.
 * So every led have just to check, which way his precursor covered before and follow that way. 
 */
void moveSnakeBody(){
  int head = 0;

  for(int i = head; i < listCounter-2; i++){
      if(UP == true){
        snake[i+1].x--;
        UP = false;
        if(snake[i+1].y > snake[i+2].y){
          LEFTUP = true;
        }else if(snake[i+1].y < snake[i+2].y){
          RIGHTUP = true;
        }else if(snake[i+1].y == snake[i+2].y){
          UP = true;
        }
      }else if(DOWN == true){
        snake[i+1].x++;
        DOWN = false;
        if(snake[i+1].y > snake[i+2].y){
          LEFTDOWN = true;
        }else if(snake[i+1].y < snake[i+2].y){
          RIGHTDOWN = true;
        }else if(snake[i+1].y == snake[i+2].y){
          DOWN = true;
        }
      }else if(LEFT == true){
        snake[i+1].y++;
        LEFT = false;
        if(snake[i+1].x > snake[i+2].x){
          DOWNLEFT = true;
        }else if(snake[i+1].x < snake[i+2].x){
          UPLEFT = true;
        }else if(snake[i+1].x == snake[i+2].x){
          LEFT = true;
        }
      }else if(RIGHT == true){
        snake[i+1].y--;
        RIGHT = false;
        if(snake[i+1].x > snake[i+2].x){
          DOWNRIGHT = true;
        }else if(snake[i+1].x < snake[i+2].x){
          UPRIGHT = true;
        }else if(snake[i+1].x == snake[i+2].x){
          RIGHT = true;
        }
      }else if(UPRIGHT == true){
        snake[i+1].x--;
        UPRIGHT = false;
        if(snake[i+1].y > snake[i+2].y){
          LEFTUP = true;
        }else if(snake[i+1].y < snake[i+2].y){
          RIGHTUP = true;
        }else if(snake[i+1].y == snake[i+2].y){
          UP = true;
        }
      }else if(RIGHTUP == true){
        snake[i+1].y--;
        RIGHTUP = false;
        if(snake[i+1].x > snake[i+2].x){
          DOWNRIGHT = true;
        }else if(snake[i+1].x < snake[i+2].x){
          UPRIGHT = true;
        }else if(snake[i+1].x == snake[i+2].x){
          RIGHT = true;
        }
      }else if(DOWNRIGHT == true){
        snake[i+1].x++;
        DOWNRIGHT = false;
        if(snake[i+1].y > snake[i+2].y){
          LEFTDOWN = true;
        }else if(snake[i+1].y < snake[i+2].y){
          RIGHTDOWN = true;
        }else if(snake[i+1].y == snake[i+2].y){
          DOWN = true;
        }
      }else if(RIGHTDOWN == true){
        snake[i+1].y--;
        RIGHTDOWN = false;
        if(snake[i+1].x > snake[i+2].x){
          DOWNRIGHT = true;
        }else if(snake[i+1].x < snake[i+2].x){
          UPRIGHT = true;
        }else if(snake[i+1].x == snake[i+2].x){
          RIGHT = true;
        }
      }else if(UPLEFT == true){
        snake[i+1].x--;
        UPLEFT = false;
        if(snake[i+1].y > snake[i+2].y){
          LEFTUP = true;
        }else if(snake[i+1].y < snake[i+2].y){
          RIGHTUP = true;
        }else if(snake[i+1].y == snake[i+2].y){
          UP = true;
        }   
      }else if(LEFTUP == true){
        snake[i+1].y++;
        LEFTUP = false;
        if(snake[i+1].x > snake[i+2].x){
          DOWNLEFT = true;
        }else if(snake[i+1].x < snake[i+2].x){
          UPLEFT = true;
        }else if(snake[i+1].x == snake[i+2].x){
          LEFT = true;
        }
      }else if(DOWNLEFT == true){
        snake[i+1].x++;
        DOWNLEFT = false;
        if(snake[i+1].y > snake[i+2].y){
          LEFTDOWN = true;
        }else if(snake[i+1].y < snake[i+2].y){
          RIGHTDOWN = true;
        }else if(snake[i+1].y == snake[i+2].y){
          DOWN = true;
        }
      }else if(LEFTDOWN == true){
        snake[i+1].y++;
        LEFTDOWN = false;
        if(snake[i+1].x > snake[i+2].x){
          DOWNLEFT = true;
        }else if(snake[i+1].x < snake[i+2].x){
          UPLEFT = true;
        }else if(snake[i+1].x == snake[i+2].x){
          LEFT = true;
        }
      }
    }

//The following if-else statement is important to move the last led of the list because the loop before goes until the second
//last of the list.

    if(UP == true){
      snake[listCounter-1].x--;
      UP = false;
    }else if(DOWN == true){
      snake[listCounter-1].x++;
      DOWN = false;
    }else if(LEFT == true){
      snake[listCounter-1].y++;
      LEFT = false;
    }else if(RIGHT == true){
      snake[listCounter-1].y--;
      RIGHT = false;
    }else if(UPRIGHT == true){
      snake[listCounter-1].x--;
      UPRIGHT = false;
    }else if(RIGHTUP == true){
      snake[listCounter-1].y--;
      RIGHTUP = false;
    }else if(DOWNRIGHT == true){
      snake[listCounter-1].x++;
      DOWNRIGHT = false;
    }else if(RIGHTDOWN == true){
      snake[listCounter-1].y--;
      RIGHTDOWN = false;
    }else if(UPLEFT == true){
      snake[listCounter-1].x--;
      UPLEFT= false;
    }else if(LEFTUP == true){
      snake[listCounter-1].y++;
      LEFTUP = false;
    }else if(DOWNLEFT == true){
      snake[listCounter-1].x++;
      DOWNLEFT = false;
    }else if(LEFTDOWN == true){
      snake[listCounter-1].y++;
      LEFTDOWN = false;
    }
}

void onTheMove(){
  int head = 0;

  if(dirDOWN == true){
    moveDown();
  }else if(dirUP == true){
    moveUp();
  }else if(dirLEFT == true){
    moveLeft();
  }else if(dirRIGHT == true){
    moveRight();
  }
  eatApple();
}

/*
 * Changes direction by moving the joystick. 
 */
void changeDirection(int x_axe, int y_axe){
  int head = 0;
  
  if(y_axe > 1000){//Down

    dirDOWN = true;
    dirUP = false;
    dirLEFT = false;
    dirRIGHT = false;
    

    moveDown();
    
  }else if(y_axe < 10){ //UP

    dirUP = true;
    dirDOWN = false;
    dirLEFT = false;
    dirRIGHT = false;

    moveUp();
    
  }else if(x_axe < 10){//LEFT

    dirLEFT = true;
    dirUP = false;
    dirDOWN = false;
    dirRIGHT = false;

    moveLeft();
    
  }else if(x_axe > 1000){ //RIGHT

    dirRIGHT = true;
    dirUP = false;
    dirLEFT = false;
    dirDOWN = false;
    
    moveRight();
  }

  eatApple();
}

// Lights a random LED, use this for the apple


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
  /*Led led3 = {xc3, yc3};
  listCounter++;
  Led led4 = {xc4, yc4};
  listCounter++;
  Led led5 = {xc5, yc5};
  listCounter++;
  Led led6 = {xc6, yc6};
  listCounter++;*/

  snake[0] = led1;
  snake[1] = led2;
  /*snake[2] = led3;
  snake[3] = led4;
  snake[4] = led5;
  snake[5] = led6;*/

  dirUP = false; 
  dirDOWN = false; 
  dirLEFT = true; 
  dirRIGHT = false;

  apple = randomLight();
  
  digitalWrite(zLayer, LOW);

  bitClear(pinVals[apple.y], apple.x);
  bitSet(pinVals[apple.y], apple.x);
}


void loop(){
  digitalWrite(latchPin, LOW);
  for(int i = 0; i < 8; i++){
   shiftOut(dataPin, clockPin, MSBFIRST, pinVals[i]);
  }
  digitalWrite(latchPin, HIGH);

  buttonPressed(); //Check if a button is pressed, if it is pressed Snake goes up or down

  unsigned long currentTime = millis();
  elapsedTime += currentTime - previousTime;

  if(zLayer == 2){
    if(elapsedTime > 300){
      for(int i = 0; i < listCounter; i++){
        bitClear(pinVals[snake[i].y], snake[i].x);
      }
      onTheMove();
      elapsedTime = 0;
      readInput = true;
    
      for(int i = 0; i < listCounter; i++){
        bitSet(pinVals[snake[i].y], snake[i].x);
      }
    }
  }else if(zLayer == 3){
    if(elapsedTime > 290){
      for(int i = 0; i < listCounter; i++){
        bitClear(pinVals[snake[i].y], snake[i].x);
      }
      onTheMove();
      elapsedTime = 0;
      readInput = true;
    
      for(int i = 0; i < listCounter; i++){
        bitSet(pinVals[snake[i].y], snake[i].x);
      }
    }
  }else if(zLayer == 4){
    if(elapsedTime > 280){
      for(int i = 0; i < listCounter; i++){
        bitClear(pinVals[snake[i].y], snake[i].x);
      }
      onTheMove();
      elapsedTime = 0;
      readInput = true;
    
      for(int i = 0; i < listCounter; i++){
        bitSet(pinVals[snake[i].y], snake[i].x);
      }
    }
  }else if(zLayer == 5){
    if(elapsedTime > 270){
      for(int i = 0; i < listCounter; i++){
        bitClear(pinVals[snake[i].y], snake[i].x);
      }
      onTheMove();
      elapsedTime = 0;
      readInput = true;
    
      for(int i = 0; i < listCounter; i++){
        bitSet(pinVals[snake[i].y], snake[i].x);
      }
    }
  }else if(zLayer == 6){
    if(elapsedTime > 260){
      for(int i = 0; i < listCounter; i++){
        bitClear(pinVals[snake[i].y], snake[i].x);
      }
      onTheMove();
      elapsedTime = 0;
      readInput = true;
    
      for(int i = 0; i < listCounter; i++){
        bitSet(pinVals[snake[i].y], snake[i].x);
      }
    }
  }else if(zLayer == 7){
    if(elapsedTime > 250){
      for(int i = 0; i < listCounter; i++){
        bitClear(pinVals[snake[i].y], snake[i].x);
      }
      onTheMove();
      elapsedTime = 0;
      readInput = true;
    
      for(int i = 0; i < listCounter; i++){
        bitSet(pinVals[snake[i].y], snake[i].x);
      }
    }
  }else if(zLayer == 8){
    if(elapsedTime > 240){
      for(int i = 0; i < listCounter; i++){
        bitClear(pinVals[snake[i].y], snake[i].x);
      }
      onTheMove();
      elapsedTime = 0;
      readInput = true;
    
      for(int i = 0; i < listCounter; i++){
        bitSet(pinVals[snake[i].y], snake[i].x);
      }
    }
  }else if(zLayer == 9){
    if(elapsedTime > 230){
      for(int i = 0; i < listCounter; i++){
        bitClear(pinVals[snake[i].y], snake[i].x);
      }
      onTheMove();
      elapsedTime = 0;
      readInput = true;
    
      for(int i = 0; i < listCounter; i++){
        bitSet(pinVals[snake[i].y], snake[i].x);
      }
    }
  }

  if(readInput){
    
    for(int i = 0; i < listCounter; i++){
      bitClear(pinVals[snake[i].y], snake[i].x);
    }

    changeDirection(analogRead(x_pin), analogRead(y_pin));
    readInput = false;
    
    
    for(int i = 0; i < listCounter; i++){
      bitSet(pinVals[snake[i].y], snake[i].x);
    }
  }

  previousTime = currentTime;

  /*//Gameover
  for(int i = 1; i < listCounter; i++){
    if(snake[0].x == snake[i].x && snake[0].y == snake[i].y){
      while(1);
    }
  }*/

}
