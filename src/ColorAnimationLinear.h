
#ifndef COLORANIMATIONLINEAR_H
#define COLORANIMATIONLINEAR_H

#include "ColorAnimation.h"

class ColorAnimationLinear : public ColorAnimation {
  public:
  ColorAnimationLinear( ColorAnchorPoint * reference, ColorAnchorPoint target, unsigned long startTime, unsigned long endTime);
  void update( unsigned long runTime);
};

#endif
