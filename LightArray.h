#ifndef LIGHT_ARRAY_H
#define LIGHT_ARRAY_H

#include <FastLED.h>
#include "constants.h"

class LightArray
{
  public:
    LightArray(int tick, int width, int length, CRGB * color);
    void initializeAllSame(CRGB color);
    void initializeAllFromFunction(CRGB (*fx)(int x, int y));
    void attachUpdateFunction(int updateInterval, CRGB (*f)(int x, int y, int progress));
    void setLight(int x, int y, CRGB color);
    void update(void);
    void begin(void);
    void stop(void);
  private:
    CRGB (*_f)(int, int, int);
    CRGB * _leds;
    int _tick;
    int _updateInterval;
    int _progress;
    int _width;
    int _length;
};

#endif
