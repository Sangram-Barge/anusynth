#include <Arduino.h>
#include <synthboard.hpp>

#define AMPLITUDE 30000

Adafruit_SSD1306 display(128, 64, &Wire, -1);

float_t phase = 0.0;
float_t phase_incr = (2.0f * PI * 440.0) / SAMPLERATE;

void setup() {
  configure_audio();
  configure_disp();
}

void loop() {
  const int buffer_size = 256;
  int16_t samples[buffer_size * 2];

  for(int i = 0; i < buffer_size; i++) {
    int16_t sample = (int16_t)(AMPLITUDE * sin(phase));
    samples[i * 2]      = sample;
    samples[i * 2 + 1]  = sample;
    
    phase += phase_incr;
    if (phase >= 2.0f * PI) phase -= 2.0f * PI;
  }
  size_t bytes_written;
  i2s_write(I2S_NUM_0, samples, sizeof(samples), &bytes_written, portMAX_DELAY);
}