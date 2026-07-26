#include <synthboard.hpp>
/*
  2 -> BCLK
  3 -> LRCLK
  1 -> DIN
*/
void configure_audio() {
  i2s_config_t i2s_cfg = {
    .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_TX),
    .sample_rate = SAMPLERATE,
    .bits_per_sample = I2S_BITS_PER_SAMPLE_16BIT,
    .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,
    .communication_format = I2S_COMM_FORMAT_STAND_I2S,
    .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1,
    .dma_buf_count = 8,
    .dma_buf_len = 256,
    .use_apll = false,
    .tx_desc_auto_clear = true
  };
  i2s_driver_install(I2S_NUM_0, &i2s_cfg, 0, NULL);

  i2s_pin_config_t i2s_pin_cfg = {
    .bck_io_num = I2S_BCLK,
    .ws_io_num = I2S_LRCLK,
    .data_out_num =I2S_DIN,
    .data_in_num = I2S_PIN_NO_CHANGE
  };
  i2s_set_pin(I2S_NUM_0, &i2s_pin_cfg);
}

void configure_disp(Adafruit_SSD1306& display) {
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.display();
}

void update_disp(Adafruit_SSD1306& display, const char* buffer) {
   display.clearDisplay();
    display.setCursor(0, 0);
    display.printf(buffer);
    display.display();
}