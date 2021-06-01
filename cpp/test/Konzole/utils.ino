const PROGMEM uint8_t None[][5] = {};  // empty array for Entities

const int bottom_button_count = 4;
const int bottom_button_pins[] = {button_bottom1_pin, button_bottom2_pin, button_bottom3_pin, button_bottom4_pin};

int input_debounce = 50; // set according to specific button
bool dbc_last_button_states[bottom_button_count] = {HIGH};
bool dbc_last_button_times[bottom_button_count] = {-1};

//input device state was stable for at least button_debounce time.
bool button_debounced(int i) { return (millis() - dbc_last_button_times[i] > input_debounce); }

unsigned long last_frame_start = 0;
const int desired_frame_time = 10;

static inline int8_t sign(int val) {
  if (val < 0) return -1;
  if (val==0) return 0;
  return 1;
}

void debounce_update() {  //update debounce vars
  bool reading;
  for (int i=0; i<bottom_button_count; i++) {
    reading = digitalRead(bottom_button_pins[i]);
    if (reading != dbc_last_button_states[i]) {
      dbc_last_button_times[i] = millis(); 
      dbc_last_button_states[i] = reading;
    }
  }
}

void frame_time_stabilizer() {
  int wait_time = desired_frame_time - (millis() - last_frame_start);
  if (wait_time > 0)
    delay(wait_time);
  last_frame_start = millis();
}

void draw_image(int pos_x, int pos_y, uint8_t (*data)[5], uint8_t len, color_t *colors, byte size_y, color_t background) {
  for(int c=size_y; c>0; c--) {
    for(int i=0; i<len; i++) {
      uint8_t color_id = pgm_read_byte(&data[i][4]);
      color_t draw_color = color_id != 255 ? pgm_read_word_near(&colors[color_id]) : background;
      int y = pgm_read_byte(&data[i][1]) - c;
      if (y >= 0)
        tft.drawHLine(pos_x + pgm_read_byte(&data[i][0]), pos_y + y, pgm_read_byte(&data[i][2]), draw_color);
    }
  }
}
