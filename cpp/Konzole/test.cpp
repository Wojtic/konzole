#include "define.h"

#define sample_count 1

// 4500 bytes MEM

namespace test {
  int test_stage = -1;
  int last_test_stage = -1;
  int test_stage_count = 10;
  long test_stage_time = -1;
  long test_stage_step = 0;

  const int test_stage2_x[] = {55, 160, 55, 85, 25, 55, 260, 260, 235, 285};
  const int test_stage2_y[] = {120, 155, 180, 150, 150, 150, 120, 170, 145, 145};
  
  int reading = 0;
  char reading_text[4];
  
  void setup() {
    test_stage = 0;
  }

  void basic_test_stage() {
    tft.fillScreen(color_black);
    tft.setCursor(55, 20);
    tft.setTextColor(color_white);
    tft.setTextSize(3);
    tft.println("Test konzole");
    test_stage_time == -1;
    test_stage_step = 0;
  }

  void display_test_stage() {
    switch(test_stage) {
      case 0:
        tft.fillScreen(color_black);
        tft.setCursor(55, 20);
        tft.setTextColor(color_white);
        tft.setTextSize(3);
        tft.println("Test konzole");
        test_stage_time = millis();
        break;
      case 1:
        tft.fillScreen(color_black);
        tft.setCursor(55, 20);
        tft.setTextColor(color_white);
        tft.setTextSize(3);
        tft.println("Test konzole");
        
        tft.setCursor(50, 60);
        tft.setTextSize(2);
        tft.println("dolni rada tlacitek");
        test_stage_time = -1;
        break;
      case 2:
        basic_test_stage();
        tft.setTextSize(1);
        tft.setCursor(250, 220);
        tft.print("pokracovat");
        tft.setCursor(190, 220);
        tft.print("osy");
        tft.setTextSize(2);
        tft.setCursor(70, 60);
        tft.print("horni tlacitka");
        for(int i=0; i<10; i++) {
          tft.fillCircle(test_stage2_x[i], test_stage2_y[i], 15, color_gray);
          tft.fillCircle(test_stage2_x[i], test_stage2_y[i], 12, color_black);
        }
        break;
      case 3:
        basic_test_stage();
        tft.setCursor(270, 220);
        tft.setTextSize(1);
        tft.print("zpet");
        tft.setTextSize(2);
        tft.setCursor(150, 60);
        tft.print("osy");
        delay(750);
        break;
      case 4:
        basic_test_stage();
        tft.setTextSize(1);
        tft.setCursor(250, 220);
        tft.print("vynulovat");
        tft.setCursor(190, 220);
        tft.print("zmenit");
        tft.setTextSize(2);
        tft.setCursor(120, 60);
        tft.print("bzucak");
        test_stage_step = 25;
        delay(750);
        tone(piezo_pin, 0);
        noTone(piezo_pin);
        break;
    }
  }

