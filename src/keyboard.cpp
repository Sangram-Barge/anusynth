#include <keyboard.hpp>

keyboard::keyboard(
    const std::vector<uint8_t> rows,
    const std::vector<uint8_t> cols)
    : row_pins(rows),
      col_pins(cols),
      r_size(row_pins.size()),
      c_size(col_pins.size()),
      keystate(r_size, std::vector<uint8_t>(c_size, 0)) {}

void keyboard::scanKeys() {
    for (int c = 0; c < c_size; c++) {
        digitalWrite(col_pins[c], HIGH);
        delayMicroseconds(2);
        for (int r = 0; r < r_size; r++) {
            keystate[r][c] = digitalRead(row_pins[r]);
        }
        digitalWrite(col_pins[c], LOW);
    }
}