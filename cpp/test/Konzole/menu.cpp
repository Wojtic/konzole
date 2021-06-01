#include "define.h"

namespace menu {
  struct Item {
    uint8_t *data;
    uint8_t len;
    color_t *colors;
    color_t background;
  };
  
  const PROGMEM uint8_t pacman_data[] = {31, 31, 8, 34, 65, 17, 6, 38, 65, 15, 5, 41, 64, 14, 4, 43, 64, 13, 4, 33, 97, 36, 97, 32, 64, 13, 3, 33, 99, 34, 99, 32, 64, 12, 3, 33, 97, 129, 34, 97, 129, 32, 64, 12, 3, 33, 97, 129, 34, 97, 129, 32, 64, 12, 3, 34, 97, 36, 97, 33, 64, 12, 3, 45, 64, 12, 3, 44, 161, 195, 8, 3, 42, 167, 193, 6, 3, 41, 170, 192, 5, 3, 40, 172, 192, 4, 3, 39, 174, 192, 3, 3, 33, 64, 0, 35, 172, 6, 3, 32, 64, 2, 33, 171, 8, 3, 64, 4, 32, 169, 10, 10, 168, 11, 10, 168, 11, 10, 168, 192, 10, 10, 169, 193, 8, 11, 170, 193, 6, 11, 172, 194, 3, 12, 172, 192, 4, 13, 170, 192, 5, 14, 167, 193, 6, 16, 161, 195, 8, 31, 31};
  const PROGMEM color_t pacman_colors[] = {0, 53703, 45478, 65535, 16953, 65377, 54784};   
  Item pacman {pacman_data, sizeof(pacman_data)/sizeof(uint8_t), pacman_colors, color_dark_purple};

  const PROGMEM uint8_t settings_data[] = {31, 31, 12, 37, 12, 12, 32, 66, 96, 32, 12, 6, 33, 3, 32, 64, 98, 32, 3, 33, 6, 5, 32, 65, 32, 1, 32, 64, 100, 32, 1, 32, 97, 32, 5, 4, 32, 67, 33, 64, 102, 33, 99, 32, 4, 3, 32, 70, 110, 32, 3, 3, 32, 66, 114, 32, 3, 4, 32, 64, 114, 32, 4, 5, 32, 64, 112, 32, 5, 5, 32, 64, 101, 35, 102, 32, 5, 4, 32, 65, 100, 32, 3, 32, 102, 32, 4, 1, 34, 64, 101, 32, 5, 32, 102, 34, 1, 1, 32, 65, 101, 32, 7, 32, 102, 128, 32, 1, 1, 32, 64, 102, 32, 7, 32, 102, 128, 32, 1, 1, 32, 65, 101, 32, 7, 32, 102, 128, 32, 1, 1, 32, 65, 101, 32, 7, 32, 101, 129, 32, 1, 1, 34, 64, 101, 32, 5, 32, 101, 128, 34, 1, 4, 32, 64, 101, 32, 3, 32, 101, 128, 32, 4, 5, 32, 64, 101, 35, 101, 128, 32, 5, 5, 32, 64, 111, 128, 32, 5, 4, 32, 65, 111, 129, 32, 4, 3, 32, 66, 113, 128, 32, 3, 3, 32, 65, 97, 66, 103, 129, 99, 128, 32, 3, 4, 32, 67, 33, 64, 102, 33, 128, 97, 128, 32, 4, 5, 32, 65, 32, 1, 32, 64, 100, 32, 1, 32, 129, 32, 5, 6, 33, 3, 32, 64, 98, 32, 3, 33, 6, 12, 32, 65, 97, 32, 12, 12, 37, 12, 31, 31};
  const PROGMEM color_t settings_colors[] = {0, 12710, 29582, 25356, 19017};
  Item settings {settings_data, sizeof(settings_data)/sizeof(uint8_t), settings_colors, color_white};
  
