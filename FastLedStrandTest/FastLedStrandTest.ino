#include <FastLED.h>

#define DATA_PIN 6
#define NUM_LEDS 2

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2811_400, DATA_PIN>(leds, NUM_LEDS); 
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(13, HIGH);
  leds[1].setRGB(0,0,255); FastLED.show(); delay(1000);
  leds[1].setRGB(0,0,0); FastLED.show(); delay(1000);

  
/*  for(short i=0; i++; i<NUM_LEDS){
    leds[i] = CRGB::Red;     
  }
  FastLED.show(); delay(1000); 
 
  digitalWrite(13, LOW);
  for(short i=0; i++; i<NUM_LEDS){
    leds[i] = CRGB::Blue;     
  }
  FastLED.show(); delay(1000); 

  digitalWrite(13, HIGH);
  for(short i=0; i++; i<NUM_LEDS){
    leds[i] = CRGB::Black;     
  }
  FastLED.show(); delay(100); 
*/
  digitalWrite(13, LOW); delay(500);
  //digitalWrite(13, HIGH); delay(500);
  //digitalWrite(13, LOW);
}



