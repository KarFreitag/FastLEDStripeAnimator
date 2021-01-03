
#include "ColorAnimation.h"

ColorAnimation::ColorAnimation( ColorAnchorPoint * reference, ColorAnchorPoint target, unsigned long startTime, unsigned long endTime)
  : referencePoint( reference), startPoint( *reference), targetPoint( target), startTime( startTime), endTime( endTime) {
  reset();
}

void ColorAnimation::reset() {
  didStart = false;
  didEnd = false;
}

