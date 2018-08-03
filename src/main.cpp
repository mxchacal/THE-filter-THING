#include <Arduino.h>
#include "mux.h"

//TODO: get the point for the rez thing..

void setMode(int _mode);
void setRezMode(int _mode);

Mux poleMixer(1, 2, 3);
Mux rezMixer(4, 5, 6);

const char filter_mode[15] = {1, 9, 0, 8, 2, 3, 4, 10, 13, 6, 7, 11, 12, 14, 15};
int  activeMode, modeCV;
int  potPin, cvPin;

void setup() {
  Serial.begin(96000);

  poleMixer.init();
  rezMixer.init();

  potPin = 0;
  cvPin = 1;
  modeCV = 0;
  activeMode = 0;

  pinMode(potPin, INPUT);
  pinMode(cvPin, INPUT);

  setMode(activeMode);
}

void loop() {
  modeCV =  analogRead(potPin) + analogRead(cvPin); //read cv + pot
  activeMode = map(modeCV, 0, 2046, 0, 15);
  setMode(filter_mode[activeMode]);
  //+4 RGB led display
}

void setMode(int _mode) {
  poleMixer.setPin(_mode);
  rezMixer.setPin(_mode >> 3);
}
