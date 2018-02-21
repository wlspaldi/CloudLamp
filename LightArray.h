#ifndef LIGHT_ARRAY
#define LIGHT_ARRAY

#include <FastLED.h>
#include "constants.h"

class LightArray
{
  public:
    LightArray(int tick, int width, int length, CRGB * color);
    void initializeAllSame(CRGB color);
    void initializeAllFromFunction(CRGB (*fx)(int x, int y));
    void attachUpdateFunction(int updateInterval, void (*f)(int));
    void update(void);
    void begin(void);
    void stop(void);
  private:
    void (*_f)(int);
    CRGB * _leds;
    int _tick;
    int _updateInterval;
    int _progress;
    int _width;
    int _length;
};

#endif
