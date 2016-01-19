/*
Vixen Lights 3.x - Arduino Generic Serial for Addressable Pixels
 
Using this code is pretty straight forward, simply hookup your one wire (WS2811 or WS2812) 
data line to pin 6 of your Arduino and upload this code.  Make sure you have properly 
installed the FastLED library from http://fastled.io Once you are done, simply power your Pixel 
strips from an external power supply.  Next configure a Generic Serial Controller inside of 
Vixen Lights 3.x and add 3 x pixels for the number of channels.  Configure the Generic Serial 
Controller to use 115200, 8, none, and 1.  Then create your element and add "Multiple Items 
(1 x number of pixels).  Finally select your pixel elements and set them as RGB pixels before
patching them to the controler outputs.  You should now be ready to begin testing.
 
For a complete tutorial check out blog.huntgang.com

Created   November 8th, 2014
By        Richard Sloan - www.themindfactory.com
And       David Hunt - blog.huntgang.com
Version   1.4
*/
 
// You must download and install the library from http://fastled.io/ 
#include <FastLED.h>
 
// Sets the maximum number of LEDs that this code will handle to avoid running out of memory
#define NUM_LEDS 49

// Sets the pin which is used to connect to the LED pixel strip
#define DATA_PIN 6

#define OB_LED 13

CRGB leds[NUM_LEDS];

void setup() {
  // Let the FastLED library know how many pixels we will be addressing
  FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);

  // Define the speed of the serial port
  Serial.begin(115200);
  pinMode(OB_LED, OUTPUT);
} // end setup

void blinkLED(int nTimes, int wait) {
  digitalWrite(OB_LED, LOW);
  if(wait<=0) { wait = 0; }
  
  for(int i=0; i<nTimes; i++) {
    digitalWrite(OB_LED, HIGH); 
    delay(wait);
    digitalWrite(OB_LED, LOW);
    delay(wait); 
  }
    
} // end blinkLED

void loop() {
  blinkLED(10,50);
  // Set some counter / temporary storage variables
  int cnt;
  unsigned int num_leds;
 
  // Begin an endless loop to receive and process serial data
  for(;;) {
    // Set a counter to 0.  This couter keeps track of the pixel colors received.
    cnt = 0;
    
    // Loop through each of the pixels and read the values for each color
    num_leds = NUM_LEDS;
    do {
      while(!Serial.available()); leds[cnt].r = Serial.read();
      while(!Serial.available()); leds[cnt].g = Serial.read();
      while(!Serial.available()); leds[cnt].b = Serial.read();
      cnt++;
    } while(--num_leds);
    
    // Tell the FastLED Library it is time to update the strip of pixels
    FastLED.show();
    
    } // end internal for loop
} // end main loop




