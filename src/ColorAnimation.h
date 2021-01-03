
#ifndef COLORANIMATION_H
#define COLORANIMATION_H

#include "ColorAnchorPoint.h"

class ColorAnimation {
  public:
  ColorAnimation( ColorAnchorPoint * reference, ColorAnchorPoint target, unsigned long startTime, unsigned long endTime);
  virtual void update( unsigned long runTime) = 0;
  void reset();

  ColorAnchorPoint * referencePoint;
  ColorAnchorPoint startPoint;
  ColorAnchorPoint targetPoint;
  unsigned long startTime;
  unsigned long endTime;
  
  bool didStart;
  bool didEnd;
};

#endif
