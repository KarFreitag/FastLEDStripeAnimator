#pragma once

#include "ColorTransition.h"

class ColorTransitionConst : public ColorTransition
{
public:
  ColorTransitionConst(ColorAnchorPoint startPoint);
  ColorTransition *makeCopy() override;
  void updateTransition(ColorAnchorPoint &otherPoint, CRGB *firstColorAnchorPoint, uint8_t numSteps) override;
};