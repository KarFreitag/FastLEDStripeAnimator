#pragma once

#include <ArduinoSTL.h>
#include <FastLED.h>

#include "ColorStripeAnimator.h"

class ColorStripeAnimatorPulse : public ColorStripeAnimator
{
public:
  ColorStripeAnimatorPulse(uint8_t numLeds);
  ~ColorStripeAnimatorPulse();

  void setPulseColor(CRGB color);
  void setPulseDuration(unsigned long milliSeconds);

protected:
  CRGB pulseColor = CRGB::White;
  unsigned long pulseDuration = 2000;

  void setupAnimations();
  void reset();
};