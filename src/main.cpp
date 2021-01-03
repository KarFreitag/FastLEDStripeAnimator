//#include <ArduinoSTL.h>
#include <FastLED.h>

#include "ColorStripeAnimator.h"
#include "ColorStripeAnimatorPulse.h"

#include "ColorTransitionConst.h"
#include "ColorTransitionLinear.h"
#include "ColorAnimationLinear.h"

const uint8_t NUM_LEDS = 100;
const uint8_t BRIGHTNESS = 100; //max. 255
CRGB * leds;

const ColorStripeAnimatorPulse animator( NUM_LEDS);

void setup() {
  delay( 3000 ); // power-up safety delay

  // put your setup code here, to run once:
  Serial.begin( 9600 );
  Serial.println( "setup()");

  // set chipset type, color order of LEDs and number of LEDs on stripe
  leds = new CRGB[ NUM_LEDS];
  const int clockPin = 13;
   const int dataPin = 11;
  FastLED.addLeds<APA102, dataPin, clockPin, BGR>( leds, NUM_LEDS).setCorrection( TypicalLEDStrip );

  // set global brightness
  FastLED.setBrightness( BRIGHTNESS);
  //FastLED.setTemperature( Tungsten100W);
  //FastLED.setTemperature( OvercastSky);

  // turn off all LEDs
  for (uint8_t i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Black;
  }

  FastLED.show();

  //      animator.addColorTransition( &ColorTransitionConst( ColorAnchorPoint( 0, CRGB::Blue)));
  //      animator.addColorTransition( &ColorTransitionConst( ColorAnchorPoint( 25, CRGB::Red)));
  //      animator.addColorTransition( &ColorTransitionConst( ColorAnchorPoint( 50, CRGB::Green)));
  //      animator.addColorTransition( &ColorTransitionConst( ColorAnchorPoint( 75, CRGB::Yellow)));
  //
  //  animator.addColorTransition( &ColorTransitionLinear( ColorAnchorPoint( 25, CRGB::Blue)));
  //
  //  std::vector< ColorAnchorPoint *> anchors = animator.getAnchorPoints();
  //
  //  animator.addColorAnimation( new ColorAnimationLinear( anchors[0], ColorAnchorPoint( anchors[0]->position, CRGB::Black), 0000, 1000));
  //  animator.addColorAnimation( new ColorAnimationLinear( anchors[0], ColorAnchorPoint( anchors[0]->position, CRGB::Red), 1000, 2000));
  //  animator.addColorAnimation( new ColorAnimationLinear( anchors[0], ColorAnchorPoint( anchors[0]->position, CRGB::Black), 2000, 3000));
  //  animator.addColorAnimation( new ColorAnimationLinear( anchors[0], ColorAnchorPoint( anchors[0]->position, CRGB::Blue), 3000, 4000));

  Serial.println( "setup() - done");
}

void loop() {
  //Serial.println( "loop()");
  // put your main code here, to run repeatedly:
  animator.animateLeds( leds, millis());

  FastLED.show();
  //delay(500);
}
