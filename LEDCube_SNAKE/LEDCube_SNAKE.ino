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

//defining led lights,each with x and y coordinate
typedef struct Led{
  int x;
  int y;
  boolean UP, DOWN, LEFT, RIGHT, UPRIGHT, RIGHTUP, DOWNRIGHT, RIGHTDOWN, UPLEFT, LEFTUP, DOWNLEFT, LEFTDOWN;
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

/*
void moveLight(int x_axe, int y_axe, Led list[], int counter){
  if(y_axe > 1000){  //Down
    int j1 = 0;
    
    if(snake[j1].y > snake[j1+1].y){
      snake[j1].x++;
      snake[j1].LEFTDOWN = true;
    }else if(snake[j1].y < snake[j1+1].y){
      snake[j1].x++;
      snake[j1].RIGHTDOWN = true;
    }else{
      snake[j1].x++;
    }
    
    for(int i = j1; i < counter-1; i++){
      if (snake[i].x > snake[i+1].x && snake[i].y > snake[i+1].y && snake[i].LEFTDOWN == true){
        snake[i+1].y++;
      }else if(snake[i].x > snake[i+1].x && snake[i].y > snake[i+1].y && snake[i].DOWNLEFT == true){
        snake[i+1].x++;
        snake[i].DOWNLEFT = false;
      }else if(snake[i].x < snake[i+1].x && snake[i].y > snake[i+1].y && snake[i].LEFTUP == true){
        snake[i+1].y++;
        snake[i].LEFTUP = false;
      }else if(snake[i].x < snake[i+1].x && snake[i].y > snake[i+1].y && snake[i].UPLEFT == true){
        snake[i+1].x--;
        snake[i].UPLEFT = false;
      }else if(snake[i].x > snake[i+1].x && snake[i].y < snake[i+1].y && snake[i].RIGHTDOWN == true){
        snake[i+1].y--;
        snake[i].RIGHTDOWN = false;
      }else if(snake[i].x > snake[i+1].x && snake[i].y < snake[i+1].y && snake[i].DOWNRIGHT == true){
        snake[i+1].x++;
        snake[i].DOWNRIGHT = false;
      }else if(snake[i].x < snake[i+1].x && snake[i].y < snake[i+1].y && snake[i].RIGHTUP == true){
        snake[i+1].y--;
        snake[i].RIGHTUP = false;
      }else if(snake[i].x < snake[i+1].x && snake[i].y < snake[i+1].y && snake[i].UPRIGHT == true){
        snake[i+1].x--;
        snake[i].UPRIGHT = false;
      }else if(snake[i].x == snake[i+1].x && snake[i].y < snake[i+1].y){
        snake[i+1].y--;
      }else if(snake[i].x == snake[i+1].x && snake[i].y > snake[i+1].y){
        snake[i+1].y++;
      }else if(snake[i].x < snake[i+1].x && snake[i].y == snake[i+1].y){
        snake[i+1].x--;
      }else if(snake[i].x > snake[i+1].x && snake[i].y == snake[i+1].y){
        snake[i+1].x++;
      }
    }
   
    for(int i = 0; i < counter; i++){
      if(snake[i].x < 0){
        snake[i].x = 7;
      } 
    }
    light(snake[0].x, snake[0].y, zLayer);
  }else if(y_axe < 10){ //UP
    int j2 = 0;
    
    if(snake[j2].y > snake[j2+1].y){
      snake[j2].x--;
      snake[j2].LEFTUP = true;
    }else if(snake[j2].y < snake[j2+1].y){
      snake[j2].x--;
      snake[j2].RIGHTUP = true;
    }else{
      snake[j2].x--;
    }
    
    for(int i = j2; i < counter-1; i++){
      if (snake[i].x > snake[i+1].x && snake[i].y > snake[i+1].y && snake[i].LEFTDOWN == true){
        snake[i+1].y++;
      }else if(snake[i].x > snake[i+1].x && snake[i].y > snake[i+1].y && snake[i].DOWNLEFT == true){
        snake[i+1].x++;
        snake[i].DOWNLEFT = false;
      }else if(snake[i].x < snake[i+1].x && snake[i].y > snake[i+1].y && snake[i].LEFTUP == true){
        snake[i+1].y++;
        snake[i].LEFTUP = false;
      }else if(snake[i].x < snake[i+1].x && snake[i].y > snake[i+1].y && snake[i].UPLEFT == true){
        snake[i+1].x--;
        snake[i].UPLEFT = false;
      }else if(snake[i].x > snake[i+1].x && snake[i].y < snake[i+1].y && snake[i].RIGHTDOWN == true){
        snake[i+1].y--;
        snake[i].RIGHTDOWN = false;
      }else if(snake[i].x > snake[i+1].x && snake[i].y < snake[i+1].y && snake[i].DOWNRIGHT == true){
        snake[i+1].x++;
        snake[i].DOWNRIGHT = false;
      }else if(snake[i].x < snake[i+1].x && snake[i].y < snake[i+1].y && snake[i].RIGHTUP == true){
        snake[i+1].y--;
        snake[i].RIGHTUP = false;
      }else if(snake[i].x < snake[i+1].x && snake[i].y < snake[i+1].y && snake[i].UPRIGHT == true){
        snake[i+1].x--;
        snake[i].UPRIGHT = false;
      }else if(snake[i].x == snake[i+1].x && snake[i].y < snake[i+1].y){
        snake[i+1].y--;
      }else if(snake[i].x == snake[i+1].x && snake[i].y > snake[i+1].y){
        snake[i+1].y++;
      }else if(snake[i].x < snake[i+1].x && snake[i].y == snake[i+1].y){
        snake[i+1].x--;
      }else if(snake[i].x > snake[i+1].x && snake[i].y == snake[i+1].y){
        snake[i+1].x++;
      }
    }
    
    for(int i = 0; i < counter; i++){
      if(snake[i].x > 7){
        snake[i].x = 0;
      } 
    }
    light(snake[0].x, snake[0].y, zLayer);
  }else if(x_axe < 10){//LEFT
    int j3 = 0;
  
    if(snake[j3].x > snake[j3+1].x){
      snake[j3].y++;
      snake[j3].DOWNLEFT = true;
    }else if(snake[j3].x < snake[j3+1].x){
      snake[j3].y++;
      snake[j3].UPLEFT = true;
    }else{
      snake[j3].y++;
    }
    
    for(int i = j3; i < counter-1; i++){
      if (snake[i].x > snake[i+1].x && snake[i].y > snake[i+1].y && snake[i].LEFTDOWN == true){
        snake[i+1].y++;
      }else if(snake[i].x > snake[i+1].x && snake[i].y > snake[i+1].y && snake[i].DOWNLEFT == true){
        snake[i+1].x++;
        snake[i].DOWNLEFT = false;
      }else if(snake[i].x < snake[i+1].x && snake[i].y > snake[i+1].y && snake[i].LEFTUP == true){
        snake[i+1].y++;
        snake[i].LEFTUP = false;
      }else if(snake[i].x < snake[i+1].x && snake[i].y > snake[i+1].y && snake[i].UPLEFT == true){
        snake[i+1].x--;
        snake[i].UPLEFT = false;
      }else if(snake[i].x > snake[i+1].x && snake[i].y < snake[i+1].y && snake[i].RIGHTDOWN == true){
        snake[i+1].y--;
        snake[i].RIGHTDOWN = false;
      }else if(snake[i].x > snake[i+1].x && snake[i].y < snake[i+1].y && snake[i].DOWNRIGHT == true){
        snake[i+1].x++;
        snake[i].DOWNRIGHT = false;
      }else if(snake[i].x < snake[i+1].x && snake[i].y < snake[i+1].y && snake[i].RIGHTUP == true){
        snake[i+1].y--;
        snake[i].RIGHTUP = false;
      }else if(snake[i].x < snake[i+1].x && snake[i].y < snake[i+1].y && snake[i].UPRIGHT == true){
        snake[i+1].x--;
        snake[i].UPRIGHT = false;
      }else if(snake[i].x == snake[i+1].x && snake[i].y < snake[i+1].y){
        snake[i+1].y--;
      }else if(snake[i].x == snake[i+1].x && snake[i].y > snake[i+1].y){
        snake[i+1].y++;
      }else if(snake[i].x < snake[i+1].x && snake[i].y == snake[i+1].y){
        snake[i+1].x--;
      }else if(snake[i].x > snake[i+1].x && snake[i].y == snake[i+1].y){
        snake[i+1].x++;
      }
    }
    
    for(int i = 0; i < counter-1; i++){
      if(snake[i].y > 7){
        snake[i].y = 0;
      } 
    }
    light(snake[0].x, snake[0].y, zLayer);
  }else if(x_axe > 1000){ //RIGHT
    int j4 = 0;
    
    if(snake[j4].x > snake[j4+1].x){
      snake[j4].y--;
      snake[j4].DOWNRIGHT = true;
    }else if(snake[j4].x < snake[j4+1].x){
      snake[j4].y--;
      snake[j4].UPRIGHT = true;
    }else{
      snake[j4].y--;
    }

    
    for(int i = j4; i < counter-1; i++){
      if (snake[i].x > snake[i+1].x && snake[i].y > snake[i+1].y && snake[i].LEFTDOWN == true){
        snake[i+1].y++;
      }else if(snake[i].x > snake[i+1].x && snake[i].y > snake[i+1].y && snake[i].DOWNLEFT == true){
        snake[i+1].x++;
        snake[i].DOWNLEFT = false;
      }else if(snake[i].x < snake[i+1].x && snake[i].y > snake[i+1].y && snake[i].LEFTUP == true){
        snake[i+1].y++;
        snake[i].LEFTUP = false;
      }else if(snake[i].x < snake[i+1].x && snake[i].y > snake[i+1].y && snake[i].UPLEFT == true){
        snake[i+1].x--;
        snake[i].UPLEFT = false;
      }else if(snake[i].x > snake[i+1].x && snake[i].y < snake[i+1].y && snake[i].RIGHTDOWN == true){
        snake[i+1].y--;
        snake[i].RIGHTDOWN = false;
      }else if(snake[i].x > snake[i+1].x && snake[i].y < snake[i+1].y && snake[i].DOWNRIGHT == true){
        snake[i+1].x++;
        snake[i].DOWNRIGHT = false;
      }else if(snake[i].x < snake[i+1].x && snake[i].y < snake[i+1].y && snake[i].RIGHTUP == true){
        snake[i+1].y--;
        snake[i].RIGHTUP = false;
      }else if(snake[i].x < snake[i+1].x && snake[i].y < snake[i+1].y && snake[i].UPRIGHT == true){
        snake[i+1].x--;
        snake[i].UPRIGHT = false;
      }else if(snake[i].x == snake[i+1].x && snake[i].y < snake[i+1].y){
        snake[i+1].y--;
      }else if(snake[i].x == snake[i+1].x && snake[i].y > snake[i+1].y){
        snake[i+1].y++;
      }else if(snake[i].x < snake[i+1].x && snake[i].y == snake[i+1].y){
        snake[i+1].x--;
      }else if(snake[i].x > snake[i+1].x && snake[i].y == snake[i+1].y){
        snake[i+1].x++;
      }
    }
    
    for(int i = 0; i < counter; i++){
      if(snake[i].y < 0){
        snake[i].y = 7;
      } 
    }
    light(snake[0].x, snake[0].y, zLayer);
  }
}
*/

/*
 * By changing the movement, the whole of the snake should follow the direction. Each led light should
 * be checked in which direction they have to move on. For each led should the direction, in where it moved, be saved as boolean.
 * So every led have just to check, which way his precursor covered before and follow that way. 
 */
void moveSnakeBody(Led snake[], int counter){
  int head = 0;

  for(int i = head; i < counter-2; i++){
      if(snake[i].UP == true){
        snake[i+1].x--;
        snake[i].UP = false;
        if(snake[i+1].y > snake[i+2].y){
          snake[i+1].RIGHTUP = true;
        }else if(snake[i+1].y < snake[i+2].y){
          snake[i+1].LEFTUP = true;
        }else if(snake[i+1].y == snake[i+2].y){
          snake[i+1].UP = true;
        }
      }else if(snake[i].DOWN == true){
        snake[i+1].x++;
        snake[i].DOWN = false;
        if(snake[i+1].y > snake[i+2].y){
          snake[i+1].LEFTDOWN = true;
        }else if(snake[i+1].y < snake[i+2].y){
          snake[i+1].RIGHTDOWN = true;
        }else if(snake[i+1].y == snake[i+2].y){
          snake[i+1].DOWN = true;
        }
      }else if(snake[i].LEFT == true){
        snake[i+1].y--;
        snake[i].LEFT = false;
        if(snake[i+1].x > snake[i+2].x){
          snake[i+1].UPLEFT = true;
        }else if(snake[i+1].y < snake[i+2].y){
          snake[i+1].DOWNLEFT = true;
        }else if(snake[i+1].y == snake[i+2].y){
          snake[i+1].LEFT = true;
        }
      }else if(snake[i].RIGHT == true){
        snake[i+1].y++;
        snake[i].RIGHT = false;
        if(snake[i+1].x > snake[i+2].x){
          snake[i+1].UPRIGHT = true;
        }else if(snake[i+1].y < snake[i+2].y){
          snake[i+1].DOWNRIGHT = true;
        }else if(snake[i+1].y == snake[i+2].y){
          snake[i+1].RIGHT = true;
        }
      }else if(snake[i].UPRIGHT == true){
        snake[i+1].x--;
        snake[i].UPRIGHT = false;
        if(snake[i+1].y > snake[i+2].y){
          snake[i+1].RIGHTUP = true;
        }else if(snake[i+1].y < snake[i+2].y){
          snake[i+1].LEFTUP = true;
        }else if(snake[i+1].y == snake[i+2].y){
          snake[i+1].UP = true;
        }
      }else if(snake[i].RIGHTUP == true){
        snake[i+1].x--;
        snake[i].RIGHTUP = false;
        if(snake[i+1].y > snake[i+2].y){
          snake[i+1].RIGHTUP = true;
        }else if(snake[i+1].y < snake[i+2].y){
          snake[i+1].LEFTUP = true;
        }else if(snake[i+1].y == snake[i+2].y){
          snake[i+1].UP = true;
        }  
      }else if(snake[i].DOWNRIGHT == true){
        snake[i+1].x++;
        snake[i].DOWNRIGHT = false;
        if(snake[i+1].y > snake[i+2].y){
          snake[i+1].RIGHTDOWN = true;
        }else if(snake[i+1].y < snake[i+2].y){
          snake[i+1].LEFTDOWN = true;
        }else if(snake[i+1].y == snake[i+2].y){
          snake[i+1].DOWN = true;
        }
      }else if(snake[i].RIGHTDOWN == true){
        snake[i+1].y--;
        snake[i].RIGHTDOWN = false;
        if(snake[i+1].x > snake[i+2].x){
          snake[i+1].DOWNRIGHT = true;
        }else if(snake[i+1].x < snake[i+2].x){
          snake[i+1].UPRIGHT = true;
        }else if(snake[i+1].x == snake[i+2].x){
          snake[i+1].RIGHT = true;
        }
      }else if(snake[i].UPLEFT == true){
        snake[i+1].x--;
        snake[i].UPLEFT = false;
        if(snake[i+1].y > snake[i+2].y){
          snake[i+1].RIGHTUP = true;
        }else if(snake[i+1].y < snake[i+2].y){
          snake[i+1].LEFTUP = true;
        }else if(snake[i+1].y == snake[i+2].y){
          snake[i+1].UP = true;
        }  
      }else if(snake[i].LEFTUP == true){
        snake[i+1].x--;
        snake[i].LEFTUP = false;
        if(snake[i+1].y > snake[i+2].y){
          snake[i+1].RIGHTUP = true;
        }else if(snake[i+1].y < snake[i+2].y){
          snake[i+1].LEFTUP = true;
        }else if(snake[i+1].y == snake[i+2].y){
          snake[i+1].UP = true;
        }
      }else if(snake[i].DOWNLEFT == true){
        snake[i+1].x++;
        snake[i].DOWNLEFT = false;
        if(snake[i+1].y > snake[i+2].y){
          snake[i+1].RIGHTDOWN = true;
        }else if(snake[i+1].y < snake[i+2].y){
          snake[i+1].LEFTDOWN = true;
        }else if(snake[i+1].y == snake[i+2].y){
          snake[i+1].DOWN = true;
        }
      }else if(snake[i].LEFTDOWN == true){
        snake[i+1].y--;
        snake[i].LEFTDOWN = false;
        if(snake[i+1].x > snake[i+2].x){
          snake[i+1].DOWNRIGHT = true;
        }else if(snake[i+1].x < snake[i+2].x){
          snake[i+1].UPRIGHT = true;
        }else if(snake[i+1].x == snake[i+2].x){
          snake[i+1].RIGHT = true;
        }
      }
    }

//The followeing if-else statement is important to move the last led of the list because the loop before goes until the second
//last of the list.

    if(snake[counter-2].UP == true){
      snake[counter-1].x--;
      snake[counter-2].UP = false;
    }else if(snake[counter-2].DOWN == true){
      snake[counter-1].x++;
      snake[counter-2].DOWN = false;
    }else if(snake[counter-2].LEFT == true){
      snake[counter-1].y--;
      snake[counter-2].LEFT = false;
    }else if(snake[counter-2].RIGHT == true){
      snake[counter-1].y++;
      snake[counter-2].RIGHT = false;
    }else if(snake[counter-2].UPRIGHT == true){
      snake[counter-1].x--;
      snake[counter-2].UPRIGHT = false;
    }else if(snake[counter-2].RIGHTUP == true){
      snake[counter-1].y--;
      snake[counter-2].RIGHTUP = false;
    }else if(snake[counter-2].DOWNRIGHT == true){
      snake[counter-1].x++;
      snake[counter-2].DOWNRIGHT = false;
    }else if(snake[counter-2].RIGHTDOWN == true){
      snake[counter-1].y--;
      snake[counter-2].RIGHTDOWN = false;
    }else if(snake[counter-2].UPLEFT == true){
      snake[counter-1].x--;
      snake[counter-2].UPLEFT= false;
    }else if(snake[counter-2].LEFTUP == true){
      snake[counter-1].y--;
      snake[counter-2].LEFTUP = false;
    }else if(snake[counter-2].DOWNLEFT == true){
      snake[counter-1].x++;
      snake[counter-2].DOWNLEFT = false;
    }else if(snake[counter-2].LEFTDOWN == true){
      snake[counter-1].y++;
      snake[counter-2].LEFTDOWN = false;
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
      list[head].LEFTDOWN = true;
    }else if(list[head].y < list[head+1].y){
      list[head].x++;
      list[head].RIGHTDOWN = true;
    }else if(list[head].y == list[head+1].y){
      list[head].x++;
    }
    
    moveSnakeBody(list, counter);

   //If the snake move toward a side of the cube, it will come out from the other side. 
    for(int i = 0; i < counter; i++){
      if(list[i].x < 0){
        list[i].x = 7;
      } 
    }
    light(list[head].x, list[head].y, zLayer);
    
  }else if(y_axe < 10){ //UP
    
    if(list[head].y > list[head+1].y){
      list[head].x--;
      list[head].LEFTUP = true;
    }else if(list[head].y < list[head+1].y){
      list[head].x--;
      list[head].RIGHTUP = true;
    }else if(list[head].y == list[head+1].y){
      list[head].x--;
    }
    
    moveSnakeBody(list, counter);
    
    for(int i = 0; i < counter; i++){
      if(list[i].x > 7){
        list[i].x = 0;
      } 
    }
    light(list[head].x, list[head].y, zLayer);
    
  }else if(x_axe < 10){//LEFT
  
    if(list[head].x > list[head+1].x){
      list[head].y++;
      list[head].DOWNLEFT = true;
    }else if(list[head].x < list[head+1].x){
      list[head].y++;
      list[head].UPLEFT = true;
    }else if(list[head].x == list[head+1].x){
      list[head].y++;
    }
    
    moveSnakeBody(list, counter);
    
    for(int i = 0; i < counter-1; i++){
      if(list[i].y > 7){
        list[i].y = 0;
      } 
    }
    light(list[head].x, list[head].y, zLayer);
    
  }else if(x_axe > 1000){ //RIGHT
    
    if(list[head].x > list[head+1].x){
      list[head].y--;
      list[head].DOWNRIGHT = true;
    }else if(list[head].x < list[head+1].x){
      list[head].y--;
      list[head].UPRIGHT = true;
    }else if(list[head].x == list[head+1].x){
      list[head].y--;
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
  Led newLed = {x, y, false, false, false, false, false, false, false, false, false, false };
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

  Led led1 = {xc, yc, false, false, false, false, false, false, false, false, false, false};
  listCounter++;
  Led led2 = {xc2, yc2, false, false, false, false, false, false, false, false, false, false};
  listCounter++;
  Led led3 = {xc3, yc3, false, false, false, false, false, false, false, false, false, false};
  listCounter++;
  Led led4 = {xc4, yc4, false, false, false, false, false, false, false, false, false, false};
  listCounter++;
  Led led5 = {xc5, yc5, false, false, false, false, false, false, false, false, false, false};
  listCounter++;

  snake[0] = led1;
  snake[1] = led2;
  snake[2] = led3;
  snake[3] = led4;
  snake[4] = led5;

  /*apple = randomLight();
  if(snake[0].x == apple.x && snake[0].y == apple.y){
    listCounter++;
    if(snake[0].x == snake[1].x){
      snake[listCounter] = createLight(snake[listCounter-1].x, snake[listCounter-1].y--);
    }else if(snake[0].y == snake[1].y){
      snake[listCounter] = createLight(snake[listCounter-1].x--, snake[listCounter-1].y);
    }
    apple = randomLight();
  }*/

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
