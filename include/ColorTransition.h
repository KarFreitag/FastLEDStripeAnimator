#pragma once

#include <FastLED.h>

#include "ColorAnchorPoint.h"

class ColorTransition
{
public:
  ColorTransition(ColorAnchorPoint *startPoint);
  virtual ~ColorTransition(){};
  
  virtual void updateTransition(CRGB * leds, uint8_t numLeds, uint8_t start, uint8_t numSteps) = 0;
  bool operator<(const ColorTransition &rhs) const { return startPoint->position < rhs.startPoint->position; }
  
  ColorAnchorPoint *startPoint;
};