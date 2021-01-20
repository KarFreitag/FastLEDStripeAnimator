#pragma once

#include "ColorAnchorPoint.h"

class ColorAnimation
{
public:
  ColorAnimation(ColorAnchorPoint *reference, ColorAnchorPoint start, ColorAnchorPoint target, unsigned long startTime, unsigned long endTime);
  virtual ~ColorAnimation(){};
  virtual void update(unsigned long runTime) = 0;

  ColorAnchorPoint *referencePoint;
  ColorAnchorPoint startPoint;
  ColorAnchorPoint targetPoint;
  unsigned long startTime;
  unsigned long endTime;
};