  const PROGMEM uint8_t tetris_data[] = {31, 31, 31, 31, 31, 10, 41, 10, 10, 32, 70, 96, 32, 10, 10, 32, 64, 133, 96, 32, 10, 10, 32, 64, 133, 96, 32, 10, 10, 32, 64, 133, 96, 32, 10, 10, 32, 64, 133, 96, 32, 10, 10, 32, 64, 133, 96, 32, 10, 10, 32, 64, 133, 96, 32, 10, 10, 32, 103, 32, 10, 10, 41, 10, 0, 61, 0, 0, 32, 70, 96, 33, 70, 96, 33, 70, 96, 32, 0, 0, 32, 64, 133, 96, 33, 64, 133, 96, 33, 64, 133, 96, 32, 0, 0, 32, 64, 133, 96, 33, 64, 133, 96, 33, 64, 133, 96, 32, 0, 0, 32, 64, 133, 96, 33, 64, 133, 96, 33, 64, 133, 96, 32, 0, 0, 32, 64, 133, 96, 33, 64, 133, 96, 33, 64, 133, 96, 32, 0, 0, 32, 64, 133, 96, 33, 64, 133, 96, 33, 64, 133, 96, 32, 0, 0, 32, 64, 133, 96, 33, 64, 133, 96, 33, 64, 133, 96, 32, 0, 0, 32, 103, 33, 103, 33, 103, 32, 0, 0, 61, 0, 31, 31, 31, 31, 31, 31, 31};
  const PROGMEM color_t tetris_colors[] = {0, 29165, 52120, 33391, 47830};
  Item tetris {tetris_data, sizeof(tetris_data)/sizeof(uint8_t), tetris_colors, color_gray};
  
  const PROGMEM uint8_t snake_data[] = {31, 31, 31, 24, 32, 5, 24, 32, 5, 25, 32, 4, 24, 67, 2, 23, 68, 96, 1, 8, 138, 160, 2, 68, 96, 1, 8, 138, 160, 2, 68, 96, 1, 8, 138, 160, 2, 68, 96, 1, 8, 138, 160, 3, 65, 97, 2, 8, 130, 160, 3, 130, 160, 10, 8, 130, 160, 3, 130, 160, 10, 8, 130, 160, 3, 130, 160, 10, 8, 130, 160, 3, 130, 160, 10, 8, 130, 160, 3, 130, 160, 10, 8, 130, 160, 3, 130, 160, 3, 133, 0, 8, 130, 160, 3, 130, 160, 3, 130, 192, 224, 128, 0, 8, 130, 160, 3, 130, 160, 3, 130, 193, 128, 0, 0, 138, 160, 3, 130, 164, 133, 0, 0, 138, 160, 3, 141, 0, 0, 138, 160, 3, 141, 0, 0, 171, 3, 141, 0, 31, 31, 31, 31, 31, 31, 31, 31};
  const PROGMEM color_t snake_colors[] = {0, 33125, 53703, 45478, 19068, 16953, 12710, 42292};
  Item snake {snake_data, sizeof(snake_data)/sizeof(uint8_t), snake_colors, color_lime};
  
  const PROGMEM uint8_t mario_data[] = {9, 41, 11, 9, 41, 11, 7, 49, 5, 7, 49, 5, 7, 69, 99, 129, 97, 9, 7, 69, 99, 129, 97, 9, 5, 65, 97, 65, 101, 129, 101, 5, 5, 65, 97, 65, 101, 129, 101, 5, 5, 65, 97, 67, 101, 129, 101, 3, 5, 65, 97, 67, 101, 129, 101, 3, 7, 65, 103, 135, 5, 7, 65, 103, 135, 5, 9, 107, 9, 9, 107, 9, 7, 35, 161, 35, 161, 35, 7, 7, 35, 161, 35, 161, 35, 7, 5, 37, 161, 35, 161, 37, 5, 5, 37, 161, 35, 161, 37, 5, 3, 39, 167, 39, 3, 3, 39, 167, 39, 3, 3, 99, 33, 161, 193, 163, 193, 161, 33, 99, 3, 3, 99, 33, 161, 193, 163, 193, 161, 33, 99, 3, 3, 101, 171, 101, 3, 3, 101, 171, 101, 3, 3, 99, 175, 99, 3, 3, 99, 175, 99, 3, 7, 165, 3, 165, 7, 7, 165, 3, 165, 7, 5, 69, 7, 69, 5, 5, 69, 7, 69, 5, 3, 71, 7, 71, 3, 3, 71, 7, 71, 3};
  const PROGMEM color_t mario_colors[] = {0, 9283, 33125, 57028, 12710, 19068, 65440};
  Item mario {mario_data, sizeof(mario_data)/sizeof(uint8_t), mario_colors, color_light_blue};

