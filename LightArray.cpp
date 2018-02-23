#include "LightArray.h"

LightArray::LightArray(int tick, int width, int length, CRGB * ledArray) {
  _tick = tick;
  _width = width;
  _length = length;
  _numberOfLEDs = width * length;
  _progress = 0;
  _leds = ledArray;
  for(int i = 0; i < ROWS_OF_LEDS; i++) {
    for(int j = 0; j < LEDS_PER_ROW; j++) {
      if(i % 2) {
        _lights[i*LEDS_PER_ROW + (LEDS_PER_ROW - j - 1)].initLight(tick, j, i, &_leds[i*LEDS_PER_ROW + (LEDS_PER_ROW - j - 1)]);
      } else {
        _lights[i*LEDS_PER_ROW + j].initLight(tick, j, i, &_leds[i*LEDS_PER_ROW + j]);
      }
    }
  }
}

void LightArray::initializeAllSame(CRGB color) {
  for(int i = 0; i < _numberOfLEDs; i++) {
    _leds[i] = color;
  }
}

void LightArray::initializeAllFromFunction(CRGB (*fx)(int x, int y)) {
  for(int i = 0; i < _width; i++) {
    for(int j = 0; i < _length; j++) {
      _leds[i*_length + j] = fx(j, i);
    }
  }
}

void LightArray::attachUpdateFunctiontoAll(int updateInterval, CRGB (*f)(int x, int y, int progress)) {
  for(int i = 0; i < _width * _length; i++) {
    _lights[i].attachUpdateFunction(updateInterval, f);
  }
}

void LightArray::attachUpdateFunctiontoOne(int x, int y, int updateInterval, CRGB (*fx)(int x, int y, int progress)) {
  if(y % 2) {
    _lights[y*LEDS_PER_ROW + (LEDS_PER_ROW - 1 - x)].attachUpdateFunction(updateInterval, fx);
  } else {
    _lights[y*LEDS_PER_ROW + x].attachUpdateFunction(updateInterval, fx);
  }
}

void LightArray::attachUpdateFunctiontoRange(int startingX, int endingX, int startingY, int endingY, int updateInterval, CRGB (*f)(int x, int y, int progress)) {
  for(int j = startingX; j <= endingX; j++) {
    for(int i = startingY; i <= endingY; i++) {
      if(i % 2) {
        _lights[i*LEDS_PER_ROW + (LEDS_PER_ROW - j - 1)].attachUpdateFunction(updateInterval, f);
      } else {
        _lights[i*LEDS_PER_ROW + j].attachUpdateFunction(updateInterval, f);
      }
    }
  }
}

void LightArray::startEvent(int startingX, int endingX, int startingY, int endingY, int duration, CRGB (*f)(int x, int y, int progress)) {
  for(int j = startingX; j <= endingX; j++) {
    for(int i = startingY; i <= endingY; i++) {
      if(i % 2) {
        _lights[i*LEDS_PER_ROW + (LEDS_PER_ROW - j - 1)].startEvent(duration, f);
      } else {
        _lights[i*LEDS_PER_ROW + j].startEvent(duration, f);
      }
    }
  }
}

void LightArray::update(void) {
  for(int i = 0; i < _numberOfLEDs; i++) {
    _lights[i].update();
  }
}

void LightArray::setLight(int x, int y, CRGB color) {
  if(y % 2) {
    _leds[y*LEDS_PER_ROW + (LEDS_PER_ROW - 1 - x)] = color;
  } else {
    _lights[y*LEDS_PER_ROW + x].set(color);
  }
}

void LightArray::setProgress(int x, int y, int progress) {
  if(y % 2) {
    _lights[y*LEDS_PER_ROW + (LEDS_PER_ROW - 1 - x)].setProgress(progress);
  } else {
    _lights[y*LEDS_PER_ROW + x].setProgress(progress);
  }
}

int LightArray::getProgress(int x, int y){
  if(y % 2) {
    return _lights[y*LEDS_PER_ROW + (LEDS_PER_ROW - 1 - x)].getProgress();
  } else {
    return _lights[y*LEDS_PER_ROW + x].getProgress();
  }
}
// void LightArray::begin(void);
// void LightArray::stop(void);
