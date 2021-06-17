#include "define.h"

enum games:uint8_t {
  Menu, Pacman, Pong, Settings, Snake, Breakout, Mario, Tetris
};
void (*game_setups[])() = {menu::setup, test::setup, pong::setup, pacman::setup, snake::setup};
void (*game_loops[])() = {menu::loop, test::loop, pong::loop, pacman::loop, snake::loop};


games current_game = Menu;

void setup() {
  Serial.begin(9600);
  tft.setup(255);
  Input::setup();
  game_setups[current_game]();
}
void loop() {
  Input::loop();
  game_loops[current_game]();
  frame_time_stabilizer();
}
