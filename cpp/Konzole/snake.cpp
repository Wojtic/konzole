#include "define.h"

namespace snake {
const uint8_t grid = 8; // Velikost mřížky - musí být násobek 4
const int maxLen = screen_width / grid * (screen_height / grid) / 4;
byte snake[maxLen];
int snakeLen = 2;
bool eaten = false;
uint8_t head [2] = {7, 5};
uint8_t prevHead[2] = {6, 5};
uint8_t prevTail[2] = {5, 5};

int dy = 0;
int dx = 1;
int lastDy = 0;
int lastDx = 1;

int delayTime = 250;

int apple[2] = {random(0, screen_width / grid), random(0, screen_height / grid)};

const color_t background = color_white;
const color_t col_snake = color_green;
const color_t col_apple = color_red;

void writeSnake(int index, int dx = dx, int dy = dy) {
  if (dx == 1) {
    bitWrite(snake[index % 4], 7 - (index % 4) * 2, 0);
    bitWrite(snake[index % 4], 6 - (index % 4) * 2, 0);
  } else if (dx == -1) {
    bitWrite(snake[index % 4], 7 - (index % 4) * 2, 0);
    bitWrite(snake[index % 4], 6 - (index % 4) * 2, 1);
  } else if (dy == 1) {
    bitWrite(snake[index % 4], 7 - (index % 4) * 2, 1);
    bitWrite(snake[index % 4], 6 - (index % 4) * 2, 0);
  } else if (dy == -1) {
    bitWrite(snake[index % 4], 7 - (index % 4) * 2, 1);
    bitWrite(snake[index % 4], 6 - (index % 4) * 2, 1);
  }
}

void readSnake(int index, int res[]) {
  uint8_t bit1 = bitRead(snake[index % 4], 7 - (index % 4) * 2);
  uint8_t bit2 = bitRead(snake[index % 4], 6 - (index % 4) * 2);
  if (bit1 == 0 && bit2 == 0) {
    res[0] = 1;
    res[1] = 0;
  } else if (bit1 == 0 && bit2 == 1) {
    res[0] = -1;
    res[1] = 0;
  } else if (bit1 == 1 && bit2 == 0) {
    res[0] = 0;
    res[1] = 1;
  } else if (bit1 == 1 && bit2 == 1) {
    res[0] = 0;
    res[1] = -1;
  }
}

void death() {
  tft.fillScreen(color_red);
  while (true) {}
}

void checkDeath() {
  if (head[0] < 0 || head[1] < 0 || head[0] >= screen_width / grid || head[1] >= screen_height / grid) {
    death();
  }
  int prevTailCopy[2];
  prevTailCopy[0] = prevTail[0];
  prevTailCopy[1] = prevTail[1];
  for (int i = 0; i < snakeLen - 1; i++) {
    int snakeReadout[2];
    readSnake(i, snakeReadout);
    prevTailCopy[0] += snakeReadout[0];
    prevTailCopy[1] += snakeReadout[1];
    if (prevTailCopy[0] == head[0] && prevTailCopy[1] == head[1]) {
      death();
    }
  }
}

void updateSnake() {
  if (eaten) {
    eaten = false;
    bitWrite(snake[snakeLen % 4], 7 - (snakeLen % 4) * 2, bitRead(snake[(snakeLen - 1) % 4], 7 - ((snakeLen - 1) % 4) * 2));
    bitWrite(snake[snakeLen % 4], 6 - (snakeLen % 4) * 2, bitRead(snake[(snakeLen - 1) % 4], 6 - ((snakeLen - 1) % 4) * 2));
    snakeLen++;
  } else {
    int tailReadout[2];
    readSnake(0, tailReadout);
    prevTail[0] += tailReadout[0];
    prevTail[1] += tailReadout[1];

    tft.fillRect(prevTail[0] * grid, prevTail[1] * grid, grid, grid, background);

    for (int i = 0; i < snakeLen - 1; i++) {
      bitWrite(snake[i % 4], 7 - (i % 4) * 2, bitRead(snake[(i + 1) % 4], 7 - ((i + 1) % 4) * 2));
      bitWrite(snake[i % 4], 6 - (i % 4) * 2, bitRead(snake[(i + 1) % 4], 6 - ((i + 1) % 4) * 2));
    }
  }
  // ------------------------------- update head
  writeSnake(snakeLen - 1);
  prevHead[0] = head[0];
  prevHead[1] = head[1];
  head[0] += dx;
  head[1] += dy;
  // ------------------------------- draw head
  if (snakeLen == 1) {
    tft.fillRect(head[0] * grid + grid / 4, head[1] * grid + grid / 4, grid / 2, grid / 2, col_snake);
  } else if (prevHead[1] > head[1]) {
    tft.fillRect(head[0] * grid + grid / 4, head[1] * grid + grid / 4, grid / 2, grid, col_snake);
  } else if (prevHead[1] < head[1]) {
    tft.fillRect(head[0] * grid + grid / 4, head[1] * grid - grid / 4, grid / 2, grid, col_snake);
  } else if (prevHead[0] < head[0]) {
    tft.fillRect(head[0] * grid - grid / 4, head[1] * grid + grid / 4, grid, grid / 2, col_snake);
  } else if (prevHead[0] > head[0]) {
    tft.fillRect(head[0] * grid + grid / 4, head[1] * grid + grid / 4, grid, grid / 2, col_snake);
  }

  checkDeath();
}

void updateApple() {
  if (head[0] == apple[0] && head[1] == apple[1]) {
    eaten = true;
    int appleNewX = random(0, screen_width / grid);
    int appleNewY = random(0, screen_height / grid);

    int prevTailCopy[2];
    prevTailCopy[0] = prevTail[0];
    prevTailCopy[1] = prevTail[1];
    for (int i = 0; i < snakeLen; i++) {
      int snakeReadout[2];
      readSnake(i, snakeReadout);
      prevTailCopy[0] += snakeReadout[0];
      prevTailCopy[1] += snakeReadout[1];
      if (prevTailCopy[0] == appleNewX && prevTailCopy[1] == appleNewY) {
        i = -1;
        appleNewX = random(0, screen_width / grid);
        appleNewY = random(0, screen_height / grid);
        prevTailCopy[0] = prevTail[0];
        prevTailCopy[1] = prevTail[1];
      }
    }
    apple[0] = appleNewX;
    apple[1] = appleNewY;
    tft.fillRect(apple[0] * grid + grid / 4, apple[1] * grid + grid / 4, grid / 2, grid / 2, col_apple);
  }
}

void setup() {
  snake[0] = 0;
  tft.fillScreen(background);
  tft.fillRect(apple[0] * grid + grid / 4, apple[1] * grid + grid / 4, grid / 2, grid / 2, col_apple);
}

unsigned long prevTime = 0;

void loop() {
  unsigned long currentTime = millis();
  if (currentTime - prevTime >= delayTime) {
    prevTime = currentTime;

    updateSnake();
    updateApple();

    lastDy = dy;
    lastDx = dx;
  }

  if (Input::is_just_pressed(button_left)) { // jenom pro testování - odstranit později
    eaten = true;
  }
  if (Input::is_just_pressed(dpad_down) && !(lastDy == -1 && lastDx == 0 && snakeLen != 1)) {
    dy = 1;
    dx = 0;
  }
  if (Input::is_just_pressed(dpad_up) && !(lastDy == 1 && lastDx == 0 && snakeLen != 1)) {
    dy = -1;
    dx = 0;
  }
  if (Input::is_just_pressed(dpad_left) && !(lastDy == 0 && lastDx == 1 && snakeLen != 1)) {
    dy = 0;
    dx = -1;
  }
  if (Input::is_just_pressed(dpad_right) && !(lastDy == 0 && lastDx == -1 && snakeLen != 1)) {
    dy = 0;
    dx = 1;
  }
}

}
