#include "LightArray.h"

LightArray::LightArray(int tick, int width, int length, CRGB * ledArray) {
  _tick = tick;
  _width = width;
  _length = length;
  _progress = 0;
  _leds = ledArray;
}

void LightArray::initializeAllSame(CRGB color) {
  for(int i = 0; i < ROWS_OF_LEDS; i++) {
    for(int j = 0; j < LEDS_PER_ROW; j++) {
      _leds[i*LEDS_PER_ROW+j] = color;
    }
  }
}

void LightArray::initializeAllFromFunction(CRGB (*fx)(int x, int y)) {
  for(int i = 0; i < _width; i++) {
    for(int j = 0; i < _length; j++) {
      _leds[i*_length + j] = fx(j, i);
    }
  }
}

void LightArray::attachUpdateFunction(int updateInterval, void (*f)(int)) {
  _updateInterval = updateInterval;
  _f = f;
}
void LightArray::update(void) {
  _progress = (_progress + _tick) % _updateInterval;
  _f(_progress);
}
// void LightArray::begin(void);
// void LightArray::stop(void);
