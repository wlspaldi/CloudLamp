#ifndef LIGHT_ARRAY_H
#define LIGHT_ARRAY_H

#include <FastLED.h>
#include "constants.h"
#include "Light.h"

class LightArray
{
  public:
    LightArray(int tick, int width, int length, CRGB * color);
    void initializeAllSame(CRGB color);
    void initializeAllFromFunction(CRGB (*fx)(int x, int y));
    void attachUpdateFunctiontoAll(int updateInterval, CRGB (*f)(int x, int y, int progress));
    void attachUpdateFunctiontoOne(int x, int y, int updateInterval, CRGB (*f)(int x, int y, int progress));
    void setLight(int x, int y, CRGB color);
    void update(void);
    void begin(void);
    void stop(void);
  private:
    CRGB (*_f)(int, int, int);
    CRGB * _leds;
    Light _lights[NUM_LEDS];
    int _tick;
    int _updateInterval;
    int _progress;
    int _width;
    int _length;
    int _numberOfLEDs;
};

#endif
