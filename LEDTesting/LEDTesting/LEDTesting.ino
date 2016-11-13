#include <Adafruit_NeoPixel.h>
//#include <Adafruit_GFX.h>
//#include <gfxfont.h>
//#include <Adafruit_NeoMatrix.h>
//#include <gamma.h>

/*-------------------------------------------------------------------------

  --------------------------------------------------------------------*/

#define ONBOARD_LED 13

#define PIXEL_COUNT 3

#define NUM_COL 32
#define NUM_ROW 8

#define PIXEL_PIN 6
#define PIXEL_TYPE NEO_RGB + NEO_KHZ800

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)


  Adafruit_NeoPixel wholeStrip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);


//-------------------------------------------------------------------------------
void setup() {

   pinMode(ONBOARD_LED, OUTPUT);  // for the onboard LED, in case we need it for debugging
   
   wholeStrip.begin();    wholeStrip.show(); 

} // end setup



//--------------------------------------------------------------------------------
void loop() {
   
   blinkLED(3); delay(800);
   
   wholeStrip.setPixelColor(0, wholeStrip.Color(0,0,0));
   wholeStrip.setPixelColor(1, wholeStrip.Color(0,0,0));
   wholeStrip.setPixelColor(2, wholeStrip.Color(0,0,0));
   wholeStrip.show();
   delay(1000);
   
    wholeStrip.setPixelColor(0, wholeStrip.Color(0,255,0));
    wholeStrip.show();

    delay(1000);
} // end loop



//==========================================================================
// Fill the dots one after the other with a color
//==========================================================================
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i < wholeStrip.numPixels(); i++) {
    wholeStrip.setPixelColor(i, c);
    wholeStrip.show();
    delay(wait);
  }
} // end colorWipe

void lightsOff() {
  for(int i=0; i<PIXEL_COUNT; i++) {
    wholeStrip.setPixelColor(i,wholeStrip.Color(0,0,0));
  }
  wholeStrip.show();
} // end lightsOff;

//==========================================================================
// blink the onboard LED nTimes

void blinkLED(int nTimes) {
  digitalWrite(ONBOARD_LED, LOW);
  for(int i=0; i<nTimes; i++) {
    digitalWrite(ONBOARD_LED, HIGH); 
    delay(300);
    digitalWrite(ONBOARD_LED, LOW);
    delay(300); 
  }
    
} // end blinkLED

