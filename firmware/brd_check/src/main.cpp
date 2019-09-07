#include <Arduino.h>

const int GREEN_LED = 33;
const int USER_SW = 32;

void setup() {
  // Setup GPIO pin mode
  pinMode(USER_SW, INPUT_PULLUP);
  pinMode(GREEN_LED, OUTPUT);
}

void loop() {
  digitalWrite(GREEN_LED, digitalRead(USER_SW));
  delay(10);
}