  const PROGMEM uint8_t piskvorky_data[] = {31, 0, 33, 2, 32, 1, 32, 2, 34, 3, 32, 10, 1, 33, 0, 33, 1, 32, 2, 32, 0, 32, 3, 32, 10, 2, 34, 1, 34, 0, 32, 2, 32, 1, 32, 11, 2, 33, 2, 33, 1, 32, 2, 32, 1, 33, 10, 1, 35, 1, 33, 1, 32, 2, 32, 1, 33, 10, 0, 33, 1, 33, 0, 33, 2, 32, 0, 32, 2, 33, 10, 0, 32, 3, 32, 0, 34, 1, 34, 2, 33, 10, 7, 34, 7, 34, 9, 2, 41, 5, 41, 2, 0, 61, 0, 4, 51, 6, 7, 34, 7, 34, 9, 8, 33, 2, 34, 1, 34, 9, 8, 33, 2, 32, 0, 32, 2, 33, 9, 8, 33, 1, 32, 2, 32, 1, 33, 9, 8, 33, 1, 32, 2, 32, 1, 33, 9, 8, 33, 1, 32, 2, 32, 1, 33, 9, 7, 34, 2, 32, 0, 32, 1, 34, 9, 7, 34, 2, 34, 1, 34, 9, 7, 34, 7, 34, 9, 2, 52, 7, 0, 61, 0, 5, 37, 4, 43, 2, 7, 34, 7, 34, 9, 7, 34, 7, 34, 1, 33, 2, 32, 1, 7, 33, 9, 33, 2, 33, 0, 33, 1, 7, 33, 9, 33, 3, 34, 2, 7, 33, 9, 33, 3, 33, 3, 8, 32, 9, 32, 3, 33, 0, 32, 2, 8, 32, 9, 32, 3, 32, 1, 33, 1, 31};
  const PROGMEM color_t piskvorky_colors[] = {0, 1};
  Item piskvorky {piskvorky_data, sizeof(piskvorky_data)/sizeof(uint8_t), piskvorky_colors, color_white};

  const PROGMEM uint8_t pong_data[] = {31, 10, 33, 6, 33, 9, 9, 32, 1, 32, 1, 32, 1, 32, 1, 32, 8, 11, 32, 8, 32, 8, 12, 32, 6, 32, 9, 2, 66, 3, 32, 1, 32, 1, 32, 2, 32, 10, 2, 66, 4, 33, 5, 35, 8, 2, 66, 25, 2, 66, 25, 2, 66, 25, 2, 66, 25, 2, 66, 25, 2, 66, 25, 2, 66, 7, 65, 15, 2, 66, 7, 65, 15, 2, 66, 9, 97, 7, 66, 2, 2, 66, 9, 97, 7, 66, 2, 2, 66, 11, 129, 5, 66, 2, 17, 129, 5, 66, 2, 19, 161, 3, 66, 2, 19, 161, 3, 66, 2, 25, 66, 2, 25, 66, 2, 25, 66, 2, 25, 66, 2, 25, 66, 2, 25, 66, 2, 25, 66, 2, 31, 31, 31, 31};
  const PROGMEM color_t pong_colors[] = {0, 34431, 57051, 46486, 31727, 23275};
  Item pong {pong_data, sizeof(pong_data)/sizeof(uint8_t), pong_colors, color_dark_gray};
  
  const Item icons[] = {settings, pong, pacman, snake, mario, tetris, piskvorky};
  const byte icon_count = 7;

  uint8_t menu_position = 0;
  uint8_t scroll_position = 0;

  void drawIcon(int x, int y, uint8_t *data, color_t *colors, color_t background, uint8_t len) {
    int cur_len = 0;
    for (int i = 0; i < len; i++) {
      uint8_t cur_data = pgm_read_byte(&data[i]);
      tft.drawHLine(x + (cur_len % 32), y + cur_len / 32, cur_data % 32 + 1, cur_data/32 == 0 ? background : pgm_read_word_near(&colors[cur_data/32]));
      cur_len += cur_data % 32 + 1;
    }
  }

