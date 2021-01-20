#pragma once

#include <ArduinoSTL.h>
#include <set>
#include <FastLED.h>

#include "ColorAnchorPoint.h"
#include "ColorTransition.h"
#include "ColorAnimation.h"

struct ColorTransitionPtrCompare
{
  bool operator()(ColorTransition *lhs, ColorTransition *rhs)
  {
    return *lhs < *rhs;
  }
};

class ColorStripeAnimator
{
public:
  ColorStripeAnimator(uint8_t numLeds);
  ~ColorStripeAnimator();

  void animateLeds(CRGB *leds, unsigned long runtime);
  void addColorTransition(ColorTransition *transition);
  void addColorAnimation(ColorAnimation *animation);

protected:
  uint8_t numLeds;
  unsigned long animDuration = 1;
  unsigned long animTime;
  std::vector<ColorTransition *> transitions;
  std::vector<ColorAnimation *> animations;
};