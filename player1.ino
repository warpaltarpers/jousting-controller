#include <Bounce2.h>

#ifndef __MKL26Z64__
#error Make sure you have a Teensy LC board, then select the proper board type in tools: Tools > Board > Teensy LC
#endif

const int kButtonPin = 5;

const double kButtonInterval = 10;

Bounce btn = Bounce();

void setup() {
  btn.attach(kButtonPin, INPUT_PULLUP);
  btn.interval(kButtonInterval);
  delay(500);
}

void loop() {
  btn.update();
  if(btn.fell()){
    Keyboard.press(KEY_1);
  }
  if(btn.rose()){
    Keyboard.release(KEY_1);
  }
}
