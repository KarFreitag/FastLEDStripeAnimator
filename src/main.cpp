//#include <ArduinoSTL.h>
#include <FastLED.h>

#include "ColorStripeAnimator.h"
#include "ColorStripeAnimatorPulse.h"

#include "ColorTransitionConst.h"
#include "ColorTransitionLinear.h"
#include "ColorAnimationLinear.h"

const uint8_t NUM_LEDS = 100;
const uint8_t BRIGHTNESS = 30; //max. 255
CRGB *leds;

ColorStripeAnimator animator(NUM_LEDS);
ColorStripeAnimatorPulse pulseAnimator(NUM_LEDS);

void setup()
{
  delay(3000); // power-up safety delay

  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("setup()");

  // set chipset type, color order of LEDs and number of LEDs on stripe
  leds = new CRGB[NUM_LEDS];
  const int clockPin = 13;
  const int dataPin = 11;
  FastLED.addLeds<APA102, dataPin, clockPin, BGR>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);

  // set global brightness
  FastLED.setBrightness(BRIGHTNESS);
  //FastLED.setTemperature( Tungsten100W);
  //FastLED.setTemperature( OvercastSky);

  ColorAnchorPoint *anchor0 = new ColorAnchorPoint(0, CRGB::Red);
  ColorAnchorPoint *anchor1 = new ColorAnchorPoint(50, CRGB::Blue);
  ColorTransition *trans0 = new ColorTransitionLinear(anchor0, anchor1);
  ColorTransition *trans1 = new ColorTransitionLinear(anchor1, anchor0);

  ColorAnimationLinear* anim0 = new ColorAnimationLinear(anchor0, ColorAnchorPoint(0, CRGB::Red), ColorAnchorPoint(49, CRGB::Red), 0, 2000);
  ColorAnimationLinear* anim1 = new ColorAnimationLinear(anchor0, ColorAnchorPoint(50, CRGB::Red), ColorAnchorPoint(99, CRGB::Red), 2001, 4000);

  ColorAnimationLinear* anim2 = new ColorAnimationLinear(anchor1, ColorAnchorPoint(50, CRGB::Blue), ColorAnchorPoint(99, CRGB::Blue), 0, 2000);
  ColorAnimationLinear* anim3 = new ColorAnimationLinear(anchor1, ColorAnchorPoint(0, CRGB::Blue), ColorAnchorPoint(49, CRGB::Blue), 2001, 4000);

  animator.addColorTransition( trans0);
  animator.addColorTransition( trans1);
  animator.addColorAnimation( anim0);
  animator.addColorAnimation( anim1);
  animator.addColorAnimation( anim2);
  animator.addColorAnimation( anim3);

  Serial.println("setup() - done");
}

void loop()
{
  // Serial.println("loop()");

  animator.animateLeds( leds, millis());

  FastLED.show();
  // delay(5000);
}
