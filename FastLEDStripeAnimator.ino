#include <ArduinoSTL.h>
#include <FastLED.h>

#include "ColorStripeAnimator.h"
#include "ColorTransitionConst.h"
#include "ColorTransitionLinear.h"

const uint8_t NUM_LEDS = 100;
const uint8_t BRIGHTNESS = 64; //max. 255
CRGB * leds;

const ColorStripeAnimator animator( NUM_LEDS);

void setup() {
  delay( 3000 ); // power-up safety delay

  // put your setup code here, to run once:
  Serial.begin( 9600 );
  Serial.println( "setup()");

  // set chipset type, color order of LEDs and number of LEDs on stripe
  //FastLED.addLeds<led_type, led_color_order>(leds, num_leds);
  leds = new CRGB[ NUM_LEDS];
  FastLED.addLeds<APA102, BGR>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );

  // set global brightness
  FastLED.setBrightness( BRIGHTNESS);
  //FastLED.setTemperature( Tungsten100W);
  //FastLED.setTemperature( OvercastSky);

  // turn off all LEDs
  for (uint8_t i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Black;
  }

  FastLED.show();

  //  animator.addColorTransition( &ColorTransitionConst( ColorAnchorPoint( 0, CRGB::Blue)));
  //  animator.addColorTransition( &ColorTransitionConst( ColorAnchorPoint( 25, CRGB::Red)));
  //  animator.addColorTransition( &ColorTransitionConst( ColorAnchorPoint( 50, CRGB::Green)));
  //  animator.addColorTransition( &ColorTransitionConst( ColorAnchorPoint( 75, CRGB::Yellow)));

  //  animator.addColorTransition( &ColorTransitionLinear( ColorAnchorPoint( 0, CRGB(50,0,0))));
  //  animator.addColorTransition( &ColorTransitionLinear( ColorAnchorPoint( 16, CRGB::Black)));
  //  animator.addColorTransition( &ColorTransitionLinear( ColorAnchorPoint( 33, CRGB(0,50,0))));
  //  animator.addColorTransition( &ColorTransitionLinear( ColorAnchorPoint( 49, CRGB::Black)));
  //  animator.addColorTransition( &ColorTransitionLinear( ColorAnchorPoint( 66, CRGB(0,0,50))));
  //  animator.addColorTransition( &ColorTransitionLinear( ColorAnchorPoint( 83, CRGB::Black)));

  animator.addColorTransition( &ColorTransitionLinear( ColorAnchorPoint( 50, CRGB::Red)));

  Serial.println( "setup() - done");
}

void loop() {
  Serial.println( "loop()");
  // put your main code here, to run repeatedly:
  animator.animateLeds( leds);
  FastLED.show();
  delay( 10000);
}
