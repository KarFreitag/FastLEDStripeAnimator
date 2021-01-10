#pragma once

#include "ColorTransition.h"

class ColorTransitionLinear : public ColorTransition
{
public:
  ColorTransitionLinear(ColorAnchorPoint startPoint);
  ColorTransition *makeCopy() override;
  void updateTransition(ColorAnchorPoint &otherPoint, CRGB *firstColorAnchorPoint, uint8_t numSteps) override;
};