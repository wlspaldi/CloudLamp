#include "CloudLamp.h"

void lightning(void);
void clearStrip(void);
void callback(void);

CRGB leds[NUM_LEDS];
LightArray cloud(TIMER_TICK_IN_MS, ROWS_OF_LEDS, LEDS_PER_ROW, leds);

void timerCallback(void) {
  cloud.update();
  Serial.print("Press any key: ");
}

CRGB blueSine(int x, int y, int progress) {
  CRGB newColor;
  float prog = 2*(float)(progress + (X_OFFSET * x))/ (float)INTERVAL;
  float sine = 64*sin(3.14 * prog) + 64;
  newColor.blue = (int)sine;
  return newColor;
}

CRGB gradientSine(int x, int y, int progress) {
  CRGB newColor;
  CRGB first = CRGB::Blue;
  CRGB second = CRGB::Orange;
  float prog = 2 * (float)(progress + (X_OFFSET * x)) / (float)INTERVAL;
  float sine = 0.5 * (sin(3.14 * prog) + 1);
  newColor.red = (first.red * sine + second.red * (1 - sine)) * 0.5;
  newColor.green = (first.green * sine + second.green * (1 - sine)) * 0.5;
  newColor.blue = (first.blue * sine + second.blue * (1 - sine)) * 0.5;
  return newColor;
}

void setup() {
  Serial.begin(115200);
  FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);

  MsTimer2::set(TIMER_TICK_IN_MS, timerCallback); // 5ms period
  MsTimer2::start();
  //clearStrip();
  cloud.initializeAllSame(CRGB::Blue);
  cloud.attachUpdateFunction(INTERVAL, gradientSine);
}

void loop() {
  // put your main code here, to run repeatedly:
  // clearStrip();
  FastLED.show();
  // lightning();
  // sunrise(10);
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
//
// void lightning(void) {
//   clearStrip();
//   assignRange(0, 10, 100, 100, 100);
//   FastLED.show();
//   delay(100);
//   clearStrip();
//   FastLED.show();
//   delay(100);
//   assignRange(35, 42, 100, 100, 100);
//   FastLED.show();
//   delay(100);
//   clearStrip();
//   FastLED.show();
//   delay(100);
//   assignRange(20, 36, 100, 100, 100);
//   FastLED.show();
//   delay(100);
//   clearStrip();
//   FastLED.show();
//   delay(100);
//   assignRange(40, 42, 100, 100, 100);
//   FastLED.show();
//   delay(100);
//   clearStrip();
//   FastLED.show();
//   delay(100);
//   assignRange(2, 28, 100, 100, 100);
//   FastLED.show();
//   delay(100);
//   clearStrip();
//   FastLED.show();
//   delay(100);
//   assignRange(38, 49, 100, 100, 100);
//   FastLED.show();
//   delay(100);
//   clearStrip();
//   FastLED.show();
//   delay(100);
//   assignRange(0, 49, 100, 100, 100);
//   FastLED.show();
//   delay(100);
//   clearStrip();
//   FastLED.show();
//   delay(100);
//   assignRange(0, 49, 100, 100, 100);
//   FastLED.show();
//   delay(100);
//   clearStrip();
//   FastLED.show();
//   delay(100);
//   assignRange(0, 49, 200, 200, 200);
//   FastLED.show();
//   fadeAllToBlack(10);
//   clearStrip();
//   FastLED.show();
// }
//
// void sunrise(int interval) {
//
// }


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
