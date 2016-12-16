#include <Keyboard.h>

int NEXT = 7;
int DOWN = 5;
int UP = 3;

void setup() {
  // put your setup code here, to run once:
  pinMode(NEXT, INPUT_PULLUP);
  pinMode(DOWN, INPUT_PULLUP);
  pinMode(UP, INPUT_PULLUP);
  //We create a "programmable mode if the up and down keys are pressed on startup for 2 min.
  if(!digitalRead(UP) && !digitalRead(DOWN)) delay(120000);
  //Init Keyboard Mode
  Keyboard.begin();
}

bool downDown = false;
bool upDown = false;
bool nextDown = false;

char upChar = 0x2B;
char downChar = 0x2D;
char nextChar = 0xD7;

void loop() {
  // put your main code here, to run repeatedly:
  if(!digitalRead(NEXT) && !nextDown) {
    Keyboard.press(nextChar);
    nextDown = true;
  }
  if(!digitalRead(DOWN) && !downDown) {
    Keyboard.press(downChar);
    downDown = true;
  }
  if(!digitalRead(UP) && !upDown) {
    Keyboard.press(upChar);
    upDown = true;
  }

  if(digitalRead(NEXT) && nextDown) {
    Keyboard.release(nextChar);
    nextDown = false;
  }
  if(digitalRead(DOWN) && downDown) {
    Keyboard.release(downChar);
    downDown = false;
  }
  if(digitalRead(UP) && upDown) {
    Keyboard.release(upChar);
    upDown = false;
  }
  delay(50);
}
