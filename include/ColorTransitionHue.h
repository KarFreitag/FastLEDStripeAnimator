#pragma once

#include "ColorTransition.h"

class ColorTransitionHue : public ColorTransition
{
public:
  ColorTransitionHue(ColorAnchorPoint *startPoint, ColorAnchorPoint *otherPoint, TGradientDirectionCode direction = SHORTEST_HUES);
  void updateTransition(CRGB * leds, uint8_t numLeds, uint8_t start, uint8_t numSteps) override;

  ColorAnchorPoint *otherPoint;
  TGradientDirectionCode directionCode;
};