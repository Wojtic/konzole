#include "define.h"

namespace snake {
const uint8_t grid = 20; // Velikost mřížky - musí být násobek 4 a musí být minimálně 16, jinak se pole nevejde do ramky
const int maxLen = screen_width / grid * (screen_height / grid);
uint8_t snake[maxLen][2];
int snakeLen = 1;
bool eaten = false;

int dy = 0;
int dx = 1;
int lastDy = 0;
int lastDx = 1;

int delayTime = 250;

int apple[2] = {random(0, screen_width / grid), random(0, screen_height / grid)};

const color_t background = color_white;
const color_t col_snake = color_green;
const color_t col_apple = color_red;

void death() {
  tft.fillScreen(color_red);
  while (true) {}
}

void checkDeath() {
  if (snake[snakeLen - 1][0] < 0 || snake[snakeLen - 1][1] < 0 || snake[snakeLen - 1][0] >= screen_width / grid || snake[snakeLen - 1][1] >= screen_height / grid) {
    death();
  }
  for (int i = 0; i < snakeLen - 1; i++) {
    for (int j = i + 1; j < snakeLen; j++) {
      if (snake[i][0] == snake[j][0] && snake[i][1] == snake[j][1]) {
        death();
      }
    }
  }
}

void updateSnake() {
  if (eaten) {
    eaten = false;
    snake[snakeLen][0] = snake[snakeLen - 1][0];
    snake[snakeLen][1] = snake[snakeLen - 1][1];
    snakeLen++;
  } else {

    tft.fillRect(snake[0][0] * grid, snake[0][1] * grid, grid, grid, background);
    for (int i = 0; i < snakeLen - 1; i++) {
      snake[i][0] = snake[i + 1][0];
      snake[i][1] = snake[i + 1][1];
    }
  }
  snake[snakeLen - 1][0] += dx;
  snake[snakeLen - 1][1] += dy;
  if (snakeLen == 1) {
    tft.fillRect(snake[snakeLen - 1][0] * grid + grid / 4, snake[snakeLen - 1][1] * grid + grid / 4, grid / 2, grid / 2, col_snake);
  } else if (snake[snakeLen - 2][1] > snake[snakeLen - 1][1]) {
    tft.fillRect(snake[snakeLen - 1][0] * grid + grid / 4, snake[snakeLen - 1][1] * grid + grid / 4, grid / 2, grid, col_snake);
  } else if (snake[snakeLen - 2][1] < snake[snakeLen - 1][1]) {
    tft.fillRect(snake[snakeLen - 1][0] * grid + grid / 4, snake[snakeLen - 1][1] * grid - grid / 4, grid / 2, grid, col_snake);
  } else if (snake[snakeLen - 2][0] < snake[snakeLen - 1][0]) {
    tft.fillRect(snake[snakeLen - 1][0] * grid - grid / 4, snake[snakeLen - 1][1] * grid + grid / 4, grid, grid / 2, col_snake);
  } else if (snake[snakeLen - 2][0] > snake[snakeLen - 1][0]) {
    tft.fillRect(snake[snakeLen - 1][0] * grid + grid / 4, snake[snakeLen - 1][1] * grid + grid / 4, grid, grid / 2, col_snake);
  }

  checkDeath();
}

void updateApple() {
  if (snake[snakeLen - 1][0] == apple[0] && snake[snakeLen - 1][1] == apple[1]) {
    eaten = true;
    int appleNewX = random(0, screen_width / grid);
    int appleNewY = random(0, screen_height / grid);
    for (int i = 0; i < snakeLen; i++) {
      if (snake[i][0] == appleNewX && snake[i][1] == appleNewY) {
        i = -1;
        appleNewX = random(0, screen_width / grid);
        appleNewY = random(0, screen_height / grid);
      }
    }
    apple[0] = appleNewX;
    apple[1] = appleNewY;
    tft.fillRect(apple[0] * grid + grid/4, apple[1] * grid + grid / 4, grid / 2, grid / 2, col_apple);
  }
}

void setup() {
  snake[0][0] = 5; // Nesnáším c++ :)
  snake[0][1] = 5;
  tft.fillScreen(background);
  tft.fillRect(apple[0] * grid, apple[1] * grid, grid, grid, col_apple);
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
