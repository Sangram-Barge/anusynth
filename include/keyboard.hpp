#ifndef keyboard_h
#define keyboard_h

#include <Arduino.h>
#include <vector>

class keyboard {
private:
public:
    const std::vector<uint8_t> row_pins, col_pins;
    const uint8_t r_size, c_size;
    std::vector<std::vector<uint8_t>> keystate;
    void scanKeys();
    keyboard(const std::vector<uint8_t> rows, const std::vector<uint8_t> cols);
};

#endif