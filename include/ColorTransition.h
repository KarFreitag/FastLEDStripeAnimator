#pragma once

#include <FastLED.h>

#include "ColorAnchorPoint.h"

class ColorTransition
{
public:
  ColorTransition(ColorAnchorPoint startPoint);
  virtual ~ColorTransition(){};
  virtual ColorTransition *makeCopy() = 0;
  virtual void updateTransition(ColorAnchorPoint &otherPoint, CRGB *firstColorAnchorPoint, uint8_t numSteps) = 0;

  ColorAnchorPoint startPoint;
};