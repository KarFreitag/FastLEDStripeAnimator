#pragma once

#include "ColorTransition.h"

class ColorTransitionConst : public ColorTransition
{
public:
  ColorTransitionConst(ColorAnchorPoint *startPoint);
  void updateTransition(CRGB * leds, uint8_t numLeds, uint8_t start, uint8_t numSteps) override;
};