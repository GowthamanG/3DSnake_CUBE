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

/*int xc3 = 2;
int yc3 = 5;

int xc4 = 2;
int yc4 = 4;

int xc5 = 2;
int yc5 = 3;

int xc6 = 2;
int yc6 = 2;*/


const int sw_pin = 1;
const int x_pin = 0;
const int y_pin = 1;

boolean UP, DOWN, LEFT, RIGHT, UPRIGHT, RIGHTUP, DOWNRIGHT, RIGHTDOWN, UPLEFT, LEFTUP, DOWNLEFT, LEFTDOWN;

//defining led lights,each with x and y coordinate
typedef struct Led{
  int x;
  int y;
  //boolean UP, DOWN, LEFT, RIGHT, UPRIGHT, RIGHTUP, DOWNRIGHT, RIGHTDOWN, UPLEFT, LEFTUP, DOWNLEFT, LEFTDOWN;
}Led;

Led snake [50];

int listCounter;

Led apple;


void light (int x, int y, int z){
  xc = x;
  yc = y;
  zLayer = z;
  digitalWrite(zLayer, LOW);
}


/*
 * By changing the movement, the whole of the snake should follow the direction. Each led light should
 * be checked in which direction they have to move on. For each led should the direction, in where it moved, be saved as boolean.
 * So every led have just to check, which way his precursor covered before and follow that way. 
 */
void moveSnakeBody(Led snake[], int counter){
  int head = 0;

  for(int i = head; i < counter-2; i++){
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
      snake[counter-1].x--;
      UP = false;
    }else if(DOWN == true){
      snake[counter-1].x++;
      DOWN = false;
    }else if(LEFT == true){
      snake[counter-1].y++;
      LEFT = false;
    }else if(RIGHT == true){
      snake[counter-1].y--;
      RIGHT = false;
    }else if(UPRIGHT == true){
      snake[counter-1].x--;
      UPRIGHT = false;
    }else if(RIGHTUP == true){
      snake[counter-1].y--;
      RIGHTUP = false;
    }else if(DOWNRIGHT == true){
      snake[counter-1].x++;
      DOWNRIGHT = false;
    }else if(RIGHTDOWN == true){
      snake[counter-1].y--;
      RIGHTDOWN = false;
    }else if(UPLEFT == true){
      snake[counter-1].x--;
      UPLEFT= false;
    }else if(LEFTUP == true){
      snake[counter-1].y++;
      LEFTUP = false;
    }else if(DOWNLEFT == true){
      snake[counter-1].x++;
      DOWNLEFT = false;
    }else if(LEFTDOWN == true){
      snake[counter-1].y++;
      LEFTDOWN = false;
    }
}

/*
 * Changes direction by moving the joystick. 
 */
void changeDirection(int x_axe, int y_axe, Led list[], int counter){
  int head = 0;
  
  if(y_axe > 1000){  //Down
    
    if(list[head].y > list[head+1].y){
      list[head].x++;
      LEFTDOWN = true;
    }else if(list[head].y < list[head+1].y){
      list[head].x++;
      RIGHTDOWN = true;
    }else if(list[head].y == list[head+1].y){
      list[head].x++;
      DOWN = true;
    }
    
    moveSnakeBody(list, counter);

   //If the snake move toward a side of the cube, it will come out from the other side. 
    for(int i = 0; i < counter; i++){
      if(list[i].x > 7){
        list[i].x = 0;
      } 
    }
    light(list[head].x, list[head].y, zLayer);
    
  }else if(y_axe < 10){ //UP
    
    if(list[head].y > list[head+1].y){
      list[head].x--;
      LEFTUP = true;
    }else if(list[head].y < list[head+1].y){
      list[head].x--;
      RIGHTUP = true;
    }else if(list[head].y == list[head+1].y){
      list[head].x--;
      UP = true;
    }
    
    moveSnakeBody(list, counter);
    
    for(int i = 0; i < counter; i++){
      if(list[i].x < 0){
        list[i].x = 7;
      } 
    }
    light(list[head].x, list[head].y, zLayer);
    
  }else if(x_axe < 10){//LEFT
  
    if(list[head].x > list[head+1].x){
      list[head].y++;
      DOWNLEFT = true;
    }else if(list[head].x < list[head+1].x){
      list[head].y++;
      UPLEFT = true;
    }else if(list[head].x == list[head+1].x){
      list[head].y++;
      LEFT = true;
    }
    
    moveSnakeBody(list, counter);
    
    for(int i = 0; i < counter; i++){
      if(list[i].y > 7){
        list[i].y = 0;
      } 
    }
    light(list[head].x, list[head].y, zLayer);
    
  }else if(x_axe > 1000){ //RIGHT
    
    if(list[head].x > list[head+1].x){
      list[head].y--;
      DOWNRIGHT = true;
    }else if(list[head].x < list[head+1].x){
      list[head].y--;
      UPRIGHT = true;
    }else if(list[head].x == list[head+1].x){
      list[head].y--;
      RIGHT = true;
    }

    
    moveSnakeBody(list, counter);
    
    for(int i = 0; i < counter; i++){
      if(list[i].y < 0){
        list[i].y = 7;
      } 
    }
    light(list[head].x, list[head].y, zLayer);
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
  
  changeDirection(analogRead(x_pin), analogRead(y_pin), snake, listCounter);

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

  apple = randomLight();
  
  

}

void loop(){
  digitalWrite(latchPin, LOW);
  for(int i = 0; i < 8; i++){
   shiftOut(dataPin, clockPin, MSBFIRST, pinVals[i]);
  }
  digitalWrite(latchPin, HIGH);

  buttonPressed(); //Check if a button is pressed, if it is pressed Snake goes up or down

 if(snake[0].x == apple.x && snake[0].y == apple.y){
    if(snake[listCounter-1].x < snake[listCounter-2].x){
      listCounter++;
      snake[listCounter-1] = createLight(snake[listCounter-2].x--, snake[listCounter-2].y);
    }else if(snake[listCounter-1].x > snake[listCounter-2].x){
      listCounter++;
      snake[listCounter-1] = createLight(snake[listCounter-2].x++, snake[listCounter-2].y);
    }else if(snake[listCounter-1].y > snake[listCounter-2].y){
      listCounter++;
      snake[listCounter-1] = createLight(snake[listCounter-2].x, snake[listCounter-2].y--);
    }else if(snake[listCounter-1].y < snake[listCounter-2].y){
      listCounter++;
      snake[listCounter-1] = createLight(snake[listCounter-2].x, snake[listCounter-2].y++);;
    }
    apple = randomLight();
  }
  
  //Set the display bits
  setBit(snake, listCounter, apple);

/*
  Serial.print("Switch:  ");
  Serial.print(digitalRead(sw_pin));
  Serial.print("\n");
  Serial.print("X-axis: ");
  Serial.print(analogRead(x_pin));
  Serial.print("\n");
  Serial.print("Y-axis: ");
  Serial.println(analogRead(y_pin));
  Serial.print("\n\n");
  */

  
  
  
  delay(100);
  
}
