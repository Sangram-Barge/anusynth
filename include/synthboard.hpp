#ifndef synthboard_hpp
#define synthboard_hpp

#include <driver/i2s.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

#define I2S_BCLK  2
#define I2S_LRCLK 3
#define I2S_DIN   1

#ifndef SAMPLERATE 
#define SAMPLERATE 44100
#endif

enum WaveShape {W_SINE, W_SQUARE, W_SAW, W_TRIANGLE};

void configure_disp(Adafruit_SSD1306& display);
void update_disp(Adafruit_SSD1306& display, const char* buffer);
void configure_audio();

#endif