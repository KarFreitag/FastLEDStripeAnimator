//#include <ArduinoSTL.h>
#include <FastLED.h>

#include "ColorStripeAnimator.h"
#include "ColorStripeAnimatorPulse.h"

#include "ColorTransitionConst.h"
#include "ColorTransitionLinear.h"
#include "ColorTransitionHue.h"
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

  ColorAnchorPoint *anchor0 = new ColorAnchorPoint(25, CRGB::Red);
  
  ColorTransition *trans0 = new ColorTransitionHue(anchor0, anchor0, FORWARD_HUES);
  animator.addColorTransition( trans0);

  ColorAnimationLinear* anim0 = new ColorAnimationLinear(anchor0, ColorAnchorPoint(0, CRGB::Red), ColorAnchorPoint(99, CRGB::Red), 0, 5000);
  animator.addColorAnimation( anim0);

  Serial.println("setup() - done");
}

void loop()
{
  // Serial.println("loop()");

  animator.animateLeds( leds, millis());

  FastLED.show();
  // delay(5000);
}
