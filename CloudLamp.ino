#include "CloudLamp.h"

void lightning(void);
void clearStrip(void);
void callback(void);

// int _updateInterval, tick, progress;
CRGB leds[NUM_LEDS];
// void (*_f)(int);
// CRGB * leds;
//                       0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49
//CRGB storm1[NUM_LEDS] = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0];
LightArray cloud(TIMER_TICK_IN_MS, 1, 13, leds);
int index;

void timerCallback(void) {
  clearStrip();
  leds[index] = CRGB::Yellow;
  index = (index + 1) % NUM_LEDS;
}

CRGB sineAssign(int x, int y) {
  sine
}

void setup() {
  // progress = 0;
  // tick = TIMER_TICK_IN_MS;
  // _updateInterval = TIMER_TICK_IN_MS * 5;
  // put your setup code here, to run once:
  //index = 0;
  //leds = cloud.getArray();
  FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);

  // MsTimer2::set(500, timerCallback); // 5ms period
  // MsTimer2::start();
  //clearStrip();
  cloud.initializeAllSame(CRGB::Orange);
}

void loop() {
  // put your main code here, to run repeatedly:
  // clearStrip();
  FastLED.show();
  // lightning();
  // sunrise(10);
   delay(5000);
   clearStrip();
}


void assignRange(int start_idx, int end_idx, int red, int green, int blue) {
  int i;
  if(start_idx < end_idx and end_idx < NUM_LEDS) {
    for(i = start_idx; i <= end_idx; i++) {
      leds[i].red = red;
      leds[i].green = green;
      leds[i].blue = blue;
    }
  }
}

void clearStrip(void) {
  for(int i = 0; i < NUM_LEDS; i++) {
    leds[i].red = 0;
    leds[i].green = 0;
    leds[i].blue = 0;
  }
}

void fadeAllToBlack(int interval) {
  for(int j = 255; j > 0; j--) {
    for(int i = 0; i < NUM_LEDS-1; i++) {
      if(leds[i].red > 0) {
        leds[i].red = j;
      }
      if(leds[i].green > 0) {
        leds[i].green = j;
      }
      if(leds[i].blue > 0) {
        leds[i].blue = j;
      }
    }
    FastLED.show();
    delay(interval);
  }
}

void lightning(void) {
  clearStrip();
  assignRange(0, 10, 100, 100, 100);
  FastLED.show();
  delay(100);
  clearStrip();
  FastLED.show();
  delay(100);
  assignRange(35, 42, 100, 100, 100);
  FastLED.show();
  delay(100);
  clearStrip();
  FastLED.show();
  delay(100);
  assignRange(20, 36, 100, 100, 100);
  FastLED.show();
  delay(100);
  clearStrip();
  FastLED.show();
  delay(100);
  assignRange(40, 42, 100, 100, 100);
  FastLED.show();
  delay(100);
  clearStrip();
  FastLED.show();
  delay(100);
  assignRange(2, 28, 100, 100, 100);
  FastLED.show();
  delay(100);
  clearStrip();
  FastLED.show();
  delay(100);
  assignRange(38, 49, 100, 100, 100);
  FastLED.show();
  delay(100);
  clearStrip();
  FastLED.show();
  delay(100);
  assignRange(0, 49, 100, 100, 100);
  FastLED.show();
  delay(100);
  clearStrip();
  FastLED.show();
  delay(100);
  assignRange(0, 49, 100, 100, 100);
  FastLED.show();
  delay(100);
  clearStrip();
  FastLED.show();
  delay(100);
  assignRange(0, 49, 200, 200, 200);
  FastLED.show();
  fadeAllToBlack(10);
  clearStrip();
  FastLED.show();
}

void sunrise(int interval) {

}


////////////////////////////////////////////////////////////
//
// void initializeAllSame(CRGB color) {
//   // for(int i = 0; i < ROWS_OF_LEDS; i++) {
//   //   for(int j = 0; i < NUM_LEDS / ROWS_OF_LEDS; j++) {
//   //     leds[i*(NUM_LEDS / ROWS_OF_LEDS) + j] = color;
//   //   }
//   // }
//   for(int i = 0; i < NUM_LEDS; i++) {
//     leds[i] = color;
//   }
// }
//
// void initializeAllFromFunction(CRGB (*fx)(int x, int y)) {
//   for(int i = 0; i < ROWS_OF_LEDS; i++) {
//     for(int j = 0; i < NUM_LEDS / ROWS_OF_LEDS; j++) {
//       leds[i*NUM_LEDS / ROWS_OF_LEDS + j] = fx(j, i);
//     }
//   }
// }
//
// void attachUpdateFunction(int updateInterval, void (*f)(int)) {
//   _updateInterval = updateInterval;
//   _f = f;
// }
//
// void update(void) {
//   progress = (progress + tick) % _updateInterval;
//   _f(progress);
// }
// // void LightArray::begin(void);
// // void LightArray::stop(void);
