#ifndef LIGHT_H
#define LIGHT_H

#include <FastLED.h>
#include "constants.h"

class Light {
  public:
    //Light(int tick, int x, int y, CRGB * led);
    void initLight(int tick, int x, int y, CRGB * led);
    void setTick(int tick);
    void initializeProgress(int progress);
    void attachLED(CRGB * LED);
    void attachUpdateFunction(int updateInterval, CRGB (*f)(int x, int y, int progress));
    void startEvent(int duration, CRGB (*f)(int x, int y, int progress));
    void update(void);
    void set(CRGB color);
    int getProgress(void);
    void setProgress(int);
    int red;
    int blue;
    int green;
  private:
    CRGB (*_f)(int, int, int);
    CRGB (*_event)(int, int, int);
    int _x;
    int _y;
    int _tick;
    int _progress;
    int _updateInterval;
    CRGB * _currentColor;
    bool _eventInProgress;
    int _eventProgress;
    int _eventDuration;
};

#endif
