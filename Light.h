#ifndef LIGHT_H
#define LIGHT_H

#include <FastLED.h>
#include "constants.h"

class Light {
  public:
    Light(int x, int y);
    void attachLED(CRGB * LED);
    void update(void);
    int red;
    int blue;
    int green;
  private:
    CRGB (*_f)(int, int, int);
    int _x;
    int _y;
    int _progress;
    CRGB currentColor;
};

#endif
