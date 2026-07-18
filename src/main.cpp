#include <Arduino.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <vector>
#include <keyboard.hpp>

Adafruit_SSD1306 display(128, 64, &Wire, -1);
/*
r1 10 | r2 20 | r3 21 | r4 4
c1 5  | c2 6  | c3 7
*/
keyboard keyb(
    {10, 20, 21, 4},
    {5, 6, 7});


void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.setRotation(2); 
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  for (int i = 0; i < keyb.r_size; i++) {
    pinMode(keyb.row_pins[i], INPUT_PULLDOWN);
  }
  for (int i = 0; i < keyb.c_size; i++) {
    pinMode(keyb.col_pins[i], OUTPUT);
    digitalWrite(keyb.col_pins[i], LOW);
  }
}

void loop() {
  display.clearDisplay();
  display.setCursor(0, 0);
  keyb.scanKeys();
  for (int r = 0; r < keyb.r_size; r++) {
    for (int c = 0; c < keyb.c_size; c++) {
      display.printf("%d | ",keyb.keystate[r][c]);
    }
    display.println();
  }
  display.display();

}