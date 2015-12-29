#include <FastLED.h>
#define DATA_PIN 6
#define NUM_LEDS 50

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS); 

}

void loop() {
  for(short i=0; i++; i<NUM_LEDS){
    leds[i] = CRGB::Red;     
  }
  FastLED.show(); delay(30); 
  
  for(short i=0; i++; i<NUM_LEDS){
    leds[i] = CRGB::Blue;     
  }
  FastLED.show(); delay(30); 
}



