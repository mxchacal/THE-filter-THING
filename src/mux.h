#ifndef MUX_H
#define MUX_H
#include <Arduino.h>

class Mux {
public:
  Mux(int x, int y, int z) { _x = x; _y = y; _z = z; }

  void init() {
    pinMode(_x, OUTPUT);
    pinMode(_y, OUTPUT);
    pinMode(_z, OUTPUT);
  }

  void setPin(int pin) {
    digitalWrite(_x, bitRead(pin, 0));
    digitalWrite(_y, bitRead(pin, 1));
    digitalWrite(_z, bitRead(pin, 2));
  }

private:
  int _x, _y, _z;
};

#endif
