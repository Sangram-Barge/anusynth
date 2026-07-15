#include <Arduino.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

Adafruit_SSD1306 display(128, 64, &Wire, -1);

/*
r1 10 | r2 20 | yellow r3 7 | r4 4
c1 5  | c2 6  | c3 7
*/

uint8_t rows[]= {10, 20, 21, 4};
uint8_t cols[]= {5, 6, 7};

uint8_t rows_len = 4;
uint8_t cols_len = 3;

uint8_t button_mat[4][3];

void scanKeys();

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.setRotation(2); // NOT 90

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("booting...");
  display.display();
  for (int i = 0; i < rows_len; i++) {
    pinMode(rows[i], INPUT_PULLDOWN);
  }
  for (int i = 0; i < cols_len; i++) {
    pinMode(cols[i], OUTPUT);
    digitalWrite(cols[i], LOW);
  }
  display.clearDisplay();
  display.println("done");
  display.display();
  delay(1000);
}


void loop() {
  display.clearDisplay();
  display.setCursor(0, 0);
  scanKeys();
  for (int r = 0; r < rows_len; r++) {
    for (int c = 0; c < cols_len; c++) {
      display.printf("%d | ",button_mat[r][c]);
    }
    display.println();
  }
  for (int r = 0; r < rows_len; r++)
    for (int c = 0; c < cols_len; c++)
      button_mat[r][c] = 0;
  display.display();
}

void scanKeys() {
  for (int c = 0; c < cols_len; c++) {
    digitalWrite(cols[c], HIGH);
    delayMicroseconds(2);
    for (int r = 0; r < rows_len; r++) {
      button_mat[r][c] = digitalRead(rows[r]);
    digitalWrite(cols[c], LOW);
  }
}
