#include "define.h"

namespace pacman { 
  const uint8_t data_mapy[] = {
    1,2,2,2,2,10,2,2,2,2,2,2,2,2,10,2,2,2,2,3,
    5,0,0,0,0,5,0,0,0,0,0,0,0,0,5,0,0,0,0,5,
    5,0,1,12,0,8,0,13,2,2,2,2,12,0,8,0,13,3,0,5,
    5,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,5,
    5,0,5,0,4,0,13,2,3,0,0,1,2,12,0,4,0,5,0,5,
    5,0,5,0,5,0,0,0,9,2,2,11,0,0,0,5,0,5,0,5,
    5,0,8,0,5,0,4,0,0,0,0,0,0,4,0,5,0,8,0,5,
    5,0,0,0,8,0,9,3,0,1,3,0,1,11,0,8,0,0,0,5,
    5,0,4,0,0,0,0,8,0,9,11,0,8,0,0,0,0,4,0,5,
    5,0,5,0,1,12,0,0,0,0,0,0,0,0,13,3,0,5,0,5,
    5,0,5,0,9,12,0,1,2,12,13,2,3,0,13,11,0,5,0,5,
    5,0,5,0,0,0,0,5,0,0,0,0,5,0,0,0,0,5,0,5,
    5,0,9,2,2,12,0,9,2,2,2,2,11,0,13,2,2,11,0,5,
    5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,
    9,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,11
  };
    
  const uint8_t horizontal_data[] = {0b00000000,0b11111111,0b00000000,0b00000000,0b00000000,0b00000000,0b11111111,0b00000000};
  const uint8_t vertical_data[] = {0b01000010,0b01000010,0b01000010,0b01000010,0b01000010,0b01000010,0b01000010,0b01000010};
  const uint8_t corner[] = {0b00000000, 0b00000011, 0b00001100, 0b00010000, 0b00100000, 0b00100000, 0b01000001, 0b01000010};
  const uint8_t end_V[] = {0b00000000, 0b00011111, 0b00100000, 0b01000000, 0b01000000, 0b00100000, 0b00011111, 0b00000000};
  const uint8_t end_H[] =  {0b00000000, 0b00011000, 0b00100100, 0b01000010, 0b01000010, 0b01000010, 0b01000010, 0b01000010};
  const uint8_t single_data[] = {0b00000000, 0b00111100, 0b01100110, 0b01000010, 0b01000010, 0b01100110, 0b00111100, 0b00000000};
  const uint8_t connection_H[] = {0b00000000, 0b11111111, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b10000001, 0b01000010};
  const uint8_t connection_V[] = {0b01000010, 0b01000001, 0b01000000, 0b01000000, 0b01000000, 0b01000000, 0b01000001, 0b01000010};
  Tile_8 horizontal(horizontal_data, 0x01FD);
  Tile_8 vertical(vertical_data, 0x01FD);
  Tile_8 corner_UL(corner, 0x01FD, false, false);
  Tile_8 corner_UR(corner, 0x01FD, false, true);
  Tile_8 corner_DL(corner, 0x01FD, true, false);
  Tile_8 corner_DR(corner, 0x01FD, true, true);
  Tile_8 end_VL(end_V, 0x01FD, false, false);
  Tile_8 end_VR(end_V, 0x01FD, false, true);
  Tile_8 end_HU(end_H, 0x01FD, false, false);
  Tile_8 end_HD(end_H, 0x01FD, true, false);
  Tile_8 single(single_data, 0x01FD, false, false);
  Tile_8 connection_HU(connection_H, 0x01FD, false, false);
  Tile_8 connection_HD(connection_H, 0x01FD, true, false);
  Tile_8 connection_VL(connection_V, 0x01FD, false, true);
  Tile_8 connection_VR(connection_V, 0x01FD, false, false);
  
  const PROGMEM uint8_t pacman_LR[][5] = {{1,3,1,0,255},{1,12,1,0,255},{2,2,1,0,255},{2,4,1,0,255},{2,11,1,0,255},{2,13,1,0,255},{3,1,1,0,255},{3,14,1,0,255},{4,5,1,0,255},{4,10,1,0,255},{5,0,1,0,255},{5,15,1,0,255},{6,6,1,0,255},{6,9,1,0,255},{8,7,2,0,255},{9,2,2,255,0},{11,0,1,255,0},{11,2,2,0,255},{11,15,1,255,0},{13,1,1,255,0},{13,14,1,255,0},{14,2,1,255,0},{14,13,1,255,0},{15,3,2,255,0},{15,11,2,255,0},{16,5,6,255,0}};
  const PROGMEM uint8_t pacman_UD[][5] = {{5,0,6,0,255},{3,1,2,0,255},{11,1,2,0,255},{2,2,1,0,255},{9,2,2,255,0},{13,2,1,0,255},{1,3,1,0,255},{14,3,1,0,255},{1,4,1,255,0},{9,4,2,0,255},{2,5,2,255,0},{15,5,1,0,255},{4,6,2,255,0},{6,7,2,255,0},{6,9,2,0,255},{4,10,2,0,255},{2,11,2,0,255},{15,11,1,255,0},{1,12,1,0,255},{1,13,1,255,0},{14,13,1,255,0},{2,14,1,255,0},{13,14,1,255,0},{3,15,2,255,0},{11,15,2,255,0},{5,16,6,255,0}};
  const PROGMEM color_t pacman_colors[] = {65285};
  Entity pacman(pacman_LR, pacman_UD, pacman_colors, 26, 26);
  
  void setup() {
    BG_solid cerne_pozadi(0x0000);
    Tile_8 tily[] = {corner_UL, horizontal, corner_UR, end_HU, vertical, single, connection_VL, end_HD, corner_DL, connection_HU, corner_DR, end_VR, end_VL, connection_HD, connection_VR};
    //BG_tiled_16 mapa(tily, data_mapy, 40, 30);
    cerne_pozadi.draw();
    //mapa.draw();
    pacman.setSize(16, 16);
    pacman.setPosition(80, 40);
  }
  
  void loop() {
    if (Input::is_pressed(dpad_right)) {
      pacman.move(direction_right);
    }
      
    if (Input::is_pressed(dpad_down)) {
      pacman.move(direction_down);
    }
      
    if (Input::is_pressed(dpad_left)) {
      pacman.move(direction_left);
    }
      
    if (Input::is_pressed(dpad_up)) {
      pacman.move(direction_up);
    }
  }
}
