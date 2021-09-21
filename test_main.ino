#include <FastLED.h>

#define NUM 597
#define LED_PIN 2
#define DIAL 25

CRGB LEDs[NUM] = {0};

uint8_t hue = 0;
uint8_t mode = 1;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  FastLED.addLeds<WS2812, LED_PIN, GRB>(LEDs, NUM);
  FastLED.setBrightness(100);
  FastLED.clear();
  FastLED.setMaxPowerInMilliWatts(5000);
}

void loop() {
  switch(mode) {
    case 0:
      for (int i = 0; i < NUM; i++) {
        LEDs[i] = CHSV(hue + i, 255, 255);
      }
    
      EVERY_N_MILLIS(15) {
        hue++;
        FastLED.show();
      }
    case 1:
      EVERY_N_MILLIS(15) {
        LEDs[random(NUM)] = CHSV(random(185, 250), random(80, 100), 255);
        FastLED.show();
      }
      EVERY_N_MILLIS(50) {
        for(int i = 0; i < NUM; i++) {
          fadeToBlackBy(LEDs, NUM, 10);
        }
        FastLED.show();
      }
  }
  
}
