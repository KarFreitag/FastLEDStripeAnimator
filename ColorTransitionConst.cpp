
#include "ColorTransitionConst.h"

ColorTransitionConst::ColorTransitionConst( ColorAnchorPoint startPoint) : ColorTransition( startPoint) {}

ColorTransition * ColorTransitionConst::makeCopy() {
  return new ColorTransitionConst( startPoint);
}

void ColorTransitionConst::updateTransition( ColorAnchorPoint& otherPoint, CRGB * firstColorAnchorPoint, uint8_t numSteps) {
  for (uint8_t i=0; i<numSteps; ++i) {
    firstColorAnchorPoint[ i] = startPoint.color;
  }
}

