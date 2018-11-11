#include <ArduinoSTL.h>
#include <FastLED.h>

#include "ColorStripeAnimator.h"

const uint8_t NUM_LEDS = 100;
const uint8_t BRIGHTNESS = 64; //max. 255
CRGB * leds;

const ColorStripeAnimator animator( NUM_LEDS);

void setup() {
  // put your setup code here, to run once:

  // set chipset type, color order of LEDs and number of LEDs on stripe
  //FastLED.addLeds<led_type, led_color_order>(leds, num_leds);
  FastLED.addLeds<APA102, BGR>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );

  // set global brightness
  FastLED.setBrightness( BRIGHTNESS);

  // turn off all LEDs
  for (uint8_t i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Black;
  }

  FastLED.show();
}

void loop() {
  // put your main code here, to run repeatedly:
  animator.animateLeds( leds);
  FastLED.show();
}