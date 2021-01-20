#pragma once

#include "ColorTransition.h"

class ColorTransitionLinear : public ColorTransition
{
public:
  ColorTransitionLinear(ColorAnchorPoint *startPoint, ColorAnchorPoint *otherPoint);
  void updateTransition(CRGB * leds, uint8_t numLeds, uint8_t start, uint8_t numSteps) override;

  ColorAnchorPoint *otherPoint;
};