  void drawScroll() {
    if(scroll_position != 0) {
      tft.fillTriangle(30, 100, 5, 135, 30, 170, color_gray);
      tft.fillTriangle(27, 110, 10, 135, 27, 160, color_white);
    } else { // složité kvůli gradientu
      uint8_t colBlue = 19;
      uint8_t colGreen = 25;
      uint8_t colRed = 30;
      for (int i = 100; i < 170; i++) {
       colBlue -= ((i % 8) == 0);
       colGreen += ((i % 4) == 0);

       uint16_t color = ((uint16_t) (colRed & 0b00011111) << 11) + ((uint16_t)(colGreen & 0b00111111) << 5) + (colBlue & 0b00011111);
       tft.drawHLine(0, i, 31, color);
     }
    }
    if (scroll_position < icon_count-6) {
      tft.fillTriangle(290, 100, 315, 135, 290, 170, color_gray);
      tft.fillTriangle(293, 110, 310, 135, 293, 160, color_white);
    } else { // složité kvůli gradientu
      uint8_t colBlue = 19;
      uint8_t colGreen = 25;
      uint8_t colRed = 30;
      for (int i = 100; i < 170; i++) {
       colBlue -= ((i % 8) == 0);
       colGreen += ((i % 4) == 0);

       uint16_t color = ((uint16_t) (colRed & 0b00011111) << 11) + ((uint16_t)(colGreen & 0b00111111) << 5) + (colBlue & 0b00011111);
       tft.drawHLine(290, i, 31, color);
     }
    }
  }

  void drawBackground() {
    uint8_t colBlue = 31;
    uint8_t colGreen = 0;
    uint8_t colRed = 30;
    for (int i = 0; i < 240; i++) {
      colBlue -= ((i % 8) == 0);
      colGreen += ((i % 4) == 0);

      uint16_t color = ((uint16_t) (colRed & 0b00011111) << 11) + ((uint16_t)(colGreen & 0b00111111) << 5) + (colBlue & 0b00011111);
      tft.drawHLine(0, i, 320, color);
    }

    tft.fillRoundRect(0, -30, 320, 60, 30, color_white);
    tft.setCursor(96, 10);
    tft.setTextColor(color_black);
    tft.setTextSize(2);
    tft.print("Hlavni menu");
  }

  void drawItem(int position) {
    int x = position/2;
    int y = position - x*2;
    color_t frame = color_black;
    if (position+scroll_position == menu_position) {
      frame = color_yellow;
    }
    tft.fillRoundRect(40+90*x, 40+100*y, 60, 80, 7, frame);
    tft.fillRoundRect(45+90*x, 45+100*y, 50, 70, 7, icons[position+scroll_position].background);
    drawIcon(54+90*x, 50+100*y, icons[position+scroll_position].data, icons[position+scroll_position].colors, icons[position+scroll_position].background, icons[position+scroll_position].len);
  }

  void drawItems() {
    for (int i=0; i<6; i++) {
      drawItem(i);
    }
  }

  void selectMenuItem() {
    current_game = menu_position+1;  
    game_setups[current_game]();
  }
  
  void setup() {
    drawBackground();
    drawItems();
    drawScroll();
  }

  void loop() {
    if (Input::is_just_pressed(button_down)) {
      selectMenuItem();
    }
    if (Input::is_just_pressed(dpad_down) && menu_position+1 < icon_count) {
      menu_position += 1;
      if (menu_position >= scroll_position+6) {
        scroll_position+=2;
        drawScroll();
        drawItems();
      }
      drawItem(menu_position-1-scroll_position);
      drawItem(menu_position-scroll_position);
    }
    if (Input::is_just_pressed(dpad_up) && menu_position-1 >= 0) {
      menu_position -= 1;
      if (menu_position < scroll_position) {
        scroll_position-=2;
        drawScroll();
        drawItems();
      }
      drawItem(menu_position+1-scroll_position);
      drawItem(menu_position-scroll_position);
    }
    if (Input::is_just_pressed(dpad_left) && menu_position-2 >= 0) {
      menu_position -= 2;
      if (menu_position < scroll_position) {
        scroll_position-=2;
        drawScroll();
        drawItems();
      }
      drawItem(menu_position+2-scroll_position);
      drawItem(menu_position-scroll_position);
    }
    if (Input::is_just_pressed(dpad_right) && menu_position+2 < icon_count) {
      menu_position += 2;
      if (menu_position >= scroll_position+6) {
        scroll_position+=2;
        drawScroll();
        drawItems();
      }
      drawItem(menu_position-2-scroll_position);
      drawItem(menu_position-scroll_position);
    }
  }

}
