#include "Light.h"

void Light::initLight(int tick, int x, int y, CRGB * led) {
  _x = x;
  _y = y;
  _tick = tick;
  _progress = 0;
  _currentColor = led;
}

void Light::setTick(int tick) {
  _tick = tick;
}

void Light::initializeProgress(int progress) {
  _progress = progress;
}

void Light::attachLED(CRGB * LED) {
  _currentColor = LED;
}

void Light::attachUpdateFunction(int updateInterval, CRGB (*f)(int x, int y, int progress)) {
  _updateInterval = updateInterval;
  _f = f;
}

void Light::update(void) {
  _progress = (_progress + _tick) % _updateInterval;
  *_currentColor = _f(_x, _y, _progress);
}

void Light::set(CRGB color) {
  *_currentColor = color;
}
