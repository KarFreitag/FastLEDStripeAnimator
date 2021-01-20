#pragma once

#include "ColorAnimation.h"

class ColorAnimationLinear : public ColorAnimation
{
public:
  ColorAnimationLinear(ColorAnchorPoint *reference, ColorAnchorPoint start, ColorAnchorPoint target, unsigned long startTime, unsigned long endTime);
  void update(unsigned long runTime);
};