  void loop_test_stage() {
    switch(test_stage) {
      case 0:
        if (millis() - test_stage_time > 1000 && test_stage_step == 0) {
          test_stage_step = 1;
          tft.fillRect(50, 140, 40, 40, color_red);
        } else if (millis() - test_stage_time > 2000 && test_stage_step == 1) {
          test_stage_step = 2;
          tft.fillRect(140, 140, 40, 40, color_lime);
        } else if (millis() - test_stage_time > 3000 && test_stage_step == 2) {
          test_stage_step = 3;
          tft.fillRect(230, 140, 40, 40, color_blue);
        } else if(millis() - test_stage_time > 3000 && test_stage_step == 3) {
          test_stage++;
        }
        break;
      case 1:
        for(int i=0; i<bottom_button_count; i++) {
          if (!digitalRead(bottom_button_pins[i]) && button_debounced(i)) {
            if (!(test_stage_step & (1<<(i*2)))) tft.fillCircle(55+70*i, 200, 15, color_gray);
            if (!(test_stage_step & (1<<(1+i*2)))) tft.fillCircle(55+70*i, 200, 12, color_white);
            test_stage_step |= 0b11<<(i*2);
          } else if(digitalRead(bottom_button_pins[i]) && button_debounced(i) && test_stage_step & (1<<(1+i*2))) {
            tft.fillCircle(55+70*i, 200, 12, color_black);
            test_stage_step &= ~(1<<(1+i*2));
          }
        }
        if (test_stage_step == 0b1010101 && test_stage_time == -1)  test_stage_time=millis();
        if (test_stage_time != -1 && millis() - test_stage_time > 2500) test_stage++;
        break;
      case 2:
        for(int i=0; i<10; i++) {
          if (Input::is_pressed(i) && !(test_stage_step & (1<<i))) {
            tft.fillCircle(test_stage2_x[i], test_stage2_y[i], 12, color_white);
            test_stage_step |= 1<<i;
          } else if (!Input::is_pressed(i) && test_stage_step & (1<<i)){
            test_stage_step &= ~(1<<i);
            tft.fillCircle(test_stage2_x[i], test_stage2_y[i], 12, color_black);
          }
        }
        if (!digitalRead(button_bottom3_pin) && button_debounced(2)) test_stage=3;
        if (!digitalRead(button_bottom4_pin) && button_debounced(3)) test_stage=4;
        break;
        break;
      case 3:
        reading = 0;
        for (int i=0; i<sample_count; i++ ) {
          reading += analogRead(axis_left1);
        }
        itoa(reading/sample_count,reading_text,10);
        tft.setCursor(0, 100);
        tft.setTextColor(color_white);
        tft.setTextSize(1);
        tft.print("Osa1: ");
        tft.print(reading_text);
        
        reading = 0;
        for (int i=0; i<sample_count; i++ ) {
          reading += analogRead(axis_left2);
        }
        itoa(reading/sample_count,reading_text,10);
        tft.setCursor(0, 120);
        tft.print("Osa2: ");
        tft.print(reading_text);
        
        reading = 0;
        for (int i=0; i<sample_count; i++ ) {
          reading += analogRead(axis_left3);
        }
        itoa(reading/sample_count,reading_text,10);
        tft.setCursor(0, 140);
        tft.print("Osa3: ");
        tft.print(reading_text);
        
        reading = 0;
        for (int i=0; i<sample_count; i++ ) {
          reading += analogRead(axis_right1);
        }
        itoa(reading/sample_count,reading_text,10);
        tft.setCursor(0, 160);
        tft.print("Osa4: ");
        tft.print(reading_text);
        
        reading = 0;
        for (int i=0; i<sample_count; i++ ) {
          reading += analogRead(axis_right2);
        }
        itoa(reading/sample_count,reading_text,10);
        tft.setCursor(0, 180);
        tft.print("Osa5: ");
        tft.print(reading_text);
        
        reading = 0;
        for (int i=0; i<sample_count; i++ ) {
          reading += analogRead(axis_battery);
        }
        itoa(reading/sample_count,reading_text,10);
        tft.setCursor(0, 200);
        tft.print("Osa6: ");
        tft.print(reading_text);
        
        delay(100);
        tft.fillRect(0, 100, 60, 120, color_black);
        if (!digitalRead(button_bottom4_pin) && button_debounced(3)) test_stage=2;
        break;
      case 4:
        if (!digitalRead(button_bottom3_pin) && button_debounced(2)) {
          test_stage_step *= 2;
          delay(500);
          tone(piezo_pin, test_stage_step);
        }
        if (!digitalRead(button_bottom4_pin) && button_debounced(3)) {
          test_stage_step = 25;
          noTone(piezo_pin);
        }
        break;
    }
  }

  void loop() {
    if (last_test_stage != test_stage) {
      last_test_stage = test_stage;
      test_stage_step = 0;
      display_test_stage();
    }
    loop_test_stage();
  }
}
