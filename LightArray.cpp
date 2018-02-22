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

void LightArray::attachUpdateFunction(int updateInterval, CRGB (*f)(int x, int y, int progress)) {
  _updateInterval = updateInterval;
  _f = f;
}
void LightArray::update(void) {
  _progress = (_progress + _tick) % _updateInterval;
  for(int i = 0; i < ROWS_OF_LEDS; i++) {
    for(int j = 0; j < LEDS_PER_ROW; j++) {
      // _leds[i*LEDS_PER_ROW+j] = _f(i, j, _progress);
      LightArray::setLight(j, i, _f(j, i, _progress));
    }
  }
}

void LightArray::setLight(int x, int y, CRGB color) {
  if(y % 2) {
    _leds[y*LEDS_PER_ROW + (LEDS_PER_ROW - 1 - x)] = color;
  } else {
    _leds[y*LEDS_PER_ROW + x] = color;
  }

}
// void LightArray::begin(void);
// void LightArray::stop(void);
