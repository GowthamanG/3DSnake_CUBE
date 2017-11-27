/* 3D Snake game for the lecture computer architecture and operating systems.
We gonna build a 8x8x8 Led-Cube, then write a snake program, which we can play with a joystick
*/

struct Coordinate{
    int x;
    int y;
    int z;
    int direction;
}

struct Snake{
    struct Coordinate snakeList;
    int SnakeListLength;
}

moveUp();
moveDown();
moveLeft();
moveRight();
startGame();
eatApple();



